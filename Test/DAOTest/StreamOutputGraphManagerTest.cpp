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
#include "MinotaurTestDefines.h"
 
#include "GraphDTO.h"
#include "GraphDTOFactory.h" 
 
#include <string>
#include <sstream>

using namespace Minotaur;
 
CStreamOutputGraphManagerTest::CStreamOutputGraphManagerTest( void ) : 
	AbstractMinotaurDtoTest()
{
	//m_WriteSingleGraphToOutput();
	m_WriteMultipleGraphToOutput();
}
 
CStreamOutputGraphManagerTest::~CStreamOutputGraphManagerTest( void )
{

}

void CStreamOutputGraphManagerTest::m_WriteSingleGraphToOutput( void )
{
	t_testNumber += 2;
	
	unsigned int graphsCount = 1;
	CGraphDto dtoGraphToTest = t_dtoGraphFactory.doubleTriangleDtoGraph;
	std::stringstream expectedDtoGraphStream;
	CStreamOutputGraphManager validStreamOutputGraphManager = CStreamOutputGraphManager(expectedDtoGraphStream, graphsCount);
	
	std::string expectedDtoGraphString = "1\n\n" + t_dtoGraphFactory.doubleTriangleDtoGraphString;
	std::string invalidDtoGraphString = "1\n\n" + t_dtoGraphFactory.turtleDtoGraphString;

	validStreamOutputGraphManager.WriteGraphToOutput(dtoGraphToTest);
	std::string actualDtoGraphString = expectedDtoGraphStream.str();

	CHECK_EQUAL( expectedDtoGraphString, actualDtoGraphString, t_failedTestNumber );
	CHECK_NOT_EQUAL( invalidDtoGraphString, actualDtoGraphString, t_failedTestNumber );
}

void CStreamOutputGraphManagerTest::m_WriteMultipleGraphToOutput( void )
{
	t_testNumber += 2;
	
	unsigned int graphsCount = 2;
	CGraphDto dtoGraphToTest = t_dtoGraphFactory.doubleTriangleDtoGraph;
	std::stringstream expectedDtoGraphStream;
	CStreamOutputGraphManager validStreamOutputGraphManager = CStreamOutputGraphManager(expectedDtoGraphStream, graphsCount);
	
	std::string expectedDtoGraphString = "2\n\n" + t_dtoGraphFactory.doubleTriangleDtoGraphString + t_dtoGraphFactory.doubleTriangleDtoGraphString;
	std::string invalidDtoGraphString = "1\n\n" + t_dtoGraphFactory.doubleTriangleDtoGraphString;

	validStreamOutputGraphManager.WriteGraphToOutput(dtoGraphToTest);
	std::string actualDtoGraphString = expectedDtoGraphStream.str();

	CHECK_EQUAL( expectedDtoGraphString, actualDtoGraphString, t_failedTestNumber );
	CHECK_NOT_EQUAL( invalidDtoGraphString, actualDtoGraphString, t_failedTestNumber );
}
