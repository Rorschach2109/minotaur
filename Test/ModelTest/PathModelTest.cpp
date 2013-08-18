/*
 * This file is part of minotaur.
 *
 * File: PathModelTest.cpp
 * Brief: Implementation of path model test class.
 *
 * Date: 18.08.2013
 * Author: Andrzej Korycinski
 * 
 * */

#include "PathModelTest.h"
#include "TestDefines.h"

using namespace Minotaur;

CPathModelTest::CPathModelTest( void ) : 
	AbstractMinotaurModelTest(),
	m_pathModelTest( CPathModel( *t_graphModelFactory.infinityGraphModel, t_graphModelFactory.subGraphModelFactory.infinityPath0To5 ) ) 
{
	m_VerifySubGraphTopology();
}

CPathModelTest::~CPathModelTest( void )
{
	
}

void CPathModelTest::m_VerifySubGraphTopology( void )
{
	++t_testNumber;

	bool expectedValue = true;
	
	bool actualValue = m_pathModelTest.VerifySubGraphTopology();
	
	CHECK_EQUAL( expectedValue, actualValue );
}