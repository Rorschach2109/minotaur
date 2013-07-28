/*
 * This file is part of minotaur.
 *
 * File: StreamOutputGraphManagerTest.cpp
 * Brief: Implementation of stream output graph manager test class.
 *
 * Date: 28.07.2013
 * Author: Andrzej Korycinski
 * 
 * */
 
#include "StreamOutputGraphManagerTest.h"

#include "StreamOutputGraphManager.h"
#include "TestDefines.h"
 
#include "GraphDTO.h"
#include "GraphDTOFactory.h" 
 
#include <string>
#include <sstream>

using namespace Minotaur;
 
CStreamOutputGraphManagerTest::CStreamOutputGraphManagerTest( void ) : 
	AbstractMinotaurTest()
{
	m_WriteSingleGraphToOutput();
	m_WriteMultipleGraphToOutput();
}
 
CStreamOutputGraphManagerTest::~CStreamOutputGraphManagerTest( void )
{

}

void CStreamOutputGraphManagerTest::m_WriteSingleGraphToOutput( void )
{
	++t_testNumber;
	CGraphDto dtoGraphToTest = t_dtoGraphFactory.doubleTriangleDtoGraph;
	unsigned int graphsCount = 1;
	std::stringstream expectedDtoGraphStream;
	CStreamOutputGraphManager validStreamOutputGraphManager = CStreamOutputGraphManager(expectedDtoGraphStream, graphsCount);
	
	std::string expectedDtoGraphString = "1\n\n" + t_dtoGraphFactory.doubleTriangleDtoGraphString;
	std::string invalidDtoGraphString = "1\n\n" + t_dtoGraphFactory.turtleDtoGraphString;

	validStreamOutputGraphManager.WriteGraphToOutput(dtoGraphToTest);
	std::string actualDtoGraphString = expectedDtoGraphStream.str();

	CHECK_EQUAL(expectedDtoGraphString, actualDtoGraphString);
	CHECK_NOT_EQUAL(invalidDtoGraphString, actualDtoGraphString);
}

void CStreamOutputGraphManagerTest::m_WriteMultipleGraphToOutput( void )
{
	
}
