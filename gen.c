#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define MIN_PER_RANK 35 /* Nodes/Rank: How 'fat' the DAG should be.  */
#define MAX_PER_RANK 40
#define MIN_RANKS 30    /* Ranks: How 'tall' the DAG should be.  */
#define MAX_RANKS 50
#define PERCENT 70     /* Chance of having an Edge.  */

FILE* g_randomNumbersFile;
FILE* g_graphFile;

void WriteHeader( void )
{
	fprintf(g_graphFile, "%s", "graph\n{\n");
	fprintf(g_graphFile, "%s", "\tgraph[center = true, margin = 0.2, nodesep = 0.1, ranksep = 3.3];\n");
	fprintf(g_graphFile, "%s", "\tnode[shape = circle, fontsize = 10];\n");
	fprintf(g_graphFile, "%s", "\tedge[arrowsize = 2.6, fontsize = 10];\n\n");
}

void WriteEdges( int nodeIndex, int k, int nodes )
{
	char g[10];
	double edgeWeight = 0.0;

	fscanf(g_randomNumbersFile, "%s", g);;
	edgeWeight = atof(g);

	fprintf(g_graphFile, "\t%d", nodeIndex);
	fprintf(g_graphFile, "%s", " -- ");
	fprintf(g_graphFile, "%d", k + nodes);
	fprintf(g_graphFile, "%s", " [label = \"");
	fprintf(g_graphFile, "%.1f", edgeWeight);
	fprintf(g_graphFile, "%s\n", "\"];");
}

void WriteNodes( int nodesNumber )
{
	int nodeIndex = 0;
	
	fprintf(g_graphFile, "%s\n", "");
        
	for ( nodeIndex = 0; nodeIndex < nodesNumber; ++nodeIndex )
        {
                fprintf(g_graphFile, "\t%d", nodeIndex);
                fprintf(g_graphFile, "%s", " [pos = \"");
                fprintf(g_graphFile, "%d", nodeIndex);
                fprintf(g_graphFile, "%s", ", ");
                fprintf(g_graphFile, "%d", nodeIndex);
                fprintf(g_graphFile, "%s\n", "\"];");
        }
	
	fprintf (g_graphFile, "%s\n", "}");
}

int main ( void )
{
	int edgeIndex = 0;
	int nodeIndex = 0;
	int k = 0;
	int nodes = 0;
	int edgesNumber = 0;
	int newNodes = 0;
	int edgesCount = 0;

	g_randomNumbersFile = fopen("randomNumbers","r");
	g_graphFile = fopen("graphModel.dot","w");

	srand (time (NULL));
	edgesNumber = MIN_RANKS + (rand () % (MAX_RANKS - MIN_RANKS));

	WriteHeader();

	for ( edgeIndex = 0; edgeIndex < edgesNumber; ++edgeIndex )
	{
		/* New nodes of 'higher' rank than all nodes generated till now.  */
		newNodes = MIN_PER_RANK + (rand () % (MAX_PER_RANK - MIN_PER_RANK));

		/* Edges from old nodes ('nodes') to new ones ('new_nodes').  */
		for ( nodeIndex = 0; nodeIndex < nodes; ++nodeIndex )
		{
			for ( k = 0; k < newNodes; ++k )
			{
				if ( (rand () % 100) < PERCENT )
				{
					++edgesCount;
					WriteEdges(nodeIndex, k, nodes);
				}
			}
		}
		nodes += newNodes; /* Accumulate into old node set.  */
	}

	WriteNodes(nodes);

	printf("Nodes: %d\n", nodes);
	printf("Edges: %d\n\n", edgesCount);

	fclose(g_randomNumbersFile);
	fclose(g_graphFile);

	return 0;
}
