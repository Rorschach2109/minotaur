/*
 * This file is part of minotaur.
 *
 * File: AdjacencyListTest.cpp
 * Brief: Implementation of adjacency list test class.
 *
 * Date: 11.08.2013
 * Author: Andrzej Korycinski
 *
 * */

#include "AdjacencyListTest.h"
#include "TestDefines.h"

using namespace Minotaur;

CAdjacencyListTest::CAdjacencyListTest( void ) : 
	AbstractMinotaurModelTest(),
	m_adjacencyList( CAdjacencyList(t_graphModelFactory.infinityAdjacencyMap, t_graphModelFactory.infinityNodesMap) )
{
	m_RunTest();
}

CAdjacencyListTest::~CAdjacencyListTest( void )
{
}

void CAdjacencyListTest::m_RunTest( void )
{
	m_CompareTest();
	m_ContainsNodeTest();
	m_GetGraphModelNodeTest();
	m_GetGraphModelNodesTest();
	m_GetNodesNumberTest();
	m_GetNeighborsTest();
	m_ContainsEdgeTest();
	m_GetGraphModelEdgeTest();
	m_GetGraphModelEdgesTest();
	m_GetEdgesNumberTest();
}

void CAdjacencyListTest::m_CompareTest( void )
{
	CAdjacencyList validAdjacencyList = CAdjacencyList(t_graphModelFactory.infinityAdjacencyMap, t_graphModelFactory.infinityNodesMap);
	CAdjacencyList invalidAdjacencyList = CAdjacencyList(t_graphModelFactory.turtleAdjacencyMap, t_graphModelFactory.turtleNodesMap);
	
	bool expectedValidResult = true;
	bool expectedInvalidResult = false;

	bool actualValidResult = ( m_adjacencyList == validAdjacencyList );
	bool actualInvalidResult = ( m_adjacencyList == invalidAdjacencyList );
	
	CHECK_EQUAL(expectedValidResult, actualValidResult);
	CHECK_EQUAL(expectedInvalidResult, actualInvalidResult);
}
	
void CAdjacencyListTest::m_ContainsNodeTest( void )
{
	++t_testNumber;

	unsigned int validNodeId = 0;
	unsigned int invalidNodeId = 10;
	
	bool validExpectedValue = true;
	bool invalidExpectedValue = false;

	bool validActualValue = m_adjacencyList.ContainsNode(validNodeId);
	bool invalidActualNode = m_adjacencyList.ContainsNode(invalidNodeId);
	
	CHECK_EQUAL(validExpectedValue, validActualValue);
	CHECK_EQUAL(invalidExpectedValue, invalidActualNode);
}

void CAdjacencyListTest::m_GetGraphModelNodeTest( void )
{
	++t_testNumber;
	
	CNodeModel expectedModelNode = CNodeModel( 3, 4, 2 );
	
	CNodeModel actualModelNode = m_adjacencyList.GetGraphModelNode(3);
	
	CHECK_EQUAL(expectedModelNode, actualModelNode);
}

void CAdjacencyListTest::m_GetGraphModelNodesTest( void )
{
	++t_testNumber;

	std::vector < CNodeModel > expectedModelNodes = t_graphModelFactory.infinityModelNodes;
	
	std::vector < CNodeModel > actualModelNodes = m_adjacencyList.GetGraphModelNodes();

	CHECK_VECTORS_EQUAL(expectedModelNodes, actualModelNodes);
}

void CAdjacencyListTest::m_GetNodesNumberTest( void )
{
	++t_testNumber;
	
	unsigned int expectedNodesNumber = 7;
	unsigned int invalidNodesNumber = 0;
	
	unsigned int actualNodesNumber = m_adjacencyList.GetNodesNumber();
	
	CHECK_EQUAL(expectedNodesNumber, actualNodesNumber);
	CHECK_NOT_EQUAL(invalidNodesNumber, actualNodesNumber);
}

void CAdjacencyListTest::m_GetNeighborsTest( void )
{
	++t_testNumber;

	std::vector < CNodeModel > expectedNode0Neighbors = t_graphModelFactory.infinityNode0Neighbors;
	
	std::vector < CNodeModel > actualNode0Neighbors = m_adjacencyList.GetNeighbors( t_graphModelFactory.infinityNodesMap[0] );

	CHECK_VECTORS_EQUAL(expectedNode0Neighbors, actualNode0Neighbors);
}

void CAdjacencyListTest::m_ContainsEdgeTest( void )
{
	++t_testNumber;
	
	unsigned int validNodeFromId = 0;
	unsigned int validNodeToId = 1;
	unsigned int invalidNodeId = 10;
	
	bool validExpectedValue = true;
	bool invalidExpectedValue = false;

	bool validActualValue = m_adjacencyList.ContainsEdge(validNodeFromId, validNodeToId);
		
	CHECK_EQUAL(validExpectedValue, validActualValue);
	
	bool invalidActualNode = m_adjacencyList.ContainsEdge(validNodeToId, validNodeFromId);
	CHECK_EQUAL(invalidExpectedValue, invalidActualNode);

	invalidActualNode = m_adjacencyList.ContainsEdge(validNodeToId, invalidNodeId);
	CHECK_EQUAL(invalidExpectedValue, invalidActualNode);
}

void CAdjacencyListTest::m_GetGraphModelEdgeTest( void )
{
	++t_testNumber;
	
	CEdgeModel expectedModelEdge = CEdgeModel( 4, 6, 1.8 );
	
	CEdgeModel actualModelEdge = m_adjacencyList.GetGraphModelEdge(4, 6);
	
	CHECK_EQUAL(expectedModelEdge, actualModelEdge);
}

void CAdjacencyListTest::m_GetGraphModelEdgesTest( void )
{
	++t_testNumber;

	std::vector < CEdgeModel > expectedModelEdges = t_graphModelFactory.infinityModelEdges;
	
	std::vector < CEdgeModel > actualModelEdges = m_adjacencyList.GetGraphModelEdges();

	CHECK_VECTORS_EQUAL(expectedModelEdges, actualModelEdges);
}

void CAdjacencyListTest::m_GetEdgesNumberTest( void )
{
	++t_testNumber;
	
	unsigned int expectedEdgesNumber = 8;
	unsigned int invalidEdgesNumber = 0;
	
	unsigned int actualEdgesNumber = m_adjacencyList.GetEdgesNumber();
	
	CHECK_EQUAL(expectedEdgesNumber, actualEdgesNumber);
	CHECK_NOT_EQUAL(invalidEdgesNumber, actualEdgesNumber);
}