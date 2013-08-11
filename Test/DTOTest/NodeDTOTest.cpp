/*
 * This file is part of minotaur.
 *
 * File: NodeDTOTest.cpp
 * Brief: Implementation of node dto test class.
 *
 * Date: 24.07.2013
 * Author: Andrzej Korycinski
 * 
 * */
 
#include "NodeDTOTest.h"
#include "TestDefines.h"
 
using namespace Minotaur;
 
CNodeDtoTest::CNodeDtoTest( void ) : 
	AbstractMinotaurDtoTest(),
	m_dtoTestNode( CNodeDto(0, 1, 2) )
{
	m_GetNodeIdTest();
	m_GetNodeXTest();
	m_GetNodeYTest();
}

CNodeDtoTest::~CNodeDtoTest( void )
{
	
}

void CNodeDtoTest::m_GetNodeIdTest( void ) const
{
	++t_testNumber;
	unsigned int expectedDtoNodeId = 0;
	unsigned int invalidDtoNodeId = 1;
	
	unsigned int actualDtoNodeId = m_dtoTestNode.GetNodeId();
	
	CHECK_EQUAL(expectedDtoNodeId, actualDtoNodeId);
	CHECK_NOT_EQUAL(invalidDtoNodeId, actualDtoNodeId);
}

void CNodeDtoTest::m_GetNodeXTest( void ) const
{
	++t_testNumber;
	unsigned int expectedDtoNodeX = 1;
	unsigned int invalidDtoNodeX = 3;
	
	unsigned int actualDtoNodeX = m_dtoTestNode.GetNodeX();
	
	CHECK_EQUAL(expectedDtoNodeX, actualDtoNodeX);

	CHECK_NOT_EQUAL(invalidDtoNodeX, actualDtoNodeX);
}

void CNodeDtoTest::m_GetNodeYTest( void ) const
{
	++t_testNumber;
	unsigned int expectedDtoNodeY = 2;
	unsigned int invalidDtoNodeY = 1;
	
	unsigned int actualDtoNodeY = m_dtoTestNode.GetNodeY();
	
	CHECK_EQUAL(expectedDtoNodeY, actualDtoNodeY);
	CHECK_NOT_EQUAL(invalidDtoNodeY, actualDtoNodeY);
}