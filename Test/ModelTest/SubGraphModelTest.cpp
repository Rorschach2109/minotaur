/*
 * This file is part of minotaur.
 *
 * File: SubGraphTest.cpp
 * Brief: Implementation of subgraph test class.
 *
 * Date: 18.08.2013
 * Author: Andrzej Korycinski
 * 
 * */

#include "SubGraphModelTest.h"
#include "AdjacencyList.h"

#include "TestDefines.h"

#include <vector>
#include <utility>

using namespace Minotaur;

CSubGraphModelTest::CSubGraphModelTest( void ) :
	AbstractMinotaurModelTest(),
	m_subGraphTest( CSubGraphModel( *t_graphModelFactory.infinityGraphModel, t_graphModelFactory.subGraphModelFactory.doubleTriangleModelEdgeDefinition) )
{
	m_VerifySubGraphTopologyTest();
	m_GetSubGraphEdgesTest();
}

CSubGraphModelTest::~CSubGraphModelTest( void )
{
	
}

void CSubGraphModelTest::m_VerifySubGraphTopologyTest( void )
{
	++t_testNumber;
	
	bool expectedValue = true;
	
	bool actualValue = m_subGraphTest.VerifySubGraphTopology();
	
	CHECK_EQUAL(expectedValue, actualValue);
}

void CSubGraphModelTest::m_GetSubGraphEdgesTest( void )
{
	++t_testNumber;
	std::vector < std::pair < unsigned int, unsigned int > > expectedSubGraphEdges = t_graphModelFactory.subGraphModelFactory.doubleTriangleModelEdgeDefinition;
	std::vector < std::pair < unsigned int, unsigned int > > invalidSubGraphEdges = t_graphModelFactory.subGraphModelFactory.infinityModelEdgeDefinition;
	std::vector < std::pair < unsigned int, unsigned int > > actualSubGraphEdges = m_subGraphTest.GetSubGraphEdges();
	
	CHECK_VECTORS_EQUAL(expectedSubGraphEdges, actualSubGraphEdges);
	CHECK_VECTORS_NOT_EQUAL(invalidSubGraphEdges, actualSubGraphEdges);
}
