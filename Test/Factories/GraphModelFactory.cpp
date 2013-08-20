/*
 * This file is part of minotaur.
 *
 * File: GraphModelFactory.cpp
 * Brief: Implementation of graph model factory class.
 *
 * Date: 11.08.2013
 * Author: Andrzej Korycinski
 * 
 * */
 
#include "GraphModelFactory.h"

using namespace Minotaur;

CGraphModelFactory::CGraphModelFactory( void ) : 
	m_adjFactory( CAdjacencyListFactory() )
{
	m_CreateSquareModelGraph();
	m_CreateInfinityModelGraph();
	m_CreateTurtleModelGraph();
	m_CreateDoubleTriangleModelGraph();
	m_CreateSpiderNetModelGraph();
	m_CreateGrapeModelGraph();
}

CGraphModelFactory::~CGraphModelFactory( void )
{
	
}

void CGraphModelFactory::m_CreateSquareModelGraph( void )
{
	m_CreateSquareModelUtils();
	m_CreateSquareModelNodesMap();
	m_CreateSquareModelAdjacencyList();
}

void CGraphModelFactory::m_CreateSquareModelUtils( void )
{
	squareModelNodes.push_back( CNodeModel( 0, 0, 0 ) );
	squareModelNodes.push_back( CNodeModel( 1, 0, 2 ) );
	squareModelNodes.push_back( CNodeModel( 2, 2, 0 ) );
	squareModelNodes.push_back( CNodeModel( 3, 2, 2 ) );
	
	squareModelEdges.push_back( CEdgeModel( 0, 1, 3.7 ) );
	squareModelEdges.push_back( CEdgeModel( 0, 2, 2.9 ) );
	squareModelEdges.push_back( CEdgeModel( 1, 3, 2.1 ) );
	squareModelEdges.push_back( CEdgeModel( 2, 3, 3.2 ) );

	squareGraphModel = m_adjFactory.CreateFromVectors(squareModelNodes, squareModelEdges);
}

void CGraphModelFactory::m_CreateSquareModelNodesMap( void )
{
	for ( auto node : squareModelNodes )
	{
		squareNodesMap[ node.GetNodeId() ] = node;
	}	
}

void CGraphModelFactory::m_CreateSquareModelAdjacencyList( void )
{
	std::vector < std::pair < CEdgeModel, unsigned int > > node0Neighbors( {
					std::make_pair( squareModelEdges[0], 1 ),
					std::make_pair( squareModelEdges[1], 2 )
					} );
	std::vector < std::pair < CEdgeModel, unsigned int > > node1Neighbors( {
					std::make_pair( squareModelEdges[0], 0 ),
					std::make_pair( squareModelEdges[2], 3 )
					} );
	std::vector < std::pair < CEdgeModel, unsigned int > > node2Neighbors( {
					std::make_pair( squareModelEdges[1], 0 ),
					std::make_pair( squareModelEdges[3], 3 )
					} );
	std::vector < std::pair < CEdgeModel, unsigned int > > node3Neighbors( {
					std::make_pair( squareModelEdges[2], 1 ),
					std::make_pair( squareModelEdges[3], 2 )
					} );
	squareAdjacencyMap[0] = node0Neighbors;
	squareAdjacencyMap[1] = node1Neighbors;
	squareAdjacencyMap[2] = node2Neighbors;
	squareAdjacencyMap[3] = node3Neighbors;
}

void CGraphModelFactory::m_CreateInfinityModelGraph( void )
{
	m_CreateInfinityModelUtils();
	m_CreateInfinityModelNodesMap();
	m_CreateInfinityModelAdjacencyList();
}

void CGraphModelFactory::m_CreateInfinityModelUtils( void )
{
	infinityModelNodes.clear();
	infinityModelNodes.push_back( CNodeModel( 0, 0, 2 ) );
	infinityModelNodes.push_back( CNodeModel( 1, 2, 4 ) );
	infinityModelNodes.push_back( CNodeModel( 2, 2, 0 ) );
	infinityModelNodes.push_back( CNodeModel( 3, 4, 2 ) );
	infinityModelNodes.push_back( CNodeModel( 4, 6, 4 ) );
	infinityModelNodes.push_back( CNodeModel( 5, 6, 0 ) );
	infinityModelNodes.push_back( CNodeModel( 6, 8, 2 ) );

	infinityModelEdges.clear();
	infinityModelEdges.push_back( CEdgeModel( 0, 1, 1.7 ) );
	infinityModelEdges.push_back( CEdgeModel( 0, 2, 2.3 ) );
	infinityModelEdges.push_back( CEdgeModel( 1, 3, 1.9 ) );
	infinityModelEdges.push_back( CEdgeModel( 2, 3, 2.6 ) );
	infinityModelEdges.push_back( CEdgeModel( 3, 4, 3.1 ) );
	infinityModelEdges.push_back( CEdgeModel( 3, 5, 1.2 ) );
	infinityModelEdges.push_back( CEdgeModel( 4, 6, 1.8 ) );
	infinityModelEdges.push_back( CEdgeModel( 5, 6, 2.1 ) );

	infinityNode0Neighbors.clear();
	infinityNode0Neighbors.push_back( CNodeModel( 1, 2, 4 ) );
	infinityNode0Neighbors.push_back( CNodeModel( 2, 2, 0 ) );
	
	infinityGraphModel = m_adjFactory.CreateFromVectors(infinityModelNodes, infinityModelEdges);
}

void CGraphModelFactory::m_CreateInfinityModelNodesMap( void )
{
	for ( auto node : infinityModelNodes )
	{
		infinityNodesMap[ node.GetNodeId() ] = node;
	}
}

void CGraphModelFactory::m_CreateInfinityModelAdjacencyList( void )
{
	std::vector < std::pair < CEdgeModel, unsigned int > > node0Neighbors( {
					std::make_pair( infinityModelEdges[0], 1 ),
					std::make_pair( infinityModelEdges[1], 2 )
					} );
	std::vector < std::pair < CEdgeModel, unsigned int > > node1Neighbors( {
					std::make_pair( infinityModelEdges[0], 0 ),
					std::make_pair( infinityModelEdges[2], 3 )
					} );
	std::vector < std::pair < CEdgeModel, unsigned int > > node2Neighbors( {
					std::make_pair( infinityModelEdges[1], 0 ),
					std::make_pair( infinityModelEdges[3], 3 )
					} );
	std::vector < std::pair < CEdgeModel, unsigned int > > node3Neighbors( {
					std::make_pair( infinityModelEdges[2], 1 ),
					std::make_pair( infinityModelEdges[3], 2 ),
					std::make_pair( infinityModelEdges[4], 4 ),
					std::make_pair( infinityModelEdges[5], 5 )
					} );
	std::vector < std::pair < CEdgeModel, unsigned int > > node4Neighbors( {
					std::make_pair( infinityModelEdges[4], 3 ),
					std::make_pair( infinityModelEdges[6], 6 )
					} );
	std::vector < std::pair < CEdgeModel, unsigned int > > node5Neighbors( {
					std::make_pair( infinityModelEdges[5], 3 ),
					std::make_pair( infinityModelEdges[7], 6 )
					} );
	std::vector < std::pair < CEdgeModel, unsigned int > > node6Neighbors( {
					std::make_pair( infinityModelEdges[6], 4 ),
					std::make_pair( infinityModelEdges[7], 5 )
					} );
	infinityAdjacencyMap[0] = node0Neighbors;
	infinityAdjacencyMap[1] = node1Neighbors;
	infinityAdjacencyMap[2] = node2Neighbors;
	infinityAdjacencyMap[3] = node3Neighbors;
	infinityAdjacencyMap[4] = node4Neighbors;	
	infinityAdjacencyMap[5] = node5Neighbors;
	infinityAdjacencyMap[6] = node6Neighbors;
}

void CGraphModelFactory::m_CreateTurtleModelGraph( void )
{
	m_CreateTurtleModelUtils();
	m_CreateTurtleModelNodesMap();
	m_CreateTurtleModelAdjacencyList();
}

void CGraphModelFactory::m_CreateTurtleModelUtils( void )
{
	turtleModelNodes.push_back( CNodeModel( 0, 0, 0 ) );
	turtleModelNodes.push_back( CNodeModel( 1, 2, 0 ) );
	turtleModelNodes.push_back( CNodeModel( 2, 4, 2 ) );
	turtleModelNodes.push_back( CNodeModel( 3, 6, 0 ) );
	
	turtleModelEdges.push_back( CEdgeModel( 0, 1, 2.1 ) );
	turtleModelEdges.push_back( CEdgeModel( 1, 2, 2.5 ) );
	turtleModelEdges.push_back( CEdgeModel( 1, 3, 4.2 ) );
	turtleModelEdges.push_back( CEdgeModel( 2, 3, 1.2 ) );

	turtleGraphModel = m_adjFactory.CreateFromVectors(turtleModelNodes, turtleModelEdges);
}

void CGraphModelFactory::m_CreateTurtleModelNodesMap( void )
{
	for ( auto node : turtleModelNodes )
	{
		turtleNodesMap[ node.GetNodeId() ] = node;
	}	
}

void CGraphModelFactory::m_CreateTurtleModelAdjacencyList( void )
{
	std::vector < std::pair < CEdgeModel, unsigned int > > node0Neighbors( {
					std::make_pair( turtleModelEdges[0], 1 ),
					} );
	std::vector < std::pair < CEdgeModel, unsigned int > > node1Neighbors( {
					std::make_pair( turtleModelEdges[0], 0 ),
					std::make_pair( turtleModelEdges[1], 2 ),
					std::make_pair( turtleModelEdges[2], 3 )
					} );
	std::vector < std::pair < CEdgeModel, unsigned int > > node2Neighbors( {
					std::make_pair( turtleModelEdges[1], 1 ),
					std::make_pair( turtleModelEdges[3], 3 )
					} );
	std::vector < std::pair < CEdgeModel, unsigned int > > node3Neighbors( {
					std::make_pair( turtleModelEdges[2], 1 ),
					std::make_pair( turtleModelEdges[3], 2 )
					} );
					
	turtleAdjacencyMap[0] = node0Neighbors;
	turtleAdjacencyMap[1] = node1Neighbors;
	turtleAdjacencyMap[2] = node2Neighbors;
	turtleAdjacencyMap[3] = node3Neighbors;
}

void CGraphModelFactory::m_CreateDoubleTriangleModelGraph( void )
{
	m_CreateDoubleTriangleModelUtils();
	m_CreateDoubleTriangleModelNodesMap();
	m_CreateDoubleTriangleModelAdjacencyList();
}

void CGraphModelFactory::m_CreateDoubleTriangleModelUtils( void )
{
	doubleTriangleModelNodes.push_back( CNodeModel( 0, 0, 0 ) );
	doubleTriangleModelNodes.push_back( CNodeModel( 1, 2, 0 ) );
	doubleTriangleModelNodes.push_back( CNodeModel( 2, 4, 0 ) );
	doubleTriangleModelNodes.push_back( CNodeModel( 3, 1, 2 ) );
	doubleTriangleModelNodes.push_back( CNodeModel( 4, 3, 2 ) );
	doubleTriangleModelNodes.push_back( CNodeModel( 5, 2, 4 ) );
	
	doubleTriangleModelEdges.push_back( CEdgeModel( 0, 1, 1.7 ) );
	doubleTriangleModelEdges.push_back( CEdgeModel( 1, 2, 3.5 ) );
	doubleTriangleModelEdges.push_back( CEdgeModel( 0, 3, 2.1 ) );	
	doubleTriangleModelEdges.push_back( CEdgeModel( 1, 3, 2.3 ) );
	doubleTriangleModelEdges.push_back( CEdgeModel( 1, 4, 1.9 ) );
	doubleTriangleModelEdges.push_back( CEdgeModel( 2, 4, 2.7 ) );
	doubleTriangleModelEdges.push_back( CEdgeModel( 3, 4, 2.3 ) );
	doubleTriangleModelEdges.push_back( CEdgeModel( 3, 5, 2.2 ) );
	doubleTriangleModelEdges.push_back( CEdgeModel( 4, 5, 1.9 ) );
	
	doubleTriangleGraphModel = m_adjFactory.CreateFromVectors(doubleTriangleModelNodes, doubleTriangleModelEdges);
}

void CGraphModelFactory::m_CreateDoubleTriangleModelNodesMap( void )
{
	for ( auto node : doubleTriangleModelNodes )
	{
		doubleTriangleNodesMap[ node.GetNodeId() ] = node;
	}
}

void CGraphModelFactory::m_CreateDoubleTriangleModelAdjacencyList( void )
{
	std::vector < std::pair < CEdgeModel, unsigned int > > node0Neighbors( {
					std::make_pair( doubleTriangleModelEdges[0], 1 ),
					std::make_pair( doubleTriangleModelEdges[1], 3 )
					} );
	std::vector < std::pair < CEdgeModel, unsigned int > > node1Neighbors( {
					std::make_pair( doubleTriangleModelEdges[0], 0 ),
					std::make_pair( doubleTriangleModelEdges[2], 2 ),
					std::make_pair( doubleTriangleModelEdges[3], 3 ),
					std::make_pair( doubleTriangleModelEdges[4], 4 )
					} );
	std::vector < std::pair < CEdgeModel, unsigned int > > node2Neighbors( {
					std::make_pair( doubleTriangleModelEdges[2], 1 ),
					std::make_pair( doubleTriangleModelEdges[5], 4 )
					} );
	std::vector < std::pair < CEdgeModel, unsigned int > > node3Neighbors( {
					std::make_pair( doubleTriangleModelEdges[1], 0 ),
					std::make_pair( doubleTriangleModelEdges[3], 1 ),
					std::make_pair( doubleTriangleModelEdges[6], 4 ),
					std::make_pair( doubleTriangleModelEdges[7], 5 )
					} );
	std::vector < std::pair < CEdgeModel, unsigned int > > node4Neighbors( {
					std::make_pair( doubleTriangleModelEdges[4], 1 ),
					std::make_pair( doubleTriangleModelEdges[5], 2 ),
					std::make_pair( doubleTriangleModelEdges[6], 3 ),
					std::make_pair( doubleTriangleModelEdges[8], 5 )
					} );
	std::vector < std::pair < CEdgeModel, unsigned int > > node5Neighbors( {
					std::make_pair( doubleTriangleModelEdges[7], 3 ),
					std::make_pair( doubleTriangleModelEdges[8], 4 )
					} );
	doubleTriangleAdjacencyMap[0] = node0Neighbors;
	doubleTriangleAdjacencyMap[1] = node1Neighbors;
	doubleTriangleAdjacencyMap[2] = node2Neighbors;
	doubleTriangleAdjacencyMap[3] = node3Neighbors;
	doubleTriangleAdjacencyMap[4] = node4Neighbors;
	doubleTriangleAdjacencyMap[5] = node5Neighbors;
}

void CGraphModelFactory::m_CreateSpiderNetModelGraph( void )
{
	m_CreateSpiderNetModelUtils();
	m_CreateSpiderNetModelNodesMap();
	m_CreateSpiderNetModelAdjacencyList();
}

void CGraphModelFactory::m_CreateSpiderNetModelUtils( void )
{
	CAdjacencyListFactory adjFactory = CAdjacencyListFactory();
	
	spiderNetModelNodes.clear();
	spiderNetModelNodes.push_back( CNodeModel( 0, 0, 0 ) );
	spiderNetModelNodes.push_back( CNodeModel( 1, 0, 0 ) );
	spiderNetModelNodes.push_back( CNodeModel( 2, 0, 0 ) );
	spiderNetModelNodes.push_back( CNodeModel( 3, 0, 0 ) );
	spiderNetModelNodes.push_back( CNodeModel( 4, 0, 0 ) );
	spiderNetModelNodes.push_back( CNodeModel( 5, 0, 0 ) );
	spiderNetModelNodes.push_back( CNodeModel( 6, 0, 0 ) );
	spiderNetModelNodes.push_back( CNodeModel( 7, 0, 0 ) );
	
	spiderNetModelEdges.clear();
	spiderNetModelEdges.push_back( CEdgeModel( 0, 1, 3.0 ) );
	spiderNetModelEdges.push_back( CEdgeModel( 0, 2, 2.0 ) );
	spiderNetModelEdges.push_back( CEdgeModel( 0, 3, 5.0 ) );
	spiderNetModelEdges.push_back( CEdgeModel( 1, 3, 2.0 ) );
	spiderNetModelEdges.push_back( CEdgeModel( 1, 5, 13.0 ) );
	spiderNetModelEdges.push_back( CEdgeModel( 2, 3, 2.0 ) );
	spiderNetModelEdges.push_back( CEdgeModel( 2, 4, 5.0 ) );
	spiderNetModelEdges.push_back( CEdgeModel( 3, 4, 4.0 ) );
	spiderNetModelEdges.push_back( CEdgeModel( 3, 5, 6.0 ) );
	spiderNetModelEdges.push_back( CEdgeModel( 3, 6, 3.0 ) );
	spiderNetModelEdges.push_back( CEdgeModel( 4, 6, 6.0 ) );
	spiderNetModelEdges.push_back( CEdgeModel( 5, 6, 2.0 ) );
	spiderNetModelEdges.push_back( CEdgeModel( 5, 7, 3.0 ) );
	spiderNetModelEdges.push_back( CEdgeModel( 6, 7, 6.0 ) );	

	spiderNetGraphModel = adjFactory.CreateFromVectors(spiderNetModelNodes, spiderNetModelEdges);
}

void CGraphModelFactory::m_CreateSpiderNetModelNodesMap( void )
{
	for ( auto node : spiderNetModelNodes )
	{
		spiderNetNodesMap[ node.GetNodeId() ] = node;
	}
}

void CGraphModelFactory::m_CreateSpiderNetModelAdjacencyList( void )
{
	std::vector < std::pair < CEdgeModel, unsigned int > > node0Neighbors( {
					std::make_pair( spiderNetModelEdges[0], 1 ),
					std::make_pair( spiderNetModelEdges[1], 2 ),
					std::make_pair( spiderNetModelEdges[2], 3 )
					} );
	std::vector < std::pair < CEdgeModel, unsigned int > > node1Neighbors( {
					std::make_pair( spiderNetModelEdges[0], 0 ),
					std::make_pair( spiderNetModelEdges[3], 3 ),
					std::make_pair( spiderNetModelEdges[4], 5 )
					} );
	std::vector < std::pair < CEdgeModel, unsigned int > > node2Neighbors( {
					std::make_pair( spiderNetModelEdges[1], 0 ),
					std::make_pair( spiderNetModelEdges[5], 3 ),
					std::make_pair( spiderNetModelEdges[6], 4 )
					} );
	std::vector < std::pair < CEdgeModel, unsigned int > > node3Neighbors( {
					std::make_pair( spiderNetModelEdges[2], 0 ),
					std::make_pair( spiderNetModelEdges[3], 1 ),
					std::make_pair( spiderNetModelEdges[5], 2 ),
					std::make_pair( spiderNetModelEdges[7], 4 ),
					std::make_pair( spiderNetModelEdges[8], 5 ),
					std::make_pair( spiderNetModelEdges[9], 6 )
					} );
	std::vector < std::pair < CEdgeModel, unsigned int > > node4Neighbors( {
					std::make_pair( spiderNetModelEdges[6], 2 ),
					std::make_pair( spiderNetModelEdges[7], 3 ),
					std::make_pair( spiderNetModelEdges[10], 6 )
					} );
	std::vector < std::pair < CEdgeModel, unsigned int > > node5Neighbors( {
					std::make_pair( spiderNetModelEdges[4], 1 ),
					std::make_pair( spiderNetModelEdges[8], 3 ),
					std::make_pair( spiderNetModelEdges[11], 6 ),
					std::make_pair( spiderNetModelEdges[12], 7 )
					} );
	std::vector < std::pair < CEdgeModel, unsigned int > > node6Neighbors( {
					std::make_pair( spiderNetModelEdges[9], 3 ),
					std::make_pair( spiderNetModelEdges[10], 4 ),
					std::make_pair( spiderNetModelEdges[11], 5 ),
					std::make_pair( spiderNetModelEdges[13], 7 )
					} );
	std::vector < std::pair < CEdgeModel, unsigned int > > node7Neighbors( {
					std::make_pair( spiderNetModelEdges[12], 5 ),
					std::make_pair( spiderNetModelEdges[13], 6 )
					} );

	spiderNetAdjacencyMap[0] = node0Neighbors;
	spiderNetAdjacencyMap[1] = node1Neighbors;
	spiderNetAdjacencyMap[2] = node2Neighbors;
	spiderNetAdjacencyMap[3] = node3Neighbors;
	spiderNetAdjacencyMap[4] = node4Neighbors;
	spiderNetAdjacencyMap[5] = node5Neighbors;
	spiderNetAdjacencyMap[6] = node6Neighbors;
	spiderNetAdjacencyMap[7] = node7Neighbors;
}

void CGraphModelFactory::m_CreateGrapeModelGraph( void )
{
	m_CreateGrapeModelUtils();
	m_CreateGrapeModelNodesMap();
	m_CreateGrapeModelAdjacencyList();
}

void CGraphModelFactory::m_CreateGrapeModelUtils( void )
{
	CAdjacencyListFactory adjFactory = CAdjacencyListFactory();
	
	grapeModelNodes.clear();
	grapeModelNodes.push_back( CNodeModel( 0, 0, 0 ) );
	grapeModelNodes.push_back( CNodeModel( 1, 0, 0 ) );
	grapeModelNodes.push_back( CNodeModel( 2, 0, 0 ) );
	grapeModelNodes.push_back( CNodeModel( 3, 0, 0 ) );
	grapeModelNodes.push_back( CNodeModel( 4, 0, 0 ) );
	grapeModelNodes.push_back( CNodeModel( 5, 0, 0 ) );
	grapeModelNodes.push_back( CNodeModel( 6, 0, 0 ) );
	grapeModelNodes.push_back( CNodeModel( 7, 0, 0 ) );
	grapeModelNodes.push_back( CNodeModel( 8, 0, 0 ) );
	grapeModelNodes.push_back( CNodeModel( 9, 0, 0 ) );
	grapeModelNodes.push_back( CNodeModel( 10, 0, 0 ) );
	grapeModelNodes.push_back( CNodeModel( 11, 0, 0 ) );
	grapeModelNodes.push_back( CNodeModel( 12, 0, 0 ) );
	grapeModelNodes.push_back( CNodeModel( 13, 0, 0 ) );
	grapeModelNodes.push_back( CNodeModel( 14, 0, 0 ) );
	grapeModelNodes.push_back( CNodeModel( 15, 0, 0 ) );
	grapeModelNodes.push_back( CNodeModel( 16, 0, 0 ) );
	grapeModelNodes.push_back( CNodeModel( 17, 0, 0 ) );
	
	grapeModelEdges.clear();
	grapeModelEdges.push_back( CEdgeModel( 0, 1, 2.0 ) );
	grapeModelEdges.push_back( CEdgeModel( 0, 2, 5.0 ) );
	grapeModelEdges.push_back( CEdgeModel( 1, 3, 8.0 ) );
	grapeModelEdges.push_back( CEdgeModel( 1, 4, 6.0 ) );
	grapeModelEdges.push_back( CEdgeModel( 2, 3, 3.0 ) );
	grapeModelEdges.push_back( CEdgeModel( 3, 6, 2.0 ) );
	grapeModelEdges.push_back( CEdgeModel( 3, 7, 4.0 ) );
	grapeModelEdges.push_back( CEdgeModel( 4, 5, 5.0 ) );
	grapeModelEdges.push_back( CEdgeModel( 4, 6, 6.0 ) );
	grapeModelEdges.push_back( CEdgeModel( 5, 11, 6.0 ) );
	grapeModelEdges.push_back( CEdgeModel( 5, 12, 5.0 ) );
	grapeModelEdges.push_back( CEdgeModel( 6, 8, 6.0 ) );
	grapeModelEdges.push_back( CEdgeModel( 6, 11, 3.0 ) );
	grapeModelEdges.push_back( CEdgeModel( 7, 8, 5.0 ) );
	grapeModelEdges.push_back( CEdgeModel( 8, 9, 3.0 ) );
	grapeModelEdges.push_back( CEdgeModel( 8, 10, 6.0 ) );
	grapeModelEdges.push_back( CEdgeModel( 9, 10, 4.0 ) );
	grapeModelEdges.push_back( CEdgeModel( 10, 14, 5.0 ) );
	grapeModelEdges.push_back( CEdgeModel( 11, 10, 6.0 ) );
	grapeModelEdges.push_back( CEdgeModel( 11, 14, 7.0 ) );
	grapeModelEdges.push_back( CEdgeModel( 12, 13, 3.0 ) );
	grapeModelEdges.push_back( CEdgeModel( 12, 14, 4.0 ) );
	grapeModelEdges.push_back( CEdgeModel( 13, 14, 2.0 ) );
	grapeModelEdges.push_back( CEdgeModel( 14, 15, 9.0 ) );
	grapeModelEdges.push_back( CEdgeModel( 14, 17, 8.0 ) );
	grapeModelEdges.push_back( CEdgeModel( 15, 16, 3.0 ) );
	grapeModelEdges.push_back( CEdgeModel( 17, 16, 5.0 ) );

	grapeGraphModel = adjFactory.CreateFromVectors(grapeModelNodes, grapeModelEdges);
}

void CGraphModelFactory::m_CreateGrapeModelNodesMap( void )
{
	for ( auto node : grapeModelNodes )
	{
		grapeNodesMap[ node.GetNodeId() ] = node;
	}		
}

void CGraphModelFactory::m_CreateGrapeModelAdjacencyList( void )
{
	std::vector < std::pair < CEdgeModel, unsigned int > > node0Neighbors( {
					std::make_pair( grapeModelEdges[0], 1 ),
					std::make_pair( grapeModelEdges[1], 2 )
					} );
	std::vector < std::pair < CEdgeModel, unsigned int > > node1Neighbors( {
					std::make_pair( grapeModelEdges[0], 0 ),
					std::make_pair( grapeModelEdges[2], 3 ),
					std::make_pair( grapeModelEdges[3], 4 )
					} );
	std::vector < std::pair < CEdgeModel, unsigned int > > node2Neighbors( {
					std::make_pair( grapeModelEdges[1], 0 ),
					std::make_pair( grapeModelEdges[4], 3 )
					} );
	std::vector < std::pair < CEdgeModel, unsigned int > > node3Neighbors( {
					std::make_pair( grapeModelEdges[0], 1 ),
					std::make_pair( grapeModelEdges[4], 2 ),
					std::make_pair( grapeModelEdges[5], 6 ),
					std::make_pair( grapeModelEdges[6], 7 )
					} );
	std::vector < std::pair < CEdgeModel, unsigned int > > node4Neighbors( {
					std::make_pair( grapeModelEdges[3], 1 ),
					std::make_pair( grapeModelEdges[7], 5 ),
					std::make_pair( grapeModelEdges[8], 6 )
					} );
	std::vector < std::pair < CEdgeModel, unsigned int > > node5Neighbors( {
					std::make_pair( grapeModelEdges[7], 4 ),
					std::make_pair( grapeModelEdges[9], 11 ),
					std::make_pair( grapeModelEdges[10], 12 )
					} );
	std::vector < std::pair < CEdgeModel, unsigned int > > node6Neighbors( {
					std::make_pair( grapeModelEdges[5], 3 ),
					std::make_pair( grapeModelEdges[8], 4 ),
					std::make_pair( grapeModelEdges[11], 8 ),
					std::make_pair( grapeModelEdges[12], 11 )
					} );
	std::vector < std::pair < CEdgeModel, unsigned int > > node7Neighbors( {
					std::make_pair( grapeModelEdges[6], 3 ),
					std::make_pair( grapeModelEdges[13], 8 )
					} );
	std::vector < std::pair < CEdgeModel, unsigned int > > node8Neighbors( {
					std::make_pair( grapeModelEdges[11], 6 ),
					std::make_pair( grapeModelEdges[13], 7 ),
					std::make_pair( grapeModelEdges[14], 9 ),
					std::make_pair( grapeModelEdges[15], 10 )
					} );
	std::vector < std::pair < CEdgeModel, unsigned int > > node9Neighbors( {
					std::make_pair( grapeModelEdges[14], 8 ),
					std::make_pair( grapeModelEdges[16], 10 )
					} );
	std::vector < std::pair < CEdgeModel, unsigned int > > node10Neighbors( {
					std::make_pair( grapeModelEdges[15], 8 ),
					std::make_pair( grapeModelEdges[16], 9 ),
					std::make_pair( grapeModelEdges[17], 11 ),
					std::make_pair( grapeModelEdges[18], 14 )
					} );
	std::vector < std::pair < CEdgeModel, unsigned int > > node11Neighbors( {
					std::make_pair( grapeModelEdges[9], 5 ),
					std::make_pair( grapeModelEdges[12], 6 ),
					std::make_pair( grapeModelEdges[17], 10 ),
					std::make_pair( grapeModelEdges[19], 14 )
					} );
	std::vector < std::pair < CEdgeModel, unsigned int > > node12Neighbors( {
					std::make_pair( grapeModelEdges[10], 5 ),
					std::make_pair( grapeModelEdges[20], 13 ),
					std::make_pair( grapeModelEdges[21], 14 )
					} );
	std::vector < std::pair < CEdgeModel, unsigned int > > node13Neighbors( {
					std::make_pair( grapeModelEdges[20], 12 ),
					std::make_pair( grapeModelEdges[22], 14 )
					} );
	std::vector < std::pair < CEdgeModel, unsigned int > > node14Neighbors( {
					std::make_pair( grapeModelEdges[18], 10 ),
					std::make_pair( grapeModelEdges[19], 11 ),
					std::make_pair( grapeModelEdges[21], 12 ),
					std::make_pair( grapeModelEdges[22], 13 ),
					std::make_pair( grapeModelEdges[23], 15 ),
					std::make_pair( grapeModelEdges[24], 17 )
					} );
	std::vector < std::pair < CEdgeModel, unsigned int > > node15Neighbors( {
					std::make_pair( grapeModelEdges[23], 14 ),
					std::make_pair( grapeModelEdges[25], 16 )
					} );
	std::vector < std::pair < CEdgeModel, unsigned int > > node16Neighbors( {
					std::make_pair( grapeModelEdges[25], 15 ),
					std::make_pair( grapeModelEdges[26], 17 )
					} );
	std::vector < std::pair < CEdgeModel, unsigned int > > node17Neighbors( {
					std::make_pair( grapeModelEdges[24], 14 ),
					std::make_pair( grapeModelEdges[26], 16 )
					} );

	grapeAdjacencyMap[0] = node0Neighbors;
	grapeAdjacencyMap[1] = node1Neighbors;
	grapeAdjacencyMap[2] = node2Neighbors;
	grapeAdjacencyMap[3] = node3Neighbors;
	grapeAdjacencyMap[4] = node4Neighbors;
	grapeAdjacencyMap[5] = node5Neighbors;
	grapeAdjacencyMap[6] = node6Neighbors;
	grapeAdjacencyMap[7] = node7Neighbors;
	grapeAdjacencyMap[8] = node8Neighbors;
	grapeAdjacencyMap[9] = node9Neighbors;
	grapeAdjacencyMap[10] = node10Neighbors;
	grapeAdjacencyMap[11] = node11Neighbors;
	grapeAdjacencyMap[12] = node12Neighbors;
	grapeAdjacencyMap[13] = node13Neighbors;
	grapeAdjacencyMap[14] = node14Neighbors;
	grapeAdjacencyMap[15] = node15Neighbors;
	grapeAdjacencyMap[16] = node16Neighbors;
	grapeAdjacencyMap[17] = node17Neighbors;
}
