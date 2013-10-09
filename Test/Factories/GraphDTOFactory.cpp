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
	squareDotGraphString(
						"graph Square\n"
						"{\n"
							"\tgraph[center = true, margin = 0.2, nodesep = 0.1, ranksep = 0.3];\n"
							"\tnode[shape = circle, fontsize = 8];\n"
							"\tedge[arrowsize = 0.6, fontsize = 8];\n\n"

							"\t0 [pos = \" 0, 0 \"];\n"
							"\t1 [pos = \" 0, 2 \"];\n"
							"\t2 [pos = \" 2, 0 \"];\n"
							"\t3 [pos = \" 2, 2 \"];\n\n"

							"\t0 -- 1 [label = \" 3.7 \"];\n"
							"\t0 -- 2 [label = \" 2.9 \"];\n"
							"\t1 -- 3 [label = \" 2.1 \"];\n"
							"\t2 -- 3 [label = \" 3.2 \"];\n"
						"}\n"
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
							
							"0\t0\t2\n"
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
	infinityDotGraphString(
			"graph Infinity\n"
			"{\n"
				"\tgraph[center = true, margin = 0.2, nodesep = 0.1, ranksep = 0.3];\n"
				"\tnode[shape = circle, fontsize = 8];\n"
				"\tedge[arrowsize = 0.6, fontsize = 8];\n\n"

				"\t0 [pos = \" 0, 2 \"];\n"
				"\t1 [pos = \" 2, 4 \"];\n"
				"\t2 [pos = \" 2, 0 \"];\n"
				"\t3 [pos = \" 4, 2 \"];\n"
				"\t4 [pos = \" 6, 4 \"];\n"
				"\t5 [pos = \" 6, 0 \"];\n"
				"\t6 [pos = \" 8, 2 \"];\n\n"

				"\t0 -- 1 [label = \" 1.7 \"];\n"
				"\t0 -- 2 [label = \" 2.3 \"];\n"
				"\t1 -- 3 [label = \" 1.9 \"];\n"
				"\t2 -- 3 [label = \" 2.6 \"];\n"
				"\t3 -- 4 [label = \" 3.1 \"];\n"
				"\t3 -- 5 [label = \" 1.2 \"];\n"
				"\t4 -- 6 [label = \" 1.8 \"];\n"
				"\t5 -- 6 [label = \" 2.1 \"];\n"
			"}\n"
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
						
						"4\t4\n\n"

						"0\t0\t0\n"
						"1\t2\t0\n"
						"2\t4\t2\n"
						"3\t6\t0\n\n"

						"0\t1\t2.1\n"
						"1\t2\t2.5\n"
						"1\t3\t4.2\n"
						"2\t3\t1.2\n\n"
						),
	turtleDotGraphString(
						"graph Turtle\n"
						"{\n"
							"\tgraph[center = true, margin = 0.2, nodesep = 0.1, ranksep = 0.3];\n"
							"\tnode[shape = circle, fontsize = 8];\n"
							"\tedge[arrowsize = 0.6, fontsize = 8];\n\n"

							"\t0 [pos = \" 0, 0 \"];\n"
							"\t1 [pos = \" 2, 0 \"];\n"
							"\t2 [pos = \" 4, 2 \"];\n"
							"\t3 [pos = \" 6, 0 \"];\n\n"

							"\t0 -- 1 [label = \" 2.1 \"];\n"
							"\t1 -- 2 [label = \" 2.5 \"];\n"
							"\t1 -- 3 [label = \" 4.2 \"];\n"
							"\t2 -- 3 [label = \" 1.2 \"];\n"
						"}\n"
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
	doubleTriangleName( "DoubleTriangle" ),
	doubleTriangleDtoGraph(
							CGraphDto( doubleTriangleName, doubleTriangleDtoNodes, doubleTriangleDtoEdges )
							),
	doubleTriangleDtoGraphString( 
								"DoubleTriangle\n\n"
								
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
								),
	doubleTriangleDotGraphString(
								"graph DoubleTriangle\n"
								"{\n"
									"\tgraph[center = true, margin = 0.2, nodesep = 0.1, ranksep = 0.3];\n"
									"\tnode[shape = circle, fontsize = 8];\n"
									"\tedge[arrowsize = 0.6, fontsize = 8];\n\n"

									"\t0 [pos = \" 0, 0 \"];\n"
									"\t1 [pos = \" 2, 0 \"];\n"
									"\t2 [pos = \" 4, 0 \"];\n"
									"\t3 [pos = \" 1, 2 \"];\n"
									"\t4 [pos = \" 3, 2 \"];\n"
									"\t5 [pos = \" 2, 4 \"];\n\n"

									"\t0 -- 1 [label = \" 1.7 \"];\n"
									"\t0 -- 3 [label = \" 2.1 \"];\n"
									"\t1 -- 2 [label = \" 3.5 \"];\n"
									"\t1 -- 3 [label = \" 2.3 \"];\n"
									"\t1 -- 4 [label = \" 1.9 \"];\n"
									"\t2 -- 4 [label = \" 2.7 \"];\n"
									"\t3 -- 4 [label = \" 2.3 \"];\n"
									"\t3 -- 5 [label = \" 2.2 \"];\n"
									"\t4 -- 5 [label = \" 1.9 \"];\n"
								"}\n"
								),

	spiderNetDtoNodes( {
						CNodeDto( 0, 0, 2 ),
						CNodeDto( 1, 2, 4 ),
						CNodeDto( 2, 2, 0 ),
						CNodeDto( 3, 4, 2 ),
						CNodeDto( 4, 6, 0 ),
						CNodeDto( 5, 6, 4 ),
						CNodeDto( 6, 8, 2 ),
						CNodeDto( 7, 10, 4 )
						} ),
	spiderNetDtoEdges( {
						CEdgeDto( 0, 1, 3.0 ),
						CEdgeDto( 0, 2, 2.0 ),
						CEdgeDto( 0, 3, 5.0 ),
						CEdgeDto( 1, 3, 2.0 ),
						CEdgeDto( 1, 5, 13.0 ),
						CEdgeDto( 2, 3, 2.0 ),
						CEdgeDto( 2, 4, 5.0 ),
						CEdgeDto( 3, 4, 4.0 ),
						CEdgeDto( 3, 6, 3.0 ),
						CEdgeDto( 4, 6, 6.0 ),
						CEdgeDto( 5, 6, 2.0 ),
						CEdgeDto( 5, 7, 3.0 ),
						CEdgeDto( 6, 7, 6.0 )
						} ),
	spiderNetName( "SpiderNet" ),
	spiderNetDtoGraph(
			CGraphDto( spiderNetName, spiderNetDtoNodes, spiderNetDtoEdges )
			),
	spiderNetDtoGraphString(
							"SpiderNet\n\n"

							"8\t13\n\n"

							"0\t0\t2\n"
							"1\t2\t4\n"
							"2\t2\t0\n"
							"3\t4\t2\n"
							"4\t6\t0\n"
							"5\t6\t4\n"
							"6\t8\t2\n"
							"7\t10\t4\n\n"

							"0\t1\t3.0\n"
							"0\t2\t2.0\n"
							"0\t3\t5.0\n"
							"1\t3\t2.0\n"
							"1\t5\t13.0\n"
							"2\t3\t2.0\n"
							"2\t4\t5.0\n"
							"3\t4\t4.0\n"
							"3\t6\t3.0\n"
							"4\t6\t6.0\n"
							"5\t6\t2.0\n"
							"5\t7\t3.0\n"
							"6\t7\t6.0\n\n"
							),
	spiderNetDotGraphString(
							"graph SpiderNet\n"
							"{\n"
								"\tgraph[center = true, margin = 0.2, nodesep = 0.1, ranksep = 0.3];\n"
								"\tnode[shape = circle, fontsize = 8];\n"
								"\tedge[arrowsize = 0.6, fontsize = 8];\n\n"

								"\t0 [pos = \" 0, 2 \"];\n"
								"\t1 [pos = \" 2, 4 \"];\n"
								"\t2 [pos = \" 2, 0 \"];\n"
								"\t3 [pos = \" 4, 2 \"];\n"
								"\t4 [pos = \" 6, 0 \"];\n"
								"\t5 [pos = \" 6, 4 \"];\n"
								"\t6 [pos = \" 8, 2 \"];\n"
								"\t7 [pos = \" 10, 4 \"];\n\n"

								"\t0 -- 1 [label = \" 3.0 \"];\n"
								"\t0 -- 2 [label = \" 2.0 \"];\n"
								"\t0 -- 3 [label = \" 5.0 \"];\n"
								"\t1 -- 3 [label = \" 2.0 \"];\n"
								"\t1 -- 5 [label = \" 13.0 \"];\n"
								"\t2 -- 3 [label = \" 2.0 \"];\n"
								"\t2 -- 4 [label = \" 5.0 \"];\n"
								"\t3 -- 4 [label = \" 4.0 \"];\n"
								"\t3 -- 6 [label = \" 3.0 \"];\n"
								"\t4 -- 6 [label = \" 6.0 \"];\n"
								"\t5 -- 6 [label = \" 2.0 \"];\n"
								"\t5 -- 7 [label = \" 3.0 \"];\n"
								"\t6 -- 7 [label = \" 6.0 \"];\n"
							"}\n"
							),

	grapeDtoNodes( {
					CNodeDto( 0, 2, 0 ),
					CNodeDto( 1, 4, 2 ),
					CNodeDto( 2, 0, 2 ),
					CNodeDto( 3, 2, 4 ),
					CNodeDto( 4, 6, 4 ),
					CNodeDto( 5, 8, 6 ),
					CNodeDto( 6, 5, 6 ),
					CNodeDto( 7, 1, 6 ),
					CNodeDto( 8, 2, 8 ),
					CNodeDto( 9, 2, 10 ),
					CNodeDto( 10, 4, 10 ),
					CNodeDto( 11, 6, 8 ),
					CNodeDto( 12, 10, 8 ),
					CNodeDto( 13, 12, 9 ),
					CNodeDto( 14, 10, 10 ),
					CNodeDto( 15, 12, 12 ),
					CNodeDto( 16, 13, 14 ),
					CNodeDto( 17, 13, 12 )
					} ),
	grapeDtoEdges( {
					CEdgeDto( 0, 1, 2.0 ),
					CEdgeDto( 0, 2, 5.0 ),
					CEdgeDto( 1, 3, 8.0 ),
					CEdgeDto( 1, 4, 6.0 ),
					CEdgeDto( 2, 3, 3.0 ),
					CEdgeDto( 3, 6, 2.0 ),
					CEdgeDto( 3, 7, 4.0 ),
					CEdgeDto( 4, 5, 5.0 ),
					CEdgeDto( 4, 6, 6.0 ),
					CEdgeDto( 5, 11, 6.0 ),
					CEdgeDto( 5, 12, 5.0 ),
					CEdgeDto( 6, 8, 6.0 ),
					CEdgeDto( 6, 11, 3.0 ),
					CEdgeDto( 7, 8, 5.0 ),
					CEdgeDto( 8, 9, 3.0 ),
					CEdgeDto( 8, 10, 6.0 ),
					CEdgeDto( 9, 10, 4.0 ),
					CEdgeDto( 10, 14, 5.0 ),
					CEdgeDto( 11, 10, 6.0 ),
					CEdgeDto( 11, 14, 7.0 ),
					CEdgeDto( 12, 13, 3.0 ),
					CEdgeDto( 12, 14, 4.0 ),
					CEdgeDto( 13, 14, 2.0 ),
					CEdgeDto( 14, 15, 9.0 ),
					CEdgeDto( 14, 17, 8.0 ),
					CEdgeDto( 15, 16, 3.0 ),
					CEdgeDto( 17, 16, 5.0 )
					} ),
	grapeName( "Grape" ),
	grapeDtoGraph(
			CGraphDto( grapeName, grapeDtoNodes, grapeDtoEdges )
			),
	grapeDtoGraphString(
						"Grape\n\n"

						"18\t27\n\n"

						"0\t2\t0\n"
						"1\t4\t2\n"
						"2\t0\t2\n"
						"3\t2\t4\n"
						"4\t6\t4\n"
						"5\t8\t6\n"
						"6\t5\t6\n"
						"7\t1\t6\n"
						"8\t2\t8\n"
						"9\t2\t10\n"
						"10\t4\t10\n"
						"11\t6\t8\n"
						"12\t10\t8\n"
						"13\t12\t9\n"
						"14\t10\t10\n"
						"15\t12\t12\n"
						"16\t13\t14\n"
						"17\t13\t12\n\n"

						"0\t1\t2.0\n"
						"0\t2\t5.0\n"
						"1\t3\t8.0\n"
						"1\t4\t6.0\n"
						"2\t3\t3.0\n"
						"3\t6\t2.0\n"
						"3\t7\t4.0\n"
						"4\t5\t5.0\n"
						"4\t6\t6.0\n"
						"5\t11\t6.0\n"
						"5\t12\t5.0\n"
						"6\t8\t6.0\n"
						"6\t11\t3.0\n"
						"7\t8\t5.0\n"
						"8\t9\t3.0\n"
						"8\t10\t6.0\n"
						"9\t10\t4.0\n"
						"10\t14\t5.0\n"
						"11\t10\t6.0\n"
						"11\t14\t7.0\n"
						"12\t13\t3.0\n"
						"12\t14\t4.0\n"
						"13\t14\t2.0\n"
						"14\t15\t9.0\n"
						"14\t17\t8.0\n"
						"15\t16\t3.0\n"
						"17\t16\t5.0\n\n"
						),
		grapeDotGraphString(
				"graph Grape\n"
				"{\n"
					"\tgraph[center = true, margin = 0.2, nodesep = 0.1, ranksep = 0.3];\n"
					"\tnode[shape = circle, fontsize = 8];\n"
					"\tedge[arrowsize = 0.6, fontsize = 8];\n\n"

					"\t0 [pos = \" 2, 0 \"];\n"
					"\t1 [pos = \" 4, 2 \"];\n"
					"\t2 [pos = \" 0, 2 \"];\n"
					"\t3 [pos = \" 2, 4 \"];\n"
					"\t4 [pos = \" 6, 4 \"];\n"
					"\t5 [pos = \" 8, 6 \"];\n"
					"\t6 [pos = \" 5, 6 \"];\n"
					"\t7 [pos = \" 1, 6 \"];\n"
					"\t8 [pos = \" 2, 8 \"];\n"
					"\t9 [pos = \" 2, 10 \"];\n"
					"\t10 [pos = \" 4, 10 \"];\n"
					"\t11 [pos = \" 6, 8 \"];\n"
					"\t12 [pos = \" 10, 8 \"];\n"
					"\t13 [pos = \" 12, 9 \"];\n"
					"\t14 [pos = \" 10, 10 \"];\n"
					"\t15 [pos = \" 12, 12 \"];\n"
					"\t16 [pos = \" 13, 14 \"];\n"
					"\t17 [pos = \" 13, 12 \"];\n\n"

					"\t0 -- 1 [label = \" 2.0 \"];\n"
					"\t0 -- 2 [label = \" 5.0 \"];\n"
					"\t1 -- 3 [label = \" 8.0 \"];\n"
					"\t1 -- 4 [label = \" 6.0 \"];\n"
					"\t2 -- 3 [label = \" 3.0 \"];\n"
					"\t3 -- 6 [label = \" 2.0 \"];\n"
					"\t3 -- 7 [label = \" 4.0 \"];\n"
					"\t4 -- 5 [label = \" 5.0 \"];\n"
					"\t4 -- 6 [label = \" 6.0 \"];\n"
					"\t5 -- 11 [label = \" 6.0 \"];\n"
					"\t5 -- 12 [label = \" 5.0 \"];\n"
					"\t6 -- 8 [label = \" 6.0 \"];\n"
					"\t6 -- 11 [label = \" 3.0 \"];\n"
					"\t7 -- 8 [label = \" 5.0 \"];\n"
					"\t8 -- 9 [label = \" 3.0 \"];\n"
					"\t8 -- 10 [label = \" 6.0 \"];\n"
					"\t9 -- 10 [label = \" 4.0 \"];\n"
					"\t10 -- 14 [label = \" 5.0 \"];\n"
					"\t11 -- 10 [label = \" 6.0 \"];\n"
					"\t11 -- 14 [label = \" 7.0 \"];\n"
					"\t12 -- 13 [label = \" 3.0 \"];\n"
					"\t12 -- 14 [label = \" 4.0 \"];\n"
					"\t13 -- 14 [label = \" 2.0 \"];\n"
					"\t14 -- 15 [label = \" 9.0 \"];\n"
					"\t14 -- 17 [label = \" 8.0 \"];\n"
					"\t15 -- 16 [label = \" 3.0 \"];\n"
					"\t17 -- 16 [label = \" 5.0 \"];\n"
				"}\n"
				)
{

}

CGraphDtoFactory::~CGraphDtoFactory( void )
{
	
}
