#include <iostream>

#include "NodeDTOTest.h"
#include "EdgeDTOTest.h"
#include "GraphDTOTest.h"

#include "StreamInputGraphManagerTest.h"
#include "StreamOutputGraphManagerTest.h"

#include "NodeModelTest.h"
#include "EdgeModelTest.h"
#include "AdjacencyListTest.h"
#include "AdjacencyListFactoryTest.h"
#include "SubGraphModelTest.h"

#include "SubGraphToGraphAdapterTest.h"

#include "TreeModelTest.h"
#include "PathModelTest.h"

#include "GraphComparerTest.h"
#include "SubGraphComparerTest.h"

#include "KruskalAlgorithmTest.h"
#include "PrimAlgorithmTest.h"
#include "BoruvkaAlgorithmTest.h"

#include "DijkstraAlgorithmTest.h"
#include "BellmanFordAlgorithmTest.h"

int main( void )
{
	Minotaur::CNodeDtoTest dtoTestNode = Minotaur::CNodeDtoTest();
	Minotaur::CEdgeDtoTest dtoTestEdge = Minotaur::CEdgeDtoTest();
	Minotaur::CGraphDtoTest dtoTestGraph = Minotaur::CGraphDtoTest();
	
	Minotaur::CStreamInputGraphManagerTest inputGraphManagerTest = Minotaur::CStreamInputGraphManagerTest();
	Minotaur::CStreamOutputGraphManagerTest outputGraphManagerTest = Minotaur::CStreamOutputGraphManagerTest();
	
	Minotaur::CNodeModelTest nodeModelTest = Minotaur::CNodeModelTest();
	Minotaur::CEdgeModelTest edgeModelTest = Minotaur::CEdgeModelTest();
	Minotaur::CAdjacencyListTest adjacencyListTest = Minotaur::CAdjacencyListTest();
	Minotaur::CAdjacencyListFactoryTest adjacencyListFactoryTest = Minotaur::CAdjacencyListFactoryTest();
	Minotaur::CSubGraphModelTest subGraphTest = Minotaur::CSubGraphModelTest();
	
	Minotaur::CSubGraphToGraphAdapterTest adapterTest = Minotaur::CSubGraphToGraphAdapterTest();
	
	Minotaur::CTreeModelTest treeModelTest = Minotaur::CTreeModelTest();
	Minotaur::CPathModelTest pathModelTest = Minotaur::CPathModelTest();

	Minotaur::CGraphComparerTest graphComparerTest = Minotaur::CGraphComparerTest();
	Minotaur::CSubGraphComparerTest subGraphComparerTest = Minotaur::CSubGraphComparerTest();

	Minotaur::CKruskalAlgorithmTest kruskalAlgorithmTest = Minotaur::CKruskalAlgorithmTest();
	Minotaur::CPrimAlgorithmTest primAlgorithmTest = Minotaur::CPrimAlgorithmTest();
	Minotaur::CBoruvkaAlgorithmTest boruvkaAlgorithmTest = Minotaur::CBoruvkaAlgorithmTest();

	Minotaur::CDijkstraAlgorithmTest dijkstraAlgorithmTest = Minotaur::CDijkstraAlgorithmTest();
	Minotaur::CBellmanFordAlgorithmTest bellmanFordAlgorithmTest = Minotaur::CBellmanFordAlgorithmTest();
	
	return 0;
}
