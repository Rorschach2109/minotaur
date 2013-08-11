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
#include "EdgeModel.h"
#include "IGraphModel.h"

#include "TestDefines.h"

#include <memory>
#include <vector>
#include <map>

using namespace Minotaur;

CAdjacencyListFactoryTest::CAdjacencyListFactoryTest( void ) :
	AbstractModelMinotaurTest(),
	m_adjacencyListFactory( CAdjacencyListFactory() )
{
	m_CreateFromVectorsTest();	
}

CAdjacencyListFactoryTest::~CAdjacencyListFactoryTest( void )
{
	
}

void CAdjacencyListFactoryTest::m_CreateFromVectorsTest( void )
{
	std::vector < CNodeModel > expectedGraphModelNodes = t_graphModelFactory.turtleModelNodes;
	std::vector < CEdgeModel> expectedGraphModelEdges = t_graphModelFactory.turtleModelEdges;
	
	std::shared_ptr < IGraphModel > actualAdjacencyList = m_adjacencyListFactory.CreateFromVectors(expectedGraphModelNodes, expectedGraphModelEdges);
		
	std::vector < CNodeModel > actualGraphModelNodes = actualAdjacencyList->GetGraphModelNodes();
	std::vector < CEdgeModel > actualGraphModelEdges = actualAdjacencyList->GetGraphModelEdges();
	
	CHECK_VECTORS_EQUAL(expectedGraphModelNodes, actualGraphModelNodes);
	CHECK_VECTORS_EQUAL(expectedGraphModelEdges, actualGraphModelEdges);
	
	actualAdjacencyList.reset();
}