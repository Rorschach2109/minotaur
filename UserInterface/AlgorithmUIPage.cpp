/*
 * This file is part of minotaur.
 *
 * File: AlgorithmUIPage.cpp
 * Brief: Implementation of algorithm user interface page class.
 *
 * Date: 09.10.2013
 * Author: Andrzej Korycinski
 *
 * */

#include "AlgorithmUIPage.h"
#include "AbstractInputGraphManager.h"

#include "AlgorithmIncludes.h"
#include "GraphDTO.h"
#include "IGraphModel.h"
#include "SubGraphToGraphAdapter.h"
#include "AdjacencyListFactory.h"
#include "SubGraphToGraphAdapter.h"

#include "NodeModel.h"
#include "EdgeModel.h"
#include "NodeDTO.h"
#include "EdgeDTO.h"
#include "GraphDTO.h"

#include "StreamOutputGraphManager.h"
#include "DotOutputGraphManager.h"

#include "IPathFinder.h"
#include "ITreeFinder.h"

#include <cstdlib>
#include <unistd.h>
#include <memory>
#include <vector>
#include <fstream>
#include <iostream>

using namespace Minotaur;

CAlgorithmUIPage::CAlgorithmUIPage( AbstractInputGraphManager* inputGraphManager, const std::string& graphName ) :
		AbstractUIPage(),
		m_nodeFromId( 0 ),
		m_nodeToId( 0 ),
		m_inputGraphManager( inputGraphManager ),
		m_outputGraphManager( nullptr ),
		m_graphModel( nullptr ),
		m_resultSubGraph( nullptr ),
		m_treeFinder( nullptr ),
		m_pathFinder( nullptr ),
		m_subGraphName( graphName )
{

}

CAlgorithmUIPage::~CAlgorithmUIPage( void )
{
	m_graphModel.reset();
	m_resultSubGraph.reset();
	if ( nullptr != m_treeFinder )
	{
		delete m_treeFinder;
		m_treeFinder = nullptr;
	}
	if ( nullptr != m_pathFinder )
	{
		delete m_pathFinder;
		m_pathFinder = nullptr;
	}
}

void CAlgorithmUIPage::DisplayOptions( void ) const
{
	printf("*****Algorithm Page*****\n\n");

	printf("\t===== MST =====\n");

	printf("1.\tKruskal Algorithm\n");
	printf("2.\tPrim Algorithm\n");
	printf("3.\tBoruvka Algorithm\n");

	printf("\n\t===== PATH =====\n");

	printf("4.\tDijkstra Algorithm\n");
	printf("5.\tBellman-Ford Algorithm\n");

	printf("\n99.\tEnd\n\n");
}

void CAlgorithmUIPage::ExecuteOption( void ) const
{
	switch( t_optionId )
	{
	case EAlgorithmOptionId::KRUSKAL:
		m_LoadGraph();
		m_KruskalAlgorithm();
		break;
	case EAlgorithmOptionId::PRIM:
		m_LoadGraph();
		m_PrimAlgorithm();
		break;
	case EAlgorithmOptionId::BORUVKA:
		m_LoadGraph();
		m_BoruvkaAlgorithm();
		break;
	case EAlgorithmOptionId::DIJKSTRA:
		m_LoadGraph();
		m_DijkstraAlgorithm();
		break;
	case EAlgorithmOptionId::BELLMAN_FORD:
		m_LoadGraph();
		m_BellmanFordAlgorithm();
		break;
	case EAlgorithmOptionId::EXIT_ALGORITHM:
		break;
	default:
		printf("%s", t_wrongOptionMessage.c_str() );
	}
	m_graphModel.reset();
}

const std::string& CAlgorithmUIPage::GetSubGraphName( void ) const
{
	return m_subGraphName;
}

void CAlgorithmUIPage::m_LoadGraph( void ) const
{
	CGraphDto loadedDTOGraph = m_inputGraphManager->GetNextGraph();
	CAdjacencyListFactory adjacencyListFactory;
	m_graphModel = adjacencyListFactory.CreateFromDto( loadedDTOGraph.GetNodesDto(), loadedDTOGraph.GetEdgesDto() );
}

void CAlgorithmUIPage::m_WriteGraphToFile( void ) const
{
	if ( nullptr != m_resultSubGraph )
	{
		std::vector<CNodeDto> dtoNodes;

		for ( auto modelNode : m_resultSubGraph->GetGraphModelNodes() )
		{
			unsigned int nodeId = modelNode.GetNodeId();
			unsigned int nodeX = modelNode.GetNodeX();
			unsigned int nodeY = modelNode.GetNodeY();
		
			CNodeDto dtoNode = CNodeDto(nodeId, nodeX, nodeY);
			dtoNodes.push_back( dtoNode );
		}

		std::vector<CEdgeDto> dtoEdges;
		for ( auto modelEdge :  m_resultSubGraph->GetGraphModelEdges() )
		{
			unsigned int nodeFromId = modelEdge.GetNodeFromId();
			unsigned int nodeToId = modelEdge.GetNodeToId();
			double edgeWeight = modelEdge.GetEdgeWeight();
			
			CEdgeDto dtoEdge = CEdgeDto(nodeFromId, nodeToId, edgeWeight);
			dtoEdges.push_back( dtoEdge );
		}

		CGraphDto dtoGraph = CGraphDto(m_subGraphName, dtoNodes, dtoEdges);
		
		std::ofstream streamOutputStream;
		std::string streamPath = "./../GraphFiles/AKGraphs/" + m_subGraphName;
		streamOutputStream.open( streamPath.c_str() );
		
		CStreamOutputGraphManager streamOutputGraphManager = CStreamOutputGraphManager(streamOutputStream, 1);
		streamOutputGraphManager.WriteGraphToOutput(dtoGraph);
		
		streamOutputStream.close();
		
		std::string systemCommand = "perl ./../PerlParser/AKToDotConverter.pl " + m_subGraphName;
		system( systemCommand.c_str() );
	}
}

void CAlgorithmUIPage::m_WriteMSTExecutionTimeToFile( const std::string& algorithmName ) const
{
	if ( m_treeFinder && !m_resultSubGraph )
	{
		std::ofstream streamOutputStream;
		std::string streamPath = "./../ExecutionTime/MST/" + algorithmName;
		streamOutputStream.open( streamPath.c_str(), std::ios::app );
		
		unsigned long long executionTime = m_treeFinder->GetExecutionTime();
		
		streamOutputStream << m_subGraphName << "\t" << executionTime << "\n";
		
		streamOutputStream.close();
	}
}

void CAlgorithmUIPage::m_WritePathExecutionTimeToFile( const std::string& algorithmName ) const
{
	if ( m_pathFinder && !m_resultSubGraph )
	{
		std::ofstream streamOutputStream;
		std::string streamPath = "./../ExecutionTime/Path/" + algorithmName;
		streamOutputStream.open( streamPath.c_str(), std::ios::app );
		
		unsigned long long executionTime = m_pathFinder->GetExecutionTime();
		
		streamOutputStream << m_subGraphName << "\t" << executionTime << "\n";
		
		streamOutputStream.close();
	}
}

void CAlgorithmUIPage::m_WriteMSTMemoryUsageToFile( const std::string& algorithmName ) const
{
	if ( m_treeFinder && !m_resultSubGraph )
	{
		std::ofstream streamOutputStream;
		std::string streamPath = "./../MemoryUsage/MST/" + algorithmName;
		streamOutputStream.open( streamPath.c_str(), std::ios::app );

		unsigned long long minotaurStackMemoryUsage = m_treeFinder->GetStackMemoryAllocated();
		unsigned long long minotaurStackMemoryFreed = m_treeFinder->GetStackMemoryFreed();
		unsigned long long minotaurHeapMemoryUsage = m_treeFinder->GetHeapMemoryUsage();
		
		streamOutputStream << m_subGraphName << "\t" << minotaurStackMemoryUsage << "\t" << minotaurStackMemoryFreed << "\t" << minotaurHeapMemoryUsage << "\n";
		
		streamOutputStream.close();
	}
}

void CAlgorithmUIPage::m_WritePathMemoryUsageToFile( const std::string& algorithmName ) const
{
	if ( m_pathFinder && !m_resultSubGraph )
	{
		std::ofstream streamOutputStream;
		std::string streamPath = "./../MemoryUsage/Path/" + algorithmName;
		streamOutputStream.open( streamPath.c_str(), std::ios::app );

		unsigned long long minotaurStackMemoryUsage = m_pathFinder->GetStackMemoryAllocated();
		unsigned long long minotaurStackMemoryFreed = m_pathFinder->GetStackMemoryFreed();
		unsigned long long minotaurHeapMemoryUsage = m_pathFinder->GetHeapMemoryUsage();
		
		streamOutputStream << m_subGraphName << "\t" << minotaurStackMemoryUsage << "\t" << minotaurStackMemoryFreed << "\t" << minotaurHeapMemoryUsage << "\n";
		
		streamOutputStream.close();
	}	
}

void CAlgorithmUIPage::m_GetNodesId( void ) const
{
	printf("Get NodeFromId: ");
	std::cin >> m_nodeFromId;
	printf("Get NodeToId: ");
	std::cin >> m_nodeToId;
}

bool CAlgorithmUIPage::m_CheckNodesId( void ) const
{
	bool result = m_graphModel->ContainsNode(m_nodeFromId) && 
		m_graphModel->ContainsNode(m_nodeToId);
	return result;
}
		
void CAlgorithmUIPage::m_KruskalAlgorithm( void ) const
{
	m_subGraphName = "KruskalMST" + m_subGraphName;
	m_treeFinder = new CKruskalAlgorithm();
	std::shared_ptr < CSubGraphModel > kruskalMST = m_treeFinder->FindMST( *m_graphModel, m_graphModel->GetGraphModelNodes().front() );
	
	m_WriteMSTExecutionTimeToFile("Kruskal");
	m_WriteMSTMemoryUsageToFile("Kruskal");
	
	CSubGraphToGraphAdapter subgraphAdapter(*kruskalMST);
	m_resultSubGraph = std::make_shared < CSubGraphToGraphAdapter > ( subgraphAdapter );
	
	m_WriteGraphToFile();
	m_ExitAlgorithmPage();
}

void CAlgorithmUIPage::m_PrimAlgorithm( void ) const
{
	m_subGraphName = "PrimMST" + m_subGraphName;
	m_treeFinder = new CPrimAlgorithm();
	std::shared_ptr < CSubGraphModel > primMST = m_treeFinder->FindMST( *m_graphModel, m_graphModel->GetGraphModelNodes().front() );
	
	m_WriteMSTExecutionTimeToFile("Prim");
	m_WriteMSTMemoryUsageToFile("Prim");
	
	CSubGraphToGraphAdapter subgraphAdapter(*primMST);
	m_resultSubGraph = std::make_shared < CSubGraphToGraphAdapter > ( subgraphAdapter );
	
	m_WriteGraphToFile();
	m_ExitAlgorithmPage();
}

void CAlgorithmUIPage::m_BoruvkaAlgorithm( void ) const
{
	m_subGraphName = "BoruvkaMST" + m_subGraphName;
	m_treeFinder = new CBoruvkaAlgorithm();
	std::shared_ptr < CSubGraphModel > boruvkaMST = m_treeFinder->FindMST( *m_graphModel, m_graphModel->GetGraphModelNodes().front() );
	
	m_WriteMSTExecutionTimeToFile("Boruvka");
	m_WriteMSTMemoryUsageToFile("Boruvka");
	
	CSubGraphToGraphAdapter subgraphAdapter(*boruvkaMST);
	m_resultSubGraph = std::make_shared < CSubGraphToGraphAdapter > ( subgraphAdapter );
	
	m_WriteGraphToFile();
	m_ExitAlgorithmPage();
}

void CAlgorithmUIPage::m_DijkstraAlgorithm( void ) const
{
	m_subGraphName = "Dijkstra" + m_subGraphName;
	CRelaxationProvider relaxationProvider;
	m_pathFinder = new CDijkstraAlgorithm(relaxationProvider);
	m_GetNodesId();
	if( m_CheckNodesId() )
	{
		std::shared_ptr < CSubGraphModel > dijkstraPath = m_pathFinder->FindShortestPath( *m_graphModel, m_graphModel->GetGraphModelNode(m_nodeFromId), 
		m_graphModel->GetGraphModelNode(m_nodeToId) );
		
		m_WritePathExecutionTimeToFile("Dijkstra");
		m_WritePathMemoryUsageToFile("Dijkstra");
		
		CSubGraphToGraphAdapter subgraphAdapter(*dijkstraPath);
		m_resultSubGraph = std::make_shared < CSubGraphToGraphAdapter > ( subgraphAdapter );
		
		m_WriteGraphToFile();
	}
	else
	{
		printf("Wrong Nodes!\n\n");
	}
	
	delete m_pathFinder;
	
	m_pathFinder = nullptr;
	m_ExitAlgorithmPage();
}

void CAlgorithmUIPage::m_BellmanFordAlgorithm( void ) const
{
	m_subGraphName = "BellmanFord" + m_subGraphName;
	CRelaxationProvider relaxationProvider;
	m_pathFinder = new CBellmanFordAlgorithm(relaxationProvider);
	m_GetNodesId();
	if( m_CheckNodesId() )
	{
		std::shared_ptr < CSubGraphModel > bellmanFordPath = m_pathFinder->FindShortestPath( *m_graphModel, m_graphModel->GetGraphModelNode(m_nodeFromId), 
		m_graphModel->GetGraphModelNode(m_nodeToId) );
		
		m_WritePathExecutionTimeToFile("Bellman-Ford");
		m_WritePathMemoryUsageToFile("Bellman-Ford");
		
		CSubGraphToGraphAdapter subgraphAdapter(*bellmanFordPath);
		m_resultSubGraph = std::make_shared < CSubGraphToGraphAdapter > ( subgraphAdapter );
		
		m_WriteGraphToFile();
	}
	else
	{
		printf("Wrong Nodes!\n\n");
	}	
	
	delete m_pathFinder;
	m_pathFinder = nullptr;
	
	m_ExitAlgorithmPage();
}

void CAlgorithmUIPage::m_ExitAlgorithmPage( void ) const
{
	if ( nullptr != m_treeFinder )
	{
		delete m_treeFinder;
		m_treeFinder = nullptr;
	}
	if ( nullptr != m_pathFinder )
	{
		delete m_pathFinder;
		m_pathFinder = nullptr;
	}
	t_optionId = EAlgorithmOptionId::EXIT_ALGORITHM;
	this->ExecuteOption();
}
