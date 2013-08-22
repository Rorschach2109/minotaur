/*
 * This file is part of minotaur.
 *
 * File: NodeModelTest.cpp
 * Brief: Implementation of node model test class.
 *
 * Date: 29.07.2013
 * Author: Andrzej Korycinski
 *
 * */

#include "NodeModelTest.h"
#include "MinotaurTestDefines.h"

using namespace Minotaur;

CNodeModelTest::CNodeModelTest( void ) :
	AbstractMinotaurModelTest(),
	m_nodeModelTest( CNodeModel(0, 1, 2) )
{
	m_GetNodeModelIdTest();
	m_GetNodeModelXTest();
	m_GetNodeModelYTest();
}

CNodeModelTest::~CNodeModelTest( void )
{

}

void CNodeModelTest::m_GetNodeModelIdTest( void ) const
{
	t_testNumber += 2;

	unsigned int expectedNodeModelId = 0;
	unsigned int invalidNodeModelId = 1;

	unsigned int actualNodeModelId = m_nodeModelTest.GetNodeId();

	CHECK_EQUAL( expectedNodeModelId, actualNodeModelId, t_failedTestNumber );
	CHECK_NOT_EQUAL( invalidNodeModelId, actualNodeModelId, t_failedTestNumber );
}

void CNodeModelTest::m_GetNodeModelXTest( void ) const
{
	t_testNumber += 2;

	unsigned int expectedNodeModelX = 1;
	unsigned int invalidNodeModelX = 2;

	unsigned int actualNodeModelX = m_nodeModelTest.GetNodeX();

	CHECK_EQUAL( expectedNodeModelX, actualNodeModelX, t_failedTestNumber );
	CHECK_NOT_EQUAL( invalidNodeModelX, actualNodeModelX, t_failedTestNumber );
}

void CNodeModelTest::m_GetNodeModelYTest( void ) const
{
	t_testNumber += 2;

	unsigned int expectedNodeModelY = 2;
	unsigned int invalidNodeModelY = 1;

	unsigned int actualNodeModelY = m_nodeModelTest.GetNodeY();

	CHECK_EQUAL( expectedNodeModelY, actualNodeModelY, t_failedTestNumber );
	CHECK_NOT_EQUAL( invalidNodeModelY, actualNodeModelY, t_failedTestNumber );
}