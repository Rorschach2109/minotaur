/*
 * This file is part of minotaur.
 *
 * File: GraphDTOFactory.cpp
 * Brief: Implementation of graph dto factory class.
 *
 * Date: 28.07.2013
 * Author: Andrzej Korycinski
 * 
 * */
 
#include "GraphDTOFactory.h"

using namespace Minotaur;

CGraphDtoFactory::CGraphDtoFactory( void ) :
	
	squareDtoNodes( {
					CNodeDto( 0, 0, 0 ),
					CNodeDto( 1, 0, 2 ),
					CNodeDto( 2, 2, 0 ),
					CNodeDto( 3, 2, 2 ) 
					} ),
	squareDtoEdges( {
					CEdgeDto( 0, 1, 3.7 ),
					CEdgeDto( 0, 2, 2.9 ),
					CEdgeDto( 1, 3, 2.1 ),
					CEdgeDto( 2, 3, 3.2 )
					} ),
	squareName( "Square" ),
	squareDtoGraph(
					CGraphDto( squareName, squareDtoNodes, squareDtoEdges )
					),
	squareDtoGraphString( 
						"Square\n\n"
						
						"4\t4\n\n"
						
						"0\t0\t0\n"
						"1\t0\t2\n"
						"2\t2\t0\n"
						"3\t2\t2\n\n"
						
						"0\t1\t3.7\n"
						"0\t2\t2.9\n"
						"1\t3\t2.1\n"
						"2\t3\t3.2\n\n"
						),
	
	infinityDtoNodes( {
					CNodeDto( 0, 0, 2 ),
					CNodeDto( 1, 2, 4 ),
					CNodeDto( 2, 2, 0 ),
					CNodeDto( 3, 4, 2 ),
					CNodeDto( 4, 6, 4 ),
					CNodeDto( 5, 6, 0 ),
					CNodeDto( 6, 8, 2 )
					} ),
	infinityDtoEdges( {
					CEdgeDto( 0, 1, 1.7 ),
					CEdgeDto( 0, 2, 2.3 ),
					CEdgeDto( 1, 3, 1.9 ),
					CEdgeDto( 2, 3, 2.6 ),
					CEdgeDto( 3, 4, 3.1 ),
					CEdgeDto( 3, 5, 1.2 ),
					CEdgeDto( 4, 6, 1.8 ),
					CEdgeDto( 5, 6, 2.1 )
					} ),
	infinityName( "Infinity" ),
	infinityDtoGraph(
					CGraphDto( infinityName, infinityDtoNodes, infinityDtoEdges )
					),
	infinityDtoGraphString( 
							"Infinity\n\n"
							
							"7\t8\n\n"
							
							"0\t0\t0\t2\n"
							"1\t2\t4\n"
							"2\t2\t0\n"
							"3\t4\t2\n"
							"4\t6\t4\n"
							"5\t6\t0\n"
							"6\t8\t2\n\n"
							
							"0\t1\t1.7\n"
							"0\t2\t2.3\n"
							"1\t3\t1.9\n"
							"2\t3\t2.6\n"
							"3\t4\t3.1\n"
							"3\t5\t1.2\n"
							"4\t6\t1.8\n"
							"5\t6\t2.1\n\n"
							),
	
	turtleDtoNodes( {
					CNodeDto( 0, 0, 0 ),
					CNodeDto( 1, 2, 0 ),
					CNodeDto( 2, 4, 2 ),
					CNodeDto( 3, 6, 0 )
					} ),
	turtleDtoEdges( {
					CEdgeDto( 0, 1, 2.1 ),
					CEdgeDto( 1, 2, 2.5 ),  
					CEdgeDto( 1, 3, 4.2 ),
					CEdgeDto( 2, 3, 1.2 )
					} ),
	turtleName( "Turtle" ),
	turtleDtoGraph(
					CGraphDto( turtleName, turtleDtoNodes, turtleDtoEdges )  
					),
	turtleDtoGraphString( 
						"Turtle\n\n"
						
						"4\t4\n"

						"0\t0\t0\n"
						"1\t2\t0\n"
						"2\t4\t2\n"
						"3\t6\t0\n\n"

						"0\t1\t2.1\n"
						"1\t2\t2.5\n"
						"1\t3\t4.2\n"
						"2\t3\t1.2\n\n"
						),
	
	doubleTriangleDtoNodes( {
							CNodeDto( 0, 0, 0 ),
							CNodeDto( 1, 2, 0 ),
							CNodeDto( 2, 4, 0 ),
							CNodeDto( 3, 1, 2 ),
							CNodeDto( 4, 3, 2 ),
							CNodeDto( 5, 2, 4 )
							} ),
	doubleTriangleDtoEdges( {
							CEdgeDto( 0, 1, 1.7 ),
							CEdgeDto( 0, 3, 2.1 ),
							CEdgeDto( 1, 2, 3.5 ),
							CEdgeDto( 1, 3, 2.3 ),
							CEdgeDto( 1, 4, 1.9 ),
							CEdgeDto( 2, 4, 2.7 ),
							CEdgeDto( 3, 4, 2.3 ),
							CEdgeDto( 3, 5, 2.2 ),
							CEdgeDto( 4, 5, 1.9 )
							} ),
	doubleTriangleName( "Double Triangle" ),
	doubleTriangleDtoGraph(
							CGraphDto( doubleTriangleName, doubleTriangleDtoNodes, doubleTriangleDtoEdges )
							),
	doubleTriangleDtoGraphString( 
								"Double Triangle\n\n"
								
								"6\t9\n\n"
								
								"0\t0\t0\n"
								"1\t2\t0\n"
								"2\t4\t0\n"
								"3\t1\t2\n"
								"4\t3\t2\n"
								"5\t2\t4\n\n"
								
								"0\t1\t1.7\n"
								"0\t3\t2.1\n"
								"1\t2\t3.5\n"
								"1\t3\t2.3\n"
								"1\t4\t1.9\n"
								"2\t4\t2.7\n"
								"3\t4\t2.3\n"
								"3\t5\t2.2\n"
								"4\t5\t1.9\n\n"
								)
{
	
}

CGraphDtoFactory::~CGraphDtoFactory( void )
{
	
}