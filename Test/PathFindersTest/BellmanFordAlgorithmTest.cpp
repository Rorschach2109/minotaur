/*
 * This file is part of minotaur.
 *
 * File: BellmanFordAlgorithmTest.cpp
 * Brief: Implementation of bellman-ford algorithm test class.
 *
 * Date: .07.2013
 * Author: Andrzej Korycinski
 *
 * */
 
#include "BellmanFordAlgorithmTest.h"

#include "MinotaurTestDefines.h"

using namespace Minotaur;

CBellmanFordAlgorithmTest::CBellmanFordAlgorithmTest( void ) :
	AbstractMinotaurModelTest(),
	m_relaxationProvider( CRelaxationProvider() ),
	m_bellmanFordAlgorithmTest( CBellmanFordAlgorithm(m_relaxationProvider) ),
	m_subGraphComparer( CSubGraphComparer() )
{
	m_FindSquareShortestPathTest();
	m_FindInfinityShortestPathTest();
	m_FindTurtleShortestPathTest();
	m_FindDoubleTriangleShortest0To5PathTest();
	m_FindDoubleTriangleShortest2To5PathTest();
	m_FindSpiderNetShortest0To7PathTest();
	m_FindSpiderNetShortest5To0PathTest();
	m_FindGrapeShortest0To16PathTest();
	m_FindGrapeShortest9To13PathTest();
}

CBellmanFordAlgorithmTest::~CBellmanFordAlgorithmTest( void )
{
	
}

bool CBellmanFordAlgorithmTest::m_CheckPtr( const std::shared_ptr < CPathModel > actualPath )
{
	++t_testNumber;
	
	bool nullPtr = ( nullptr == actualPath );
	
	CHECK_NOT_EQUAL( nullptr, actualPath, t_failedTestNumber );
		
	return nullPtr;
}

void CBellmanFordAlgorithmTest::m_FindSquareShortestPathTest( void )
{
	CNodeModel nodeFrom = CNodeModel( 0, 0, 0 );
	CNodeModel nodeTo = CNodeModel( 3, 2, 2 );

	std::shared_ptr < CPathModel > expectedValidPath = t_subGraphModelFactory.squareFrom0To3Path;
	std::shared_ptr < CPathModel > invalidPath = t_subGraphModelFactory.turtleFrom0To3Path;
	
	std::shared_ptr < CPathModel > actualPath = m_bellmanFordAlgorithmTest.FindShortestPath( *( t_graphModelFactory.squareGraphModel ), nodeFrom, nodeTo );
	if ( !m_CheckPtr(actualPath) )
	{
		t_testNumber += 2;

		bool expectedValue = true;
		
		bool actualValidValue = m_subGraphComparer.AreEqual(*expectedValidPath, *actualPath);
		bool actualInvalidValue = m_subGraphComparer.AreEqual(*invalidPath, *actualPath);
		
		CHECK_EQUAL( expectedValue, actualValidValue, t_failedTestNumber );
		CHECK_NOT_EQUAL( expectedValue, actualInvalidValue, t_failedTestNumber );
	}
	
	expectedValidPath.reset();
	invalidPath.reset();
	actualPath.reset();
}

void CBellmanFordAlgorithmTest::m_FindInfinityShortestPathTest( void )
{
	CNodeModel nodeFrom = CNodeModel( 0, 0, 2 );
	CNodeModel nodeTo = CNodeModel( 6, 8, 2 );

	std::shared_ptr < CPathModel > expectedValidPath = t_subGraphModelFactory.infinityFrom0To6Path;
	std::shared_ptr < CPathModel > invalidPath = t_subGraphModelFactory.turtleFrom0To3Path;
	
	std::shared_ptr < CPathModel > actualPath = m_bellmanFordAlgorithmTest.FindShortestPath( *( t_graphModelFactory.infinityGraphModel ), nodeFrom, nodeTo );
	if ( !m_CheckPtr(actualPath) )
	{
		t_testNumber += 2;

		bool expectedValue = true;
		
		bool actualValidValue = m_subGraphComparer.AreEqual(*expectedValidPath, *actualPath);
		bool actualInvalidValue = m_subGraphComparer.AreEqual(*invalidPath, *actualPath);
		
		CHECK_EQUAL( expectedValue, actualValidValue, t_failedTestNumber );
		CHECK_NOT_EQUAL( expectedValue, actualInvalidValue, t_failedTestNumber );
	}
	
	expectedValidPath.reset();
	invalidPath.reset();
	actualPath.reset();
}

void CBellmanFordAlgorithmTest::m_FindTurtleShortestPathTest( void )
{
	CNodeModel nodeFrom = CNodeModel( 0, 0, 0 );
	CNodeModel nodeTo = CNodeModel( 3, 6, 0 );

	std::shared_ptr < CPathModel > expectedValidPath = t_subGraphModelFactory.turtleFrom0To3Path;
	std::shared_ptr < CPathModel > invalidPath = t_subGraphModelFactory.squareFrom0To3Path;
	
	std::shared_ptr < CPathModel > actualPath = m_bellmanFordAlgorithmTest.FindShortestPath( *( t_graphModelFactory.turtleGraphModel ), nodeFrom, nodeTo );
	if ( !m_CheckPtr(actualPath) )
	{
		t_testNumber += 2;
		
		bool expectedValue = true;
		
		bool actualValidValue = m_subGraphComparer.AreEqual(*expectedValidPath, *actualPath);
		bool actualInvalidValue = m_subGraphComparer.AreEqual(*invalidPath, *actualPath);
		
		CHECK_EQUAL( expectedValue, actualValidValue, t_failedTestNumber );
		CHECK_NOT_EQUAL( expectedValue, actualInvalidValue, t_failedTestNumber );
	}
	
	expectedValidPath.reset();
	invalidPath.reset();
	actualPath.reset();
}

void CBellmanFordAlgorithmTest::m_FindDoubleTriangleShortest0To5PathTest( void )
{
	CNodeModel nodeFrom = CNodeModel( 0, 0, 0 );
	CNodeModel nodeTo = CNodeModel( 5, 2, 4 );

	std::shared_ptr < CPathModel > expectedValidPath = t_subGraphModelFactory.doubleTriangleFrom0To5Path;
	std::shared_ptr < CPathModel > invalidPath = t_subGraphModelFactory.turtleFrom0To3Path;
	
	std::shared_ptr < CPathModel > actualPath = m_bellmanFordAlgorithmTest.FindShortestPath( *( t_graphModelFactory.doubleTriangleGraphModel ), nodeFrom, nodeTo );
	if ( !m_CheckPtr(actualPath) )
	{
		t_testNumber += 2;

		bool expectedValue = true;
		
		bool actualValidValue = m_subGraphComparer.AreEqual(*expectedValidPath, *actualPath);
		bool actualInvalidValue = m_subGraphComparer.AreEqual(*invalidPath, *actualPath);
		
		CHECK_EQUAL( expectedValue, actualValidValue, t_failedTestNumber );
		CHECK_NOT_EQUAL( expectedValue, actualInvalidValue, t_failedTestNumber );
	}
	
	expectedValidPath.reset();
	invalidPath.reset();
	actualPath.reset();
}

void CBellmanFordAlgorithmTest::m_FindDoubleTriangleShortest2To5PathTest( void )
{
	CNodeModel nodeFrom = CNodeModel( 2, 4, 0 );
	CNodeModel nodeTo = CNodeModel( 5, 2, 4 );

	std::shared_ptr < CPathModel > expectedValidPath = t_subGraphModelFactory.doubleTriangleFrom2To5Path;
	std::shared_ptr < CPathModel > invalidPath = t_subGraphModelFactory.doubleTriangleFrom0To5Path;
	
	std::shared_ptr < CPathModel > actualPath = m_bellmanFordAlgorithmTest.FindShortestPath( *( t_graphModelFactory.doubleTriangleGraphModel ), nodeFrom, nodeTo );
	if ( !m_CheckPtr(actualPath) )
	{
		t_testNumber += 2;

		bool expectedValue = true;
		
		bool actualValidValue = m_subGraphComparer.AreEqual(*expectedValidPath, *actualPath);
		bool actualInvalidValue = m_subGraphComparer.AreEqual(*invalidPath, *actualPath);
		
		CHECK_EQUAL( expectedValue, actualValidValue, t_failedTestNumber );
		CHECK_NOT_EQUAL( expectedValue, actualInvalidValue, t_failedTestNumber );
	}
	
	expectedValidPath.reset();
	invalidPath.reset();
	actualPath.reset();
}

void CBellmanFordAlgorithmTest::m_FindSpiderNetShortest0To7PathTest( void )
{
	CNodeModel nodeFrom = CNodeModel( 0, 0, 2 );
	CNodeModel nodeTo = CNodeModel( 7, 10, 4 );

	std::shared_ptr < CPathModel > expectedValidPath = t_subGraphModelFactory.spiderNetFrom0To7Path;
	std::shared_ptr < CPathModel > invalidPath = t_subGraphModelFactory.doubleTriangleFrom0To5Path;
	
	std::shared_ptr < CPathModel > actualPath = m_bellmanFordAlgorithmTest.FindShortestPath( *( t_graphModelFactory.spiderNetGraphModel ), nodeFrom, nodeTo );
	if ( !m_CheckPtr(actualPath) )
	{
		t_testNumber += 2;

		bool expectedValue = true;
		
		bool actualValidValue = m_subGraphComparer.AreEqual(*expectedValidPath, *actualPath);
		bool actualInvalidValue = m_subGraphComparer.AreEqual(*invalidPath, *actualPath);
		
		CHECK_EQUAL( expectedValue, actualValidValue, t_failedTestNumber );
		CHECK_NOT_EQUAL( expectedValue, actualInvalidValue, t_failedTestNumber );
	}
	
	expectedValidPath.reset();
	invalidPath.reset();
	actualPath.reset();
}

void CBellmanFordAlgorithmTest::m_FindSpiderNetShortest5To0PathTest( void )
{
	CNodeModel nodeTo = CNodeModel( 5, 6, 4 );
	CNodeModel nodeFrom = CNodeModel( 0, 0, 2 );

	std::shared_ptr < CPathModel > expectedValidPath = t_subGraphModelFactory.spiderNetFrom5To0PathBellmanFord;
	std::shared_ptr < CPathModel > invalidPath = t_subGraphModelFactory.spiderNetFrom0To7Path;
	
	std::shared_ptr < CPathModel > actualPath = m_bellmanFordAlgorithmTest.FindShortestPath( *( t_graphModelFactory.spiderNetGraphModel ), nodeFrom, nodeTo );
	if ( !m_CheckPtr(actualPath) )
	{
		t_testNumber += 2;

		bool expectedValue = true;
		
		bool actualValidValue = m_subGraphComparer.AreEqual(*expectedValidPath, *actualPath);
		bool actualInvalidValue = m_subGraphComparer.AreEqual(*invalidPath, *actualPath);
		
		CHECK_EQUAL( expectedValue, actualValidValue, t_failedTestNumber );
		CHECK_NOT_EQUAL( expectedValue, actualInvalidValue, t_failedTestNumber );
	}
	
	expectedValidPath.reset();
	invalidPath.reset();
	actualPath.reset();
}

void CBellmanFordAlgorithmTest::m_FindGrapeShortest0To16PathTest( void )
{
	CNodeModel nodeFrom = CNodeModel( 0, 2, 0 );
	CNodeModel nodeTo = CNodeModel( 16, 13, 14 );

	std::shared_ptr < CPathModel > expectedValidPath = t_subGraphModelFactory.grapeFrom0To16Path;
	std::shared_ptr < CPathModel > invalidPath = t_subGraphModelFactory.grapeFrom9To13Path;
	
	std::shared_ptr < CPathModel > actualPath = m_bellmanFordAlgorithmTest.FindShortestPath( *( t_graphModelFactory.grapeGraphModel ), nodeFrom, nodeTo );
	if ( !m_CheckPtr(actualPath) )
	{
		t_testNumber += 2;

		bool expectedValue = true;
		
		bool actualValidValue = m_subGraphComparer.AreEqual(*expectedValidPath, *actualPath);
		bool actualInvalidValue = m_subGraphComparer.AreEqual(*invalidPath, *actualPath);
		
		CHECK_EQUAL( expectedValue, actualValidValue, t_failedTestNumber );
		CHECK_NOT_EQUAL( expectedValue, actualInvalidValue, t_failedTestNumber );
	}

	expectedValidPath.reset();
	invalidPath.reset();
	actualPath.reset();
}

void CBellmanFordAlgorithmTest::m_FindGrapeShortest9To13PathTest( void )
{
	CNodeModel nodeFrom = CNodeModel( 9, 2, 10 );
	CNodeModel nodeTo = CNodeModel( 13, 12, 9 );

	std::shared_ptr < CPathModel > expectedValidPath = t_subGraphModelFactory.grapeFrom9To13Path;
	std::shared_ptr < CPathModel > invalidPath = t_subGraphModelFactory.doubleTriangleFrom0To5Path;
	
	std::shared_ptr < CPathModel > actualPath = m_bellmanFordAlgorithmTest.FindShortestPath( *( t_graphModelFactory.grapeGraphModel ), nodeFrom, nodeTo );
	if ( !m_CheckPtr(actualPath) )
	{
		t_testNumber += 2;

		bool expectedValue = true;
		
		bool actualValidValue = m_subGraphComparer.AreEqual(*expectedValidPath, *actualPath);
		bool actualInvalidValue = m_subGraphComparer.AreEqual(*invalidPath, *actualPath);
		
		CHECK_EQUAL( expectedValue, actualValidValue, t_failedTestNumber );
		CHECK_NOT_EQUAL( expectedValue, actualInvalidValue, t_failedTestNumber );
	}

	expectedValidPath.reset();
	invalidPath.reset();
	actualPath.reset();
}
