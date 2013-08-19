/*
 * This file is part of minotaur.
 *
 * File: EdgeModelTest.cpp
 * Brief: Implementation of edge model test class.
 *
 * Date: 29.07.2013
 * Author: Andrzej Korycinski
 *
 * */

#include "EdgeModelTest.h"
#include "TestDefines.h"

using namespace Minotaur;

CEdgeModelTest::CEdgeModelTest( void ) :
	AbstractMinotaurModelTest(),
	m_edgeModelTest( CEdgeModel(0, 1, 10.4) )
{
	m_GetNodeFromIdTest();
	m_GetNodeToIdTest();
	m_GetEdgeWeight();
}

CEdgeModelTest::~CEdgeModelTest( void )
{

}

void CEdgeModelTest::m_GetNodeFromIdTest( void ) const
{
	++t_testNumber;

	unsigned int expectedNodeFromId = 0;
	unsigned int invalidNodeFromId = 1;

	unsigned int actualNodeFromId = m_edgeModelTest.GetNodeFromId();

	CHECK_EQUAL(expectedNodeFromId, actualNodeFromId);
	CHECK_NOT_EQUAL(invalidNodeFromId, actualNodeFromId);
}

void CEdgeModelTest::m_GetNodeToIdTest( void ) const
{
	++t_testNumber;

	unsigned int expectedNodeToId = 1;
	unsigned int invalidNodeToId = 0;

	unsigned int actualNodeToId = m_edgeModelTest.GetNodeToId();

	CHECK_EQUAL(expectedNodeToId, actualNodeToId);
	CHECK_NOT_EQUAL(invalidNodeToId, actualNodeToId);
}

void CEdgeModelTest::m_GetEdgeWeight( void ) const
{
	++t_testNumber;

	double expectedEdgeModelWeight = 10.4;
	double invalidEdgeModelWeight = 9.5;

	double actualEdgeModelWeight = m_edgeModelTest.GetEdgeWeight();

	CHECK_EQUAL(expectedEdgeModelWeight, actualEdgeModelWeight);
	CHECK_NOT_EQUAL(invalidEdgeModelWeight, actualEdgeModelWeight);
}