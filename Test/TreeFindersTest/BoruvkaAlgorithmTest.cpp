/*
 * This file is part of minotaur.
 *
 * File: BoruvkaAlgorithmTest.cpp
 * Brief: Implementation of boruvka algorithm test class.
 *
 * Date: 23.08.2013
 * Author: Andrzej Korycinski
 *
 * */
 
#include "BoruvkaAlgorithmTest.h"
#include "NodeModel.h"

#include "MinotaurTestDefines.h"

using namespace Minotaur;

CBoruvkaAlgorithmTest::CBoruvkaAlgorithmTest( void ) : 
	m_boruvkaAlgorithmTest( CBoruvkaAlgorithm() ),
	m_subGraphComparer( CSubGraphComparer() )
{
	m_FindSquareMSTTest();
	m_FindInfinityMSTTest();
	m_FindTurtleMSTTest();
	m_FindDoubleTriangleMSTTest();
	m_FindSpiderNetMSTTest();
	m_FindGrapeMSTTest();
}

CBoruvkaAlgorithmTest::~CBoruvkaAlgorithmTest( void )
{
	
}

bool CBoruvkaAlgorithmTest::m_CheckPtr( const std::shared_ptr < CTreeModel > actualTree )
{
	++t_testNumber;
	
	bool nullPtr = ( nullptr == actualTree );
	
	CHECK_NOT_EQUAL( nullptr, actualTree, t_failedTestNumber );
		
	return nullPtr;
}

void CBoruvkaAlgorithmTest::m_FindSquareMSTTest( void )
{
	CNodeModel rootNode = CNodeModel( 0, 0, 0 );
	std::shared_ptr < CTreeModel > expectedValidTree = t_subGraphModelFactory.squareModelMSTBoruvka;
	std::shared_ptr < CTreeModel > invalidTree = t_subGraphModelFactory.turtleModelMSTBoruvka;
	
	std::shared_ptr < CTreeModel > actualTree = m_boruvkaAlgorithmTest.FindMST( *( t_graphModelFactory.squareGraphModel ), rootNode);
	if ( !m_CheckPtr(actualTree) )
	{
		t_testNumber += 2;

		bool expectedValue = true;
		
		bool actualValidValue = m_subGraphComparer.AreEqual(*expectedValidTree, *actualTree);
		bool actualInvalidValue = m_subGraphComparer.AreEqual(*invalidTree, *actualTree);
		
		CHECK_EQUAL( expectedValue, actualValidValue, t_failedTestNumber );
		CHECK_NOT_EQUAL( expectedValue, actualInvalidValue, t_failedTestNumber );
	}
	
	expectedValidTree.reset();
	invalidTree.reset();
	actualTree.reset();
}

void CBoruvkaAlgorithmTest::m_FindInfinityMSTTest( void )
{
	CNodeModel rootNode = CNodeModel( 0, 0, 2 );
	std::shared_ptr < CTreeModel > expectedValidTree = t_subGraphModelFactory.infinityModelMSTBoruvka;
	std::shared_ptr < CTreeModel > invalidTree = t_subGraphModelFactory.infinityModelMSTPrim;
	
	std::shared_ptr < CTreeModel > actualTree = m_boruvkaAlgorithmTest.FindMST( *( t_graphModelFactory.infinityGraphModel ), rootNode);
	if ( !m_CheckPtr(actualTree) )
	{
		t_testNumber += 2;

		bool expectedValue = true;
		
		bool actualValidValue = m_subGraphComparer.AreEqual(*expectedValidTree, *actualTree);
		bool actualInvalidValue = m_subGraphComparer.AreEqual(*invalidTree, *actualTree);
		
		CHECK_EQUAL( expectedValue, actualValidValue, t_failedTestNumber );
		CHECK_NOT_EQUAL( expectedValue, actualInvalidValue, t_failedTestNumber );
	}
	
	expectedValidTree.reset();
	invalidTree.reset();
	actualTree.reset();
}

void CBoruvkaAlgorithmTest::m_FindTurtleMSTTest( void )
{
	CNodeModel rootNode = CNodeModel( 0, 0, 0 );
	std::shared_ptr < CTreeModel > expectedValidTree = t_subGraphModelFactory.turtleModelMSTBoruvka;
	std::shared_ptr < CTreeModel > invalidTree = t_subGraphModelFactory.squareModelMSTBoruvka;
	
	std::shared_ptr < CTreeModel > actualTree = m_boruvkaAlgorithmTest.FindMST( *( t_graphModelFactory.turtleGraphModel ), rootNode);
	if ( !m_CheckPtr(actualTree) )
	{
		t_testNumber += 2;
		
		bool expectedValue = true;
		
		bool actualValidValue = m_subGraphComparer.AreEqual(*expectedValidTree, *actualTree);
		bool actualInvalidValue = m_subGraphComparer.AreEqual(*invalidTree, *actualTree);
		
		CHECK_EQUAL( expectedValue, actualValidValue, t_failedTestNumber );
		CHECK_NOT_EQUAL( expectedValue, actualInvalidValue, t_failedTestNumber );
	}
	
	expectedValidTree.reset();
	invalidTree.reset();
	actualTree.reset();
}

void CBoruvkaAlgorithmTest::m_FindDoubleTriangleMSTTest( void )
{
	CNodeModel rootNode = CNodeModel( 0, 0, 0 );
	std::shared_ptr < CTreeModel > expectedValidTree = t_subGraphModelFactory.doubleTriangleModelMSTBoruvka;
	std::shared_ptr < CTreeModel > invalidTree = t_subGraphModelFactory.turtleModelMSTBoruvka;
	
	std::shared_ptr < CTreeModel > actualTree = m_boruvkaAlgorithmTest.FindMST( *( t_graphModelFactory.doubleTriangleGraphModel ), rootNode);
	if ( !m_CheckPtr(actualTree) )
	{
		t_testNumber += 2;

		bool expectedValue = true;
		
		bool actualValidValue = m_subGraphComparer.AreEqual(*expectedValidTree, *actualTree);
		bool actualInvalidValue = m_subGraphComparer.AreEqual(*invalidTree, *actualTree);
		
		CHECK_EQUAL( expectedValue, actualValidValue, t_failedTestNumber );
		CHECK_NOT_EQUAL( expectedValue, actualInvalidValue, t_failedTestNumber );
	}
	
	expectedValidTree.reset();
	invalidTree.reset();
	actualTree.reset();
}

void CBoruvkaAlgorithmTest::m_FindSpiderNetMSTTest( void )
{
	CNodeModel rootNode = CNodeModel( 0, 0, 0 );
	std::shared_ptr < CTreeModel > expectedValidTree = t_subGraphModelFactory.spiderNetModelMSTBoruvka;
	std::shared_ptr < CTreeModel > invalidTree = t_subGraphModelFactory.doubleTriangleModelMSTBoruvka;
	
	std::shared_ptr < CTreeModel > actualTree = m_boruvkaAlgorithmTest.FindMST( *( t_graphModelFactory.spiderNetGraphModel ), rootNode);
	if ( !m_CheckPtr(actualTree) )
	{
		t_testNumber += 2;

		bool expectedValue = true;
		
		bool actualValidValue = m_subGraphComparer.AreEqual(*expectedValidTree, *actualTree);
		bool actualInvalidValue = m_subGraphComparer.AreEqual(*invalidTree, *actualTree);
		
		CHECK_EQUAL( expectedValue, actualValidValue, t_failedTestNumber );
		CHECK_NOT_EQUAL( expectedValue, actualInvalidValue, t_failedTestNumber );
	}
	
	expectedValidTree.reset();
	invalidTree.reset();
	actualTree.reset();
}

void CBoruvkaAlgorithmTest::m_FindGrapeMSTTest( void )
{
	CNodeModel rootNode = CNodeModel( 0, 0, 0 );
	std::shared_ptr < CTreeModel > expectedValidTree = t_subGraphModelFactory.grapeModelMSTBoruvka;
	std::shared_ptr < CTreeModel > invalidTree = t_subGraphModelFactory.doubleTriangleModelMSTBoruvka;
	
	std::shared_ptr < CTreeModel > actualTree = m_boruvkaAlgorithmTest.FindMST( *( t_graphModelFactory.grapeGraphModel ), rootNode);
	if ( !m_CheckPtr(actualTree) )
	{
		t_testNumber += 2;

		bool expectedValue = true;
		
		bool actualValidValue = m_subGraphComparer.AreEqual(*expectedValidTree, *actualTree);
		bool actualInvalidValue = m_subGraphComparer.AreEqual(*invalidTree, *actualTree);
		
		CHECK_EQUAL( expectedValue, actualValidValue, t_failedTestNumber );
		CHECK_NOT_EQUAL( expectedValue, actualInvalidValue, t_failedTestNumber );
	}

	expectedValidTree.reset();
	invalidTree.reset();
	actualTree.reset();
}
