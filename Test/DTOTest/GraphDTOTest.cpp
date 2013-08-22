/*
 * This file is part of minotaur.
 *
 * File: GraphDTOTest.cpp
 * Brief: Implementation of graph dto test class.
 *
 * Date: 28.07.2013
 * Author: Andrzej Korycinski
 * 
 * */
 
#include "GraphDTOTest.h"
#include "MinotaurTestDefines.h"

using namespace Minotaur;
 
CGraphDtoTest::CGraphDtoTest( void ) : 
	AbstractMinotaurDtoTest(),
	m_dtoGraphTest( t_dtoGraphFactory.infinityDtoGraph )
{
	m_GetDtoGraphNameTest();
	m_GetNodesDtoTest();
	m_GetEdgesDto();
}

CGraphDtoTest::~CGraphDtoTest( void )
{
	
}

void CGraphDtoTest::m_GetDtoGraphNameTest( void ) const
{
	++t_testNumber;
	
	std::string expectedGraphName = t_dtoGraphFactory.infinityName;
	std::string invalidGraphName = t_dtoGraphFactory.turtleName;
	
	std::string actualGraphName = m_dtoGraphTest.GetDtoGraphName();
	
	CHECK_EQUAL( expectedGraphName, actualGraphName, t_failedTestNumber );
	CHECK_NOT_EQUAL( invalidGraphName, actualGraphName, t_failedTestNumber );
}

void CGraphDtoTest::m_GetNodesDtoTest( void ) const
{
	++t_testNumber;
	
	std::vector < CNodeDto > expectedGraphNodes = t_dtoGraphFactory.infinityDtoNodes;
	std::vector < CNodeDto > invalidGraphNodes = t_dtoGraphFactory.turtleDtoNodes;
	
	std::vector < CNodeDto > actualGraphNodes = m_dtoGraphTest.GetNodesDto();
	
	CHECK_EQUAL( expectedGraphNodes.size(), actualGraphNodes.size(), t_failedTestNumber );
	CHECK_NOT_EQUAL( invalidGraphNodes.size(), actualGraphNodes.size(), t_failedTestNumber );

	CHECK_VECTORS_EQUAL( expectedGraphNodes, actualGraphNodes, t_failedTestNumber );
	CHECK_VECTORS_NOT_EQUAL( invalidGraphNodes, actualGraphNodes, t_failedTestNumber );
}

void CGraphDtoTest::m_GetEdgesDto( void ) const
{
	++t_testNumber;
	
	std::vector < CEdgeDto > expectedGraphEdges = t_dtoGraphFactory.infinityDtoEdges;
	std::vector < CEdgeDto > invalidGraphEdges = t_dtoGraphFactory.turtleDtoEdges;
	
	std::vector < CEdgeDto > actualGraphEdges = m_dtoGraphTest.GetEdgesDto();
	
	CHECK_EQUAL( expectedGraphEdges.size(), actualGraphEdges.size(), t_failedTestNumber );
	CHECK_NOT_EQUAL( invalidGraphEdges.size(), actualGraphEdges.size(), t_failedTestNumber );

	CHECK_VECTORS_EQUAL( expectedGraphEdges, actualGraphEdges, t_failedTestNumber );
	CHECK_VECTORS_NOT_EQUAL( invalidGraphEdges, actualGraphEdges, t_failedTestNumber );
}
