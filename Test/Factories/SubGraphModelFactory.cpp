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
	squareModelMSTKruskalEdges( { 
								std::make_pair( 1, 3 ),
								std::make_pair( 0, 2 ),
								std::make_pair( 2, 3 )
								} ),
	squareModelMSTPrimEdges( { 
								std::make_pair( 0, 2 ),
								std::make_pair( 2, 3 ),
								std::make_pair( 1, 3 )
								} ),
	squareModelMSTBoruvkaEdges( { 
								std::make_pair( 0, 2 ),
								std::make_pair( 1, 3 ),
								std::make_pair( 2, 3 )
								} ),
	squareModelMSTKruskal( new CTreeModel( *( squareGraphModel ), squareModelMSTKruskalEdges ) ),
	squareModelMSTPrim( new CTreeModel( *( squareGraphModel ), squareModelMSTPrimEdges ) ),
	squareModelMSTBoruvka( new CTreeModel( *( squareGraphModel ), squareModelMSTBoruvkaEdges ) ),
	

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
								std::make_pair( 5, 6 ),
								std::make_pair( 0, 2 )
								} ),
	infinityModelMSTPrimEdges( { 
								std::make_pair( 0, 1 ),
								std::make_pair( 1, 3 ),
								std::make_pair( 3, 5 ),
								std::make_pair( 5, 6 ),
								std::make_pair( 4, 6 ),
								std::make_pair( 0, 2 )
								} ),
	infinityModelMSTBoruvkaEdges( { 
								std::make_pair( 0, 1 ),
								std::make_pair( 0, 2 ),
								std::make_pair( 4, 6 ),
								std::make_pair( 3, 5 ),
								std::make_pair( 5, 6 ),
								std::make_pair( 1, 3 )								
								} ),
	infinityModelMSTKruskal( new CTreeModel( *( infinityGraphModel ), infinityModelMSTKruskalEdges ) ),
	infinityModelMSTPrim( new CTreeModel( *( infinityGraphModel ), infinityModelMSTPrimEdges ) ),
	infinityModelMSTBoruvka( new CTreeModel( *( infinityGraphModel ), infinityModelMSTBoruvkaEdges ) ),
	
	turtleModelEdgeDefinition( {
								std::make_pair( 0, 1 ),
								std::make_pair( 1, 3 ),
								std::make_pair( 2, 3 )
								} ),
	turtleModelMSTKruskalEdges( { 
								std::make_pair( 2, 3 ),
								std::make_pair( 0, 1 ),
								std::make_pair( 1, 2 )
								} ),
	turtleModelMSTPrimEdges( { 
								std::make_pair( 0, 1 ),
								std::make_pair( 1, 2 ),
								std::make_pair( 2, 3 )
								} ),
	turtleModelMSTBoruvkaEdges( { 
								std::make_pair( 0, 1 ),
								std::make_pair( 2, 3 ),
								std::make_pair( 1, 2 )								
								} ),
	turtleModelMSTKruskal( new CTreeModel( *( turtleGraphModel ), turtleModelMSTKruskalEdges ) ),
	turtleModelMSTPrim( new CTreeModel( *( turtleGraphModel ), turtleModelMSTPrimEdges ) ),
	turtleModelMSTBoruvka( new CTreeModel( *( turtleGraphModel ), turtleModelMSTBoruvkaEdges ) ),
	
	doubleTriangleModelEdgeDefinition( {
								std::make_pair( 0, 1 ),
								std::make_pair( 0, 3 ),
								std::make_pair( 1, 2 )
								} ),
	doubleTriangleModelMSTKruskalEdges( { 
								std::make_pair( 0, 1 ),
								std::make_pair( 1, 4 ),
								std::make_pair( 4, 5 ),
								std::make_pair( 0, 3 ),
								std::make_pair( 2, 4 )
								} ),
	doubleTriangleModelMSTPrimEdges( { 
								std::make_pair( 0, 1 ),
								std::make_pair( 1, 4 ),
								std::make_pair( 4, 5 ),
								std::make_pair( 0, 3 ),
								std::make_pair( 2, 4 )
								} ),
	doubleTriangleModelMSTBoruvkaEdges( { 
								std::make_pair( 0, 1 ),
								std::make_pair( 2, 4 ),
								std::make_pair( 0, 3 ),
								std::make_pair( 1, 4 ),
								std::make_pair( 4, 5 )
								} ),
	doubleTriangleModelMSTKruskal( new CTreeModel( *( doubleTriangleGraphModel ), doubleTriangleModelMSTKruskalEdges ) ),
	doubleTriangleModelMSTPrim( new CTreeModel( *( doubleTriangleGraphModel ), doubleTriangleModelMSTPrimEdges ) ),
	doubleTriangleModelMSTBoruvka( new CTreeModel( *( doubleTriangleGraphModel ), doubleTriangleModelMSTBoruvkaEdges ) ),
	
	spiderNetModelMSTKruskalEdges( { 
								std::make_pair( 0, 2 ),
								std::make_pair( 1, 3 ),
								std::make_pair( 2, 3 ),
								std::make_pair( 5, 6 ),
								std::make_pair( 3, 6 ),
								std::make_pair( 5, 7 ),
								std::make_pair( 3, 4 )
								} ),
	spiderNetModelMSTPrimEdges( { 
								std::make_pair( 0, 2 ),
								std::make_pair( 2, 3 ),
								std::make_pair( 1, 3 ),
								std::make_pair( 3, 6 ),
								std::make_pair( 5, 6 ),
								std::make_pair( 5, 7 ),
								std::make_pair( 3, 4 )
								} ),
	spiderNetModelMSTBoruvkaEdges( { 
								std::make_pair( 0, 2 ),
								std::make_pair( 1, 3 ),
								std::make_pair( 3, 4 ),
								std::make_pair( 5, 6 ),
								std::make_pair( 2, 3 ),
								std::make_pair( 5, 7 ),
								std::make_pair( 3, 6 )
								} ),
	spiderNetModelMSTKruskal( new CTreeModel( *( spiderNetGraphModel ), spiderNetModelMSTKruskalEdges ) ),
	spiderNetModelMSTPrim( new CTreeModel( *( spiderNetGraphModel ), spiderNetModelMSTPrimEdges ) ),
	spiderNetModelMSTBoruvka( new CTreeModel( *( spiderNetGraphModel ), spiderNetModelMSTBoruvkaEdges ) ),
	
	grapeModelMSTKruskalEdges( {
								std::make_pair( 0, 1 ),
								std::make_pair( 3, 6 ),
								std::make_pair( 13, 14 ),
								std::make_pair( 2, 3 ),
								std::make_pair( 8, 9 ),
								std::make_pair( 6, 11 ),
								std::make_pair( 12, 13 ),
								std::make_pair( 15, 16 ),
								std::make_pair( 3, 7 ),
								std::make_pair( 9, 10 ),
								std::make_pair( 0, 2 ),
								std::make_pair( 4, 5 ),
								std::make_pair( 7, 8 ),
								std::make_pair( 5, 12 ),
								std::make_pair( 10, 14 ),
								std::make_pair( 17, 16 ),
								std::make_pair( 14, 17 )
								} ),
	grapeModelMSTPrimEdges( {
								std::make_pair( 0, 1 ),
								std::make_pair( 0, 2 ),
								std::make_pair( 2, 3 ),
								std::make_pair( 3, 6 ),
								std::make_pair( 6, 11 ),
								std::make_pair( 3, 7 ),
								std::make_pair( 7, 8 ),
								std::make_pair( 8, 9 ),
								std::make_pair( 9, 10 ),
								std::make_pair( 10, 14 ),
								std::make_pair( 13, 14 ),
								std::make_pair( 12, 13 ),
								std::make_pair( 5, 12 ),
								std::make_pair( 4, 5 ),
								std::make_pair( 14, 17 ),
								std::make_pair( 17, 16 ),
								std::make_pair( 15, 16 )
								} ),
	grapeModelMSTBoruvkaEdges( {
								std::make_pair( 0, 1 ),
								std::make_pair( 2, 3 ),
								std::make_pair( 4, 5 ),
								std::make_pair( 3, 6 ),
								std::make_pair( 8, 9 ),
								std::make_pair( 9, 10 ),
								std::make_pair( 12, 13 ),
								std::make_pair( 13, 14 ),
								std::make_pair( 15, 16 ),
								std::make_pair( 0, 2 ),
								std::make_pair( 5, 12 ),
								std::make_pair( 3, 7 ),
								std::make_pair( 6, 11 ),
								std::make_pair( 17, 16 ),
								std::make_pair( 14, 17 ),
								std::make_pair( 7, 8 ),
								std::make_pair( 10, 14 )
								} ),
	grapeModelMSTKruskal( new CTreeModel( *( grapeGraphModel ), grapeModelMSTKruskalEdges ) ),
	grapeModelMSTPrim( new CTreeModel( *( grapeGraphModel ), grapeModelMSTPrimEdges ) ),
	grapeModelMSTBoruvka( new CTreeModel( *( grapeGraphModel ), grapeModelMSTBoruvkaEdges ) )
{
	
}

CSubGraphModelFactory::~CSubGraphModelFactory( void )
{
	
}
