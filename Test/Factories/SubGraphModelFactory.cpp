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
	squareFrom0To3PathEdges( {
								CNodeModel( 0, 0, 0 ),
								CNodeModel( 1, 0, 2 ),
								CNodeModel( 3, 2, 2 )
								} ),
	squareModelMSTKruskal( new CTreeModel( *( squareGraphModel ), squareModelMSTKruskalEdges ) ),
	squareModelMSTPrim( new CTreeModel( *( squareGraphModel ), squareModelMSTPrimEdges ) ),
	squareModelMSTBoruvka( new CTreeModel( *( squareGraphModel ), squareModelMSTBoruvkaEdges ) ),
	squareFrom0To3Path( new CPathModel( *( squareGraphModel ), squareFrom0To3PathEdges ) ),
	

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
								CNodeModel( 0, 0, 2 ),
								CNodeModel( 1, 2, 4 ),
								CNodeModel( 3, 4, 2 ),
								CNodeModel( 5, 6, 0 ),
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
	infinityFrom0To6PathEdges( { 
								CNodeModel( 0, 0, 2 ),
								CNodeModel( 1, 2, 4 ),
								CNodeModel( 3, 4, 2 ),
								CNodeModel( 5, 6, 0 ),
								CNodeModel( 6, 8, 2 )
								} ),
	infinityModelMSTKruskal( new CTreeModel( *( infinityGraphModel ), infinityModelMSTKruskalEdges ) ),
	infinityModelMSTPrim( new CTreeModel( *( infinityGraphModel ), infinityModelMSTPrimEdges ) ),
	infinityModelMSTBoruvka( new CTreeModel( *( infinityGraphModel ), infinityModelMSTBoruvkaEdges ) ),
	infinityFrom0To6Path( new CPathModel( *( infinityGraphModel ), infinityFrom0To6PathEdges ) ),
	
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
	turtleFrom0To3PathEdges( { 
								CNodeModel( 0, 0, 0 ),
								CNodeModel( 1, 2, 0 ),
								CNodeModel( 2, 4, 2 ),
								CNodeModel( 3, 6, 0 )
								} ),
	turtleModelMSTKruskal( new CTreeModel( *( turtleGraphModel ), turtleModelMSTKruskalEdges ) ),
	turtleModelMSTPrim( new CTreeModel( *( turtleGraphModel ), turtleModelMSTPrimEdges ) ),
	turtleModelMSTBoruvka( new CTreeModel( *( turtleGraphModel ), turtleModelMSTBoruvkaEdges ) ),
	turtleFrom0To3Path( new CPathModel( *( turtleGraphModel ), turtleFrom0To3PathEdges ) ),
	
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
	doubleTriangleFrom0To5PathEdges( { 
								CNodeModel( 0, 0, 0 ),
								CNodeModel( 3, 1, 2 ),
								CNodeModel( 5, 2, 4 )
								} ),
	doubleTriangleFrom2To5PathEdges( { 
								CNodeModel( 2, 4, 0 ),
								CNodeModel( 4, 3, 2 ),
								CNodeModel( 5, 2, 4 )
								} ),

	doubleTriangleModelMSTKruskal( new CTreeModel( *( doubleTriangleGraphModel ), doubleTriangleModelMSTKruskalEdges ) ),
	doubleTriangleModelMSTPrim( new CTreeModel( *( doubleTriangleGraphModel ), doubleTriangleModelMSTPrimEdges ) ),
	doubleTriangleModelMSTBoruvka( new CTreeModel( *( doubleTriangleGraphModel ), doubleTriangleModelMSTBoruvkaEdges ) ),
	doubleTriangleFrom0To5Path( new CPathModel( *( doubleTriangleGraphModel ), doubleTriangleFrom0To5PathEdges ) ),
	doubleTriangleFrom2To5Path( new CPathModel( *( doubleTriangleGraphModel ), doubleTriangleFrom2To5PathEdges ) ),
	
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
	spiderNetFrom0To7PathEdges( { 
								CNodeModel( 0, 0, 2 ),
								CNodeModel( 2, 2, 0 ),
								CNodeModel( 3, 4, 2 ),
								CNodeModel( 6, 8, 2 ),
								CNodeModel( 5, 6, 4 ),
								CNodeModel( 7, 10, 4 )
								} ),
	spiderNetFrom5To0PathEdges( { 
								CNodeModel( 5, 6, 4 ),
								CNodeModel( 6, 8, 2 ),
								CNodeModel( 3, 4, 2 ),
								CNodeModel( 2, 2, 0 ),
								CNodeModel( 0, 0, 2 )
								} ),
	spiderNetFrom5To0PathEdgesBellmanFord( { 
								CNodeModel( 0, 0, 2 ),
								CNodeModel( 2, 2, 0 ),
								CNodeModel( 3, 4, 2 ),
								CNodeModel( 6, 8, 2 ),
								CNodeModel( 5, 6, 4 )
								} ),
	spiderNetModelMSTKruskal( new CTreeModel( *( spiderNetGraphModel ), spiderNetModelMSTKruskalEdges ) ),
	spiderNetModelMSTPrim( new CTreeModel( *( spiderNetGraphModel ), spiderNetModelMSTPrimEdges ) ),
	spiderNetModelMSTBoruvka( new CTreeModel( *( spiderNetGraphModel ), spiderNetModelMSTBoruvkaEdges ) ),
	spiderNetFrom0To7Path( new CPathModel( *( spiderNetGraphModel ), spiderNetFrom0To7PathEdges ) ),
	spiderNetFrom5To0Path( new CPathModel( *( spiderNetGraphModel ), spiderNetFrom5To0PathEdges ) ),
	spiderNetFrom5To0PathBellmanFord( new CPathModel( *( spiderNetGraphModel ), spiderNetFrom5To0PathEdgesBellmanFord ) ),
	
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
	grapeFrom0To16PathEdges( {
								CNodeModel( 0, 2, 0 ),
								CNodeModel( 2, 0, 2 ),
								CNodeModel( 3, 2, 4 ),
								CNodeModel( 6, 5, 6 ),
								CNodeModel( 11, 6, 8 ),
								CNodeModel( 14, 10, 10 ),
								CNodeModel( 15, 12, 12 ),
								CNodeModel( 16, 13, 14 )
								} ),
	grapeFrom9To13PathEdges( {
								CNodeModel( 9, 2, 10 ),
								CNodeModel( 10, 4, 10 ),
								CNodeModel( 14, 10, 10 ),
								CNodeModel( 13, 12, 9 )
								} ),
	grapeModelMSTKruskal( new CTreeModel( *( grapeGraphModel ), grapeModelMSTKruskalEdges ) ),
	grapeModelMSTPrim( new CTreeModel( *( grapeGraphModel ), grapeModelMSTPrimEdges ) ),
	grapeModelMSTBoruvka( new CTreeModel( *( grapeGraphModel ), grapeModelMSTBoruvkaEdges ) ),
	grapeFrom0To16Path( new CPathModel( *( grapeGraphModel ), grapeFrom0To16PathEdges ) ),
	grapeFrom9To13Path( new CPathModel( *( grapeGraphModel ), grapeFrom9To13PathEdges ) )
{
	
}

CSubGraphModelFactory::~CSubGraphModelFactory( void )
{
	
}
