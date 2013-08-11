/*
 * This file is part of minotaur.
 *
 * File: EdgeDTOTest.cpp
 * Brief: Implementation of edge dto test class.
 *
 * Date: 27.07.2013
 * Author: Andrzej Korycinski
 * 
 * */
 
#include "EdgeDTOTest.h"
#include "TestDefines.h" 

using namespace Minotaur;

CEdgeDtoTest::CEdgeDtoTest( void ) : 
	AbstractMinotaurDtoTest(),
	m_dtoTestEdge( CEdgeDto(0, 1, 2.0) )
{
	m_GetNodeFromIdTest();
	m_GetNodeToIdTest();
	m_GetWeightTest();
}

CEdgeDtoTest::~CEdgeDtoTest( void )
{
	
}

void CEdgeDtoTest::m_GetNodeFromIdTest( void ) const
{
	++t_testNumber;
	unsigned int expectedDtoNodeFromId = 0;
	unsigned int invalidDtoNodeFromId = 1;
	
	unsigned int actualDtoNodeFromId = m_dtoTestEdge.GetNodeFromId();
	
	CHECK_EQUAL(expectedDtoNodeFromId, actualDtoNodeFromId);
	CHECK_NOT_EQUAL(invalidDtoNodeFromId, actualDtoNodeFromId);
}

void CEdgeDtoTest::m_GetNodeToIdTest( void ) const
{
	++t_testNumber;
	unsigned int expectedDtoNodeToId = 1;
	unsigned int invalidDtoNodeToId = 3;

	unsigned int actualDtoNodeToId = m_dtoTestEdge.GetNodeToId();
	
	CHECK_EQUAL(expectedDtoNodeToId, actualDtoNodeToId);
	CHECK_NOT_EQUAL(invalidDtoNodeToId, actualDtoNodeToId);
}

void CEdgeDtoTest::m_GetWeightTest( void ) const
{
	++t_testNumber;
	double expectedDtoEdgeWeight = 2.0;
	double invalidDtoEdgeWeight = 2.1;
	
	double actualDtoEdgeWeight = m_dtoTestEdge.GetWeight();
	
	CHECK_EQUAL(expectedDtoEdgeWeight, actualDtoEdgeWeight);
	CHECK_NOT_EQUAL(invalidDtoEdgeWeight, actualDtoEdgeWeight);
}