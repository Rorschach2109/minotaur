/*
 * This file is part of minotaur.
 *
 * File: AdjacencyListFactoryTest.cpp
 * Brief: Implementation of adjacency list factory test class.
 *
 * Date: 11.08.2013
 * Author: Andrzej Korycinski
 * 
 * */

#include "AdjacencyListFactoryTest.h"

#include "NodeModel.h"
#include "NodeDTO.h"

#include "EdgeModel.h"
#include "EdgeDTO.h"

#include "IGraphModel.h"

#include "MinotaurTestDefines.h"

#include <memory>
#include <vector>
#include <map>

using namespace Minotaur;

CAdjacencyListFactoryTest::CAdjacencyListFactoryTest( void ) :
	AbstractMinotaurModelTest(),
	AbstractMinotaurDtoTest(),
	m_adjacencyListFactory( CAdjacencyListFactory() )
{
	m_CreateFromVectorsTest();
	m_CreateSquareFromDtoTest();
	m_CreateInfinityFromDtoTest();
	m_CreateTurtleFromDtoTest();
	m_CreateDoubleTriangleFromDtoTest();
}

CAdjacencyListFactoryTest::~CAdjacencyListFactoryTest( void )
{
	
}

void CAdjacencyListFactoryTest::m_CreateFromVectorsTest( void )
{
	t_testNumber += 4;

	std::vector < CNodeModel > expectedGraphModelNodes = t_graphModelFactory.turtleModelNodes;
	std::vector < CEdgeModel> expectedGraphModelEdges = t_graphModelFactory.turtleModelEdges;
	
	std::vector < CNodeModel > invalidGraphModelNodes = t_graphModelFactory.squareModelNodes;
	std::vector < CEdgeModel> invalidGraphModelEdges = t_graphModelFactory.squareModelEdges;

	std::shared_ptr < IGraphModel > actualAdjacencyList = m_adjacencyListFactory.CreateFromVectors(expectedGraphModelNodes, expectedGraphModelEdges);
		
	std::vector < CNodeModel > actualGraphModelNodes = actualAdjacencyList->GetGraphModelNodes();
	std::vector < CEdgeModel > actualGraphModelEdges = actualAdjacencyList->GetGraphModelEdges();
	
	CHECK_VECTORS_EQUAL( expectedGraphModelNodes, actualGraphModelNodes, t_failedTestNumber );
	CHECK_VECTORS_EQUAL( expectedGraphModelEdges, actualGraphModelEdges, t_failedTestNumber );
	
	CHECK_VECTORS_NOT_EQUAL( invalidGraphModelNodes, actualGraphModelNodes, t_failedTestNumber );
	CHECK_VECTORS_NOT_EQUAL( invalidGraphModelEdges, actualGraphModelEdges, t_failedTestNumber );
	
	actualAdjacencyList.reset();
}

void CAdjacencyListFactoryTest::m_CreateSquareFromDtoTest( void )
{
	t_testNumber += 4;
	
	std::vector < CNodeDto > graphDtoNodes = t_dtoGraphFactory.squareDtoNodes;
	std::vector < CEdgeDto > graphDtoEdges = t_dtoGraphFactory.squareDtoEdges;
	
	std::shared_ptr < IGraphModel > actualAdjacencyList = m_adjacencyListFactory.CreateFromDto(graphDtoNodes, graphDtoEdges);

	std::vector < CNodeModel > expectedGraphModelNodes = t_graphModelFactory.squareModelNodes;
	std::vector < CEdgeModel> expectedGraphModelEdges = t_graphModelFactory.squareModelEdges;

	std::vector < CNodeModel > invalidGraphModelNodes = t_graphModelFactory.infinityModelNodes;
	std::vector < CEdgeModel> invalidGraphModelEdges = t_graphModelFactory.infinityModelEdges;

	std::vector < CNodeModel > actualGraphModelNodes = actualAdjacencyList->GetGraphModelNodes();
	std::vector < CEdgeModel > actualGraphModelEdges = actualAdjacencyList->GetGraphModelEdges();
	
	CHECK_VECTORS_EQUAL( expectedGraphModelNodes, actualGraphModelNodes, t_failedTestNumber );
	CHECK_VECTORS_EQUAL( expectedGraphModelEdges, actualGraphModelEdges, t_failedTestNumber );

	CHECK_VECTORS_NOT_EQUAL( invalidGraphModelNodes, actualGraphModelNodes, t_failedTestNumber );
	CHECK_VECTORS_NOT_EQUAL( invalidGraphModelEdges, actualGraphModelEdges, t_failedTestNumber );

	actualAdjacencyList.reset();
}

void CAdjacencyListFactoryTest::m_CreateInfinityFromDtoTest( void )
{
	t_testNumber += 4;

	std::vector < CNodeDto > graphDtoNodes = t_dtoGraphFactory.infinityDtoNodes;
	std::vector < CEdgeDto > graphDtoEdges = t_dtoGraphFactory.infinityDtoEdges;
	
	std::shared_ptr < IGraphModel > actualAdjacencyList = m_adjacencyListFactory.CreateFromDto(graphDtoNodes, graphDtoEdges);

	std::vector < CNodeModel > expectedGraphModelNodes = t_graphModelFactory.infinityModelNodes;
	std::vector < CEdgeModel> expectedGraphModelEdges = t_graphModelFactory.infinityModelEdges;

	std::vector < CNodeModel > invalidGraphModelNodes = t_graphModelFactory.squareModelNodes;
	std::vector < CEdgeModel> invalidGraphModelEdges = t_graphModelFactory.squareModelEdges;

	std::vector < CNodeModel > actualGraphModelNodes = actualAdjacencyList->GetGraphModelNodes();
	std::vector < CEdgeModel > actualGraphModelEdges = actualAdjacencyList->GetGraphModelEdges();
	
	CHECK_VECTORS_EQUAL( expectedGraphModelNodes, actualGraphModelNodes, t_failedTestNumber );
	CHECK_VECTORS_EQUAL( expectedGraphModelEdges, actualGraphModelEdges, t_failedTestNumber );

	CHECK_VECTORS_NOT_EQUAL( invalidGraphModelNodes, actualGraphModelNodes, t_failedTestNumber );
	CHECK_VECTORS_NOT_EQUAL( invalidGraphModelEdges, actualGraphModelEdges, t_failedTestNumber );

	actualAdjacencyList.reset();
}

void CAdjacencyListFactoryTest::m_CreateTurtleFromDtoTest( void )
{
	t_testNumber += 4;

	std::vector < CNodeDto > graphDtoNodes = t_dtoGraphFactory.turtleDtoNodes;
	std::vector < CEdgeDto > graphDtoEdges = t_dtoGraphFactory.turtleDtoEdges;
	
	std::shared_ptr < IGraphModel > actualAdjacencyList = m_adjacencyListFactory.CreateFromDto(graphDtoNodes, graphDtoEdges);

	std::vector < CNodeModel > expectedGraphModelNodes = t_graphModelFactory.turtleModelNodes;
	std::vector < CEdgeModel> expectedGraphModelEdges = t_graphModelFactory.turtleModelEdges;

	std::vector < CNodeModel > invalidGraphModelNodes = t_graphModelFactory.infinityModelNodes;
	std::vector < CEdgeModel> invalidGraphModelEdges = t_graphModelFactory.infinityModelEdges;

	std::vector < CNodeModel > actualGraphModelNodes = actualAdjacencyList->GetGraphModelNodes();
	std::vector < CEdgeModel > actualGraphModelEdges = actualAdjacencyList->GetGraphModelEdges();
	
	CHECK_VECTORS_EQUAL( expectedGraphModelNodes, actualGraphModelNodes, t_failedTestNumber );
	CHECK_VECTORS_EQUAL( expectedGraphModelEdges, actualGraphModelEdges, t_failedTestNumber );

	CHECK_VECTORS_NOT_EQUAL( invalidGraphModelNodes, actualGraphModelNodes, t_failedTestNumber );
	CHECK_VECTORS_NOT_EQUAL( invalidGraphModelEdges, actualGraphModelEdges, t_failedTestNumber );

	actualAdjacencyList.reset();
}

void CAdjacencyListFactoryTest::m_CreateDoubleTriangleFromDtoTest( void )
{
	t_testNumber += 4;

	std::vector < CNodeDto > graphDtoNodes = t_dtoGraphFactory.doubleTriangleDtoNodes;
	std::vector < CEdgeDto > graphDtoEdges = t_dtoGraphFactory.doubleTriangleDtoEdges;
	
	std::shared_ptr < IGraphModel > actualAdjacencyList = m_adjacencyListFactory.CreateFromDto(graphDtoNodes, graphDtoEdges);

	std::vector < CNodeModel > expectedGraphModelNodes = t_graphModelFactory.doubleTriangleModelNodes;
	std::vector < CEdgeModel> expectedGraphModelEdges = t_graphModelFactory.doubleTriangleModelEdges;

	std::vector < CNodeModel > invalidGraphModelNodes = t_graphModelFactory.infinityModelNodes;
	std::vector < CEdgeModel> invalidGraphModelEdges = t_graphModelFactory.infinityModelEdges;

	std::vector < CNodeModel > actualGraphModelNodes = actualAdjacencyList->GetGraphModelNodes();
	std::vector < CEdgeModel > actualGraphModelEdges = actualAdjacencyList->GetGraphModelEdges();
	
	CHECK_VECTORS_EQUAL( expectedGraphModelNodes, actualGraphModelNodes, t_failedTestNumber );
	CHECK_VECTORS_EQUAL( expectedGraphModelEdges, actualGraphModelEdges, t_failedTestNumber );

	CHECK_VECTORS_NOT_EQUAL( invalidGraphModelNodes, actualGraphModelNodes, t_failedTestNumber );
	CHECK_VECTORS_NOT_EQUAL( invalidGraphModelEdges, actualGraphModelEdges, t_failedTestNumber );

	actualAdjacencyList.reset();
}