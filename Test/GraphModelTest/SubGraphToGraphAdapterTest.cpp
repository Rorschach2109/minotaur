/*
 * This file is part of minotaur.
 *
 * File: SubGraphToGraphAdapterTest.cpp
 * Brief: Implementation of subgraph to graph adapter test class.
 *
 * Date: 15.08.2013
 * Author: Andrzej Korycinski
 * 
 * */
 
#include "SubGraphToGraphAdapterTest.h"
#include "AdjacencyList.h"
#include "NodeModel.h"
#include "EdgeModel.h"

#include "MinotaurTestDefines.h"

#include <vector>
 
using namespace Minotaur;
 
CSubGraphToGraphAdapterTest::CSubGraphToGraphAdapterTest( void ) : 
	AbstractMinotaurModelTest(),
	m_subGraphTest( *t_graphModelFactory.infinityGraphModel, t_subGraphModelFactory.infinityModelEdgeDefinition ),
	m_adapterTest( CSubGraphToGraphAdapter(m_subGraphTest) )
{
	m_RunTest();
}

CSubGraphToGraphAdapterTest::~CSubGraphToGraphAdapterTest( void )
{
	
}
		
void CSubGraphToGraphAdapterTest::m_RunTest( void )
{
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

void CSubGraphToGraphAdapterTest::m_ContainsNodeTest( void )
{
	t_testNumber += 2;

	unsigned int validNodeId = 0;
	unsigned int invalidNodeId = 10;
	
	bool validExpectedValue = true;
	
	bool validActualValue = m_adapterTest.ContainsNode(validNodeId);
	bool invalidActualValue = m_adapterTest.ContainsNode(invalidNodeId);
	
	CHECK_EQUAL( validExpectedValue, validActualValue, t_failedTestNumber );
	CHECK_NOT_EQUAL( validExpectedValue, invalidActualValue, t_failedTestNumber );
}


void CSubGraphToGraphAdapterTest::m_GetGraphModelNodeTest( void )
{
	t_testNumber += 2;

	CNodeModel expectedNode = t_graphModelFactory.infinityModelNodes[0];
	unsigned int validNodeId = t_graphModelFactory.infinityModelNodes[0].GetNodeId();
	unsigned int invalidNodeId = t_graphModelFactory.infinityModelNodes[1].GetNodeId();
	
	CNodeModel validActualNode = m_adapterTest.GetGraphModelNode( validNodeId );
	CNodeModel invalidActualNode = m_adapterTest.GetGraphModelNode( invalidNodeId );
	
	CHECK_EQUAL( expectedNode, validActualNode, t_failedTestNumber );
	CHECK_NOT_EQUAL( expectedNode, invalidActualNode, t_failedTestNumber );
}


void CSubGraphToGraphAdapterTest::m_GetGraphModelNodesTest( void )
{
	++t_testNumber;

	std::vector < CNodeModel > expectedSubGraphNodes = t_graphModelFactory.infinityModelNodes;
	
	std::vector < CNodeModel > actualSubGraphNodes = m_adapterTest.GetGraphModelNodes();
	
	CHECK_VECTORS_EQUAL( expectedSubGraphNodes, actualSubGraphNodes, t_failedTestNumber);
}


void CSubGraphToGraphAdapterTest::m_GetNodesNumberTest( void )
{
	++t_testNumber;

	unsigned int expectedNodesNumber = 7;
	
	unsigned int actualNodesNumber = m_adapterTest.GetNodesNumber();
	
	CHECK_EQUAL( expectedNodesNumber, actualNodesNumber, t_failedTestNumber );
}

void CSubGraphToGraphAdapterTest::m_GetNeighborsTest( void )
{
	t_testNumber += 3;

	CNodeModel nodeModelTest = CNodeModel( 1, 2, 4 );
	
	std::vector < CNodeModel > expectedNodes; 
	expectedNodes.push_back( CNodeModel( 0, 0, 2 ) );
	expectedNodes.push_back( CNodeModel( 3, 4, 2 ) );
	
	std::vector < CNodeModel > invalidNodes;
	invalidNodes.push_back( CNodeModel( 3, 4, 4 ) );
	invalidNodes.push_back( CNodeModel( 0, 0, 2 ) );

	std::vector < CNodeModel > invalidNodesNumber; 
	invalidNodesNumber.push_back( CNodeModel( 0, 0, 2 ) );
	
	std::vector < CNodeModel > actualNodes = m_adapterTest.GetNeighbors( nodeModelTest );

	CHECK_VECTORS_EQUAL( expectedNodes, actualNodes, t_failedTestNumber );
	CHECK_VECTORS_NOT_EQUAL( invalidNodes, actualNodes, t_failedTestNumber );
	CHECK_VECTORS_NOT_EQUAL( invalidNodesNumber, actualNodes, t_failedTestNumber );
}


void CSubGraphToGraphAdapterTest::m_ContainsEdgeTest( void )
{
	t_testNumber += 2;

	unsigned int validNodeFromId = 1;
	unsigned int validNodeToId = 3;
	
	unsigned int invalidNodeFromId = 0;
	unsigned int invalidNodeToId = 2;
	
	bool validExpectedValue = true;
	
	bool validActualValue = m_adapterTest.ContainsEdge(validNodeFromId, validNodeToId);
	bool invalidActualValue = m_adapterTest.ContainsEdge(invalidNodeFromId, invalidNodeToId);
	
	CHECK_EQUAL( validExpectedValue, validActualValue, t_failedTestNumber );
	CHECK_NOT_EQUAL( validExpectedValue, invalidActualValue, t_failedTestNumber );
}


void CSubGraphToGraphAdapterTest::m_GetGraphModelEdgeTest( void )
{
	t_testNumber += 2;

	CEdgeModel expectedEdge = t_graphModelFactory.infinityModelEdges[0];
	
	unsigned int validNodeFormId = t_graphModelFactory.infinityModelEdges[0].GetNodeFromId();
	unsigned int validNodeToId = t_graphModelFactory.infinityModelEdges[0].GetNodeToId();
	unsigned int invalidNodeFromId = t_graphModelFactory.infinityModelEdges[1].GetNodeFromId();
	unsigned int invalidNodeToId = t_graphModelFactory.infinityModelEdges[1].GetNodeToId();
	
	CEdgeModel validActualEdge = m_adapterTest.GetGraphModelEdge( validNodeFormId, validNodeToId );
	CEdgeModel invalidActualEdge = m_adapterTest.GetGraphModelEdge( invalidNodeFromId, invalidNodeToId );
	
	CHECK_EQUAL( expectedEdge, validActualEdge, t_failedTestNumber );
	CHECK_NOT_EQUAL( expectedEdge, invalidActualEdge, t_failedTestNumber );
}


void CSubGraphToGraphAdapterTest::m_GetGraphModelEdgesTest( void )
{
	t_testNumber += 2;

	std::vector < CEdgeModel > expectedSubGraphEdges = t_subGraphModelFactory.infinitySubGraphModelEdges;
	
	std::vector < CEdgeModel > invalidSubGraphEdges = t_graphModelFactory.infinityModelEdges;
	
	std::vector < CEdgeModel > actualSubGraphEdges = m_adapterTest.GetGraphModelEdges();
	
	CHECK_VECTORS_EQUAL( expectedSubGraphEdges, actualSubGraphEdges, t_failedTestNumber );
	CHECK_VECTORS_NOT_EQUAL( invalidSubGraphEdges, actualSubGraphEdges, t_failedTestNumber );
}


void CSubGraphToGraphAdapterTest::m_GetEdgesNumberTest( void )
{
	++t_testNumber;

	unsigned int expectedEdgesNumber = 6;
	
	unsigned int actualEdgesNumber = m_adapterTest.GetEdgesNumber();
	
	CHECK_EQUAL( expectedEdgesNumber, actualEdgesNumber, t_failedTestNumber );
}
