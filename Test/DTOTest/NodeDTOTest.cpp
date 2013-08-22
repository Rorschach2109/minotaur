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
#include "MinotaurTestDefines.h"
 
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
	
	CHECK_EQUAL( expectedDtoNodeId, actualDtoNodeId, t_failedTestNumber );
	CHECK_NOT_EQUAL( invalidDtoNodeId, actualDtoNodeId, t_failedTestNumber );
}

void CNodeDtoTest::m_GetNodeXTest( void ) const
{
	++t_testNumber;
	
	unsigned int expectedDtoNodeX = 1;
	unsigned int invalidDtoNodeX = 3;
	
	unsigned int actualDtoNodeX = m_dtoTestNode.GetNodeX();
	
	CHECK_EQUAL( expectedDtoNodeX, actualDtoNodeX, t_failedTestNumber );
	CHECK_NOT_EQUAL( invalidDtoNodeX, actualDtoNodeX, t_failedTestNumber );
}

void CNodeDtoTest::m_GetNodeYTest( void ) const
{
	++t_testNumber;
	
	unsigned int expectedDtoNodeY = 2;
	unsigned int invalidDtoNodeY = 1;
	
	unsigned int actualDtoNodeY = m_dtoTestNode.GetNodeY();
	
	CHECK_EQUAL( expectedDtoNodeY, actualDtoNodeY, t_failedTestNumber );
	CHECK_NOT_EQUAL( invalidDtoNodeY, actualDtoNodeY, t_failedTestNumber );
}