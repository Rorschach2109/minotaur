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
#include "SubGraphModel.h"
#include "AdjacencyListFactory.h"

#include "IPathFinder.h"
#include "ITreeFinder.h"

#include <cstdlib>
#include <unistd.h>

using namespace Minotaur;

CAlgorithmUIPage::CAlgorithmUIPage( AbstractInputGraphManager* inputGraphManager ) :
		AbstractUIPage(),
		m_inputGraphManager( inputGraphManager ),
		m_graphModel( nullptr ),
		m_resultSubGraph( nullptr ),
		m_treeFinder( nullptr ),
		m_pathFinder( nullptr )
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
	printf("4.\tAll MST Algorithms\n\n");

	printf("\t===== PATH =====\n");

	printf("5.\tDijkstra Algorithm\n");
	printf("6.\tBellman-Ford Algorithm\n");
	printf("7.\tAll Paths Algorithms\n\n");

	printf("99.\tEnd\n\n");
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
	case EAlgorithmOptionId::ALL_MST:
		m_LoadGraph();
		m_AllMSTAlgorithms();
		break;
	case EAlgorithmOptionId::DIJKSTRA:
		m_LoadGraph();
		m_DijkstraAlgorithm();
		break;
	case EAlgorithmOptionId::BELLMAN_FORD:
		m_LoadGraph();
		m_BellmanFordAlgorithm();
		break;
	case EAlgorithmOptionId::ALL_PATHS:
		m_LoadGraph();
		m_AllPathAlgorithms();
		break;
	case EAlgorithmOptionId::EXIT_ALGORITHM:
		printf("\nExit");
		break;
	default:
		printf("%s", t_wrongOptionMessage.c_str() );
	}
	m_graphModel.reset();
}

void CAlgorithmUIPage::m_LoadGraph( void ) const
{
	CGraphDto loadedDTOGraph = m_inputGraphManager->GetNextGraph();
	CAdjacencyListFactory adjacencyListFactory;
	m_graphModel = adjacencyListFactory.CreateFromDto( loadedDTOGraph.GetNodesDto(), loadedDTOGraph.GetEdgesDto() );
}

void CAlgorithmUIPage::m_KruskalAlgorithm( void ) const
{
	m_treeFinder = new CKruskalAlgorithm();

	delete m_treeFinder;
	m_treeFinder = nullptr;
}

void CAlgorithmUIPage::m_PrimAlgorithm( void ) const
{
	m_treeFinder = new CPrimAlgorithm();

	delete m_treeFinder;
	m_treeFinder = nullptr;
}

void CAlgorithmUIPage::m_BoruvkaAlgorithm( void ) const
{
	m_treeFinder = new CBoruvkaAlgorithm();

	delete m_treeFinder;
	m_treeFinder = nullptr;
}

void CAlgorithmUIPage::m_AllMSTAlgorithms( void ) const
{
	m_KruskalAlgorithm();
	m_PrimAlgorithm();
	m_BoruvkaAlgorithm();
}

void CAlgorithmUIPage::m_DijkstraAlgorithm( void ) const
{
	m_pathFinder = new CDijkstraAlgorithm();

	delete m_pathFinder;
	m_pathFinder = nullptr;
}

void CAlgorithmUIPage::m_BellmanFordAlgorithm( void ) const
{
	m_pathFinder = new CBellmanFordAlgorithm();

	delete m_pathFinder;
	m_pathFinder = nullptr;
}

void CAlgorithmUIPage::m_AllPathAlgorithms( void ) const
{
	m_DijkstraAlgorithm();
	m_AllPathAlgorithms();
}
