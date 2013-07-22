#include "FileInputGraphManager.h"

using namespace Minotaur;

CFileInputGraphManager::CFileInputGraphManager( std::istream& graphInputStream, const unsigned int& graphsCount ) :
	AbstractInputGraphManager(graphInputStream),
	m_graphsCount(graphsCount),
	m_graphName(""),
	m_nodesCount(0),
	m_edgesCount(0),
	m_graphCounter(0)
{
	
}

CFileInputGraphManager::~CFileInputGraphManager( void )
{

}
		
CGraphDto CFileInputGraphManager::GetNextGraph( void )
{
	if ( m_HasNextGraph() )
	{
		++m_graphCounter;

		t_graphInputStream >> m_graphName;

		t_graphInputStream >> m_nodesCount;
		std::vector < CNodeDto > dtoNodes;
		m_GetDtoNodes(dtoNodes);
		
		t_graphInputStream >> m_edgesCount;
		std::vector < CEdgeDto > dtoEdges;
		m_GetDtoEdges(dtoEdges);
		
		CGraphDto dtoGraph(m_graphName, dtoNodes, dtoEdges);
		
		return dtoGraph;
	}
}

bool CFileInputGraphManager::m_HasNextGraph( void ) const
{
	return ( m_graphsCount > m_graphCounter );
}

void CFileInputGraphManager::m_GetDtoNodes( std::vector < CNodeDto >& dtoNodes )
{
	unsigned int nodeDtoId = 0;
	unsigned int nodeDtoX = 0;
	unsigned int nodeDtoY = 0;
	
	for ( unsigned int nodeCounter = 0; nodeCounter < m_nodesCount; ++nodeCounter )
	{
		t_graphInputStream >> nodeDtoId;
		t_graphInputStream >> nodeDtoX;
		t_graphInputStream >> nodeDtoY;
		dtoNodes.push_back( CNodeDto(nodeDtoId, nodeDtoX, nodeDtoY) );
	}
}

void CFileInputGraphManager::m_GetDtoEdges( std::vector < CEdgeDto >& dtoEdges )
{
	unsigned int nodeFromId = 0;
	unsigned int nodeToId = 0;
	double edgeWeight = 0.0;
	
	for ( unsigned int edgeCounter = 0; edgeCounter < m_edgesCount; ++edgeCounter )
	{
		t_graphInputStream >> nodeFromId;
		t_graphInputStream >> nodeToId;
		t_graphInputStream >> edgeWeight;
		dtoEdges.push_back( CEdgeDto(nodeFromId, nodeToId, edgeWeight) );
	}
}