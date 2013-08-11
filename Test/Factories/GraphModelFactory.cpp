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

CGraphModelFactory::CGraphModelFactory( void )
{
	m_CreateSquareModelGraph();
	m_CreateInfinityModelGraph();
	m_CreateTurtleModelGraph();
	m_CreateDoubleTriangleModelGraph();
}

CGraphModelFactory::~CGraphModelFactory( void )
{
	
}

void CGraphModelFactory::m_CreateSquareModelGraph( void )
{
	m_CreateSquareModelNodesMap();
	m_CreateSquareModelAdjacencyList();
}

void CGraphModelFactory::m_CreateSquareModelNodesMap( void )
{
	std::vector < CNodeModel > squareModelNodes( {
					CNodeModel( 0, 0, 0 ),
					CNodeModel( 1, 0, 2 ),
					CNodeModel( 2, 2, 0 ),
					CNodeModel( 3, 2, 2 ) 
					} );
	for ( auto node : squareModelNodes )
	{
		squareNodesMap[ node.GetNodeId() ] = node;
	}	
}

void CGraphModelFactory::m_CreateSquareModelAdjacencyList( void )
{
	std::vector < std::pair < CEdgeModel, unsigned int > > node0Neighbors( {
					std::make_pair( CEdgeModel( 0, 1, 3.7 ), 1 ),
					std::make_pair( CEdgeModel( 0, 2, 2.9 ), 2 )
					} );
	std::vector < std::pair < CEdgeModel, unsigned int > > node1Neighbors( {
					std::make_pair( CEdgeModel( 1, 3, 2.1 ), 3 )
					} );
	std::vector < std::pair < CEdgeModel, unsigned int > > node2Neighbors( {
					std::make_pair( CEdgeModel( 2, 3, 3.2 ), 3 )
					} );
	squareAdjacencyMap[0] = node0Neighbors;
	squareAdjacencyMap[1] = node1Neighbors;
	squareAdjacencyMap[2] = node2Neighbors;
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
					std::make_pair( infinityModelEdges[2], 3 )
					} );
	std::vector < std::pair < CEdgeModel, unsigned int > > node2Neighbors( {
					std::make_pair( infinityModelEdges[3], 3 )
					} );
	std::vector < std::pair < CEdgeModel, unsigned int > > node3Neighbors( {
					std::make_pair( infinityModelEdges[4], 4 ),
					std::make_pair( infinityModelEdges[5], 5 )
					} );
	std::vector < std::pair < CEdgeModel, unsigned int > > node4Neighbors( {
					std::make_pair( infinityModelEdges[6], 6 )
					} );
	std::vector < std::pair < CEdgeModel, unsigned int > > node5Neighbors( {
					std::make_pair( infinityModelEdges[7], 5 )
					} );
	infinityAdjacencyMap[0] = node0Neighbors;
	infinityAdjacencyMap[1] = node1Neighbors;
	infinityAdjacencyMap[2] = node2Neighbors;
	infinityAdjacencyMap[3] = node3Neighbors;
	infinityAdjacencyMap[4] = node4Neighbors;	
	infinityAdjacencyMap[5] = node5Neighbors;
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
					std::make_pair( turtleModelEdges[1], 2 ),
					std::make_pair( turtleModelEdges[2], 3 )
					} );
	std::vector < std::pair < CEdgeModel, unsigned int > > node2Neighbors( {
					std::make_pair( turtleModelEdges[3], 3 )
					} );
					
	turtleAdjacencyMap[0] = node0Neighbors;
	turtleAdjacencyMap[1] = node1Neighbors;
	turtleAdjacencyMap[2] = node2Neighbors;
}

void CGraphModelFactory::m_CreateDoubleTriangleModelGraph( void )
{
	m_CreateDoubleTriangleModelNodesMap();
	m_CreateDoubleTriangleModelAdjacencyList();
}

void CGraphModelFactory::m_CreateDoubleTriangleModelNodesMap( void )
{
	std::vector < CNodeModel > doubleTriangleModelNodes( {
							CNodeModel( 0, 0, 0 ),
							CNodeModel( 1, 2, 0 ),
							CNodeModel( 2, 4, 0 ),
							CNodeModel( 3, 1, 2 ),
							CNodeModel( 4, 3, 2 ),
							CNodeModel( 5, 2, 4 )
							} );
	for ( auto node : doubleTriangleModelNodes )
	{
		doubleTriangleNodesMap[ node.GetNodeId() ] = node;
	}
}

void CGraphModelFactory::m_CreateDoubleTriangleModelAdjacencyList( void )
{
	std::vector < std::pair < CEdgeModel, unsigned int > > node0Neighbors( {
					std::make_pair( CEdgeModel( 0, 1, 1.7 ), 1 ),
					std::make_pair( CEdgeModel( 0, 3, 2.1 ), 3 )
					} );
	std::vector < std::pair < CEdgeModel, unsigned int > > node1Neighbors( {
					std::make_pair( CEdgeModel( 1, 2, 3.5 ), 2 ),
					std::make_pair( CEdgeModel( 1, 3, 2.3 ), 3 ),
					std::make_pair( CEdgeModel( 1, 4, 1.9 ), 4 )
					} );
	std::vector < std::pair < CEdgeModel, unsigned int > > node2Neighbors( {
					std::make_pair( CEdgeModel( 2, 4, 2.7 ), 4 )
					} );
	std::vector < std::pair < CEdgeModel, unsigned int > > node3Neighbors( {
					std::make_pair( CEdgeModel( 3, 4, 2.3 ), 4 ),
					std::make_pair( CEdgeModel( 3, 5, 2.2 ), 5 )
					} );
	std::vector < std::pair < CEdgeModel, unsigned int > > node4Neighbors( {
					std::make_pair( CEdgeModel( 4, 5, 1.9 ), 5 )
					} );
	doubleTriangleAdjacencyMap[0] = node0Neighbors;
	doubleTriangleAdjacencyMap[1] = node1Neighbors;
	doubleTriangleAdjacencyMap[2] = node2Neighbors;
	doubleTriangleAdjacencyMap[3] = node3Neighbors;
	doubleTriangleAdjacencyMap[4] = node4Neighbors;
}