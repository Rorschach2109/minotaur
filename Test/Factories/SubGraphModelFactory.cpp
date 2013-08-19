/*
 * This file is part of minotaur.
 *
 * File: SubGraphModelFactory.cpp
 * Brief: Implementation of subgraph model factory class.
 *
 * Date: 15.08.2013
 * Author: Andrzej Korycinski
 * 
 * */

#include "SubGraphModelFactory.h"

using namespace Minotaur;

CSubGraphModelFactory::CSubGraphModelFactory( void ) : 
	CGraphModelFactory(),
	
	squareModelEdgeDefinition( {
								std::make_pair( 0, 1 ),
								std::make_pair( 0, 2 ),
								std::make_pair( 1, 3 )
								} ),
	suqareModelMSTKruskalEdges( { 
								std::make_pair( 1, 3 ),
								std::make_pair( 0, 2 ),
								std::make_pair( 2, 3 )
								} ),
	suqareModelMSTKruskal( new CTreeModel( *( squareGraphModel ), suqareModelMSTKruskalEdges ) ),
	

	infinityModelEdgeDefinition( {
								std::make_pair( 0, 1 ),
								std::make_pair( 1, 3 ),
								std::make_pair( 2, 3 ),
								std::make_pair( 3, 4 ),
								std::make_pair( 4, 6 ),
								std::make_pair( 5, 6 )
								} ),
	infinitySubGraphModelEdges( {
								CEdgeModel( 0, 1, 1.7 ),
								CEdgeModel( 1, 3, 1.9 ),
								CEdgeModel( 2, 3, 2.6 ),
								CEdgeModel( 3, 4, 3.1 ),
								CEdgeModel( 4, 6, 1.8 ),
								CEdgeModel( 5, 6, 2.1 )
								} ),
	infinityNode1Neighbors( { 
								CNodeModel( 2, 2, 0 )
								} ),
	infinityPath0To5( { 
								std::make_pair( 0, 1 ),
								std::make_pair( 1, 3 ),
								std::make_pair( 3, 5 )
								} ),
	infinityModelMSTKruskalEdges( { 
								std::make_pair( 3, 5 ),
								std::make_pair( 0, 1 ),
								std::make_pair( 4, 6 ),
								std::make_pair( 1, 3 ),
								std::make_pair( 0, 2 ),
								std::make_pair( 5, 6 )
								} ),
	infinityModelMSTKruskal( new CTreeModel( *( infinityGraphModel ), infinityModelMSTKruskalEdges ) ),
	
	turtleModelEdgeDefinition( {
								std::make_pair( 0, 1 ),
								std::make_pair( 1, 3 ),
								std::make_pair( 2, 3 )
								} ),
	turtleModelMSTKruskalEdges( { 
								std::make_pair( 1, 3 ),
								std::make_pair( 0, 1 ),
								std::make_pair( 1, 2 )
								} ),
	turtleModelMSTKruskal( new CTreeModel( *( turtleGraphModel ), turtleModelMSTKruskalEdges ) ),
	
	doubleTriangleModelEdgeDefinition( {
								std::make_pair( 0, 1 ),
								std::make_pair( 0, 3 ),
								std::make_pair( 1, 2 )
								} ),
	doubleTriangleModelMSTKruskalEdges( { 
								std::make_pair( 3, 5 ),
								std::make_pair( 0, 1 ),
								std::make_pair( 4, 6 ),
								std::make_pair( 1, 3 ),
								std::make_pair( 0, 2 ),
								std::make_pair( 5, 6 )
								} ),
	doubleTriangleModelMSTKruskal( new CTreeModel( *( doubleTriangleGraphModel ), doubleTriangleModelMSTKruskalEdges ) ),
	
	largeModelMSTKruskalEdges( { 
								std::make_pair( 0, 2 ),
								std::make_pair( 2, 3 ),
								std::make_pair( 1, 3 ),
								std::make_pair( 3, 4 ),
								std::make_pair( 3, 6 ),
								std::make_pair( 5, 6 ),
								std::make_pair( 5, 7 )
								} ),
	largeModelMSTKruskal( new CTreeModel( *( largeGraphModel ), largeModelMSTKruskalEdges ) )
{
	
}

CSubGraphModelFactory::~CSubGraphModelFactory( void )
{
	
}
