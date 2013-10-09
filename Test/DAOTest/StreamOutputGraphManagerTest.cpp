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
	m_WriteSingleGraphToOutput();
	m_WriteMultipleGraphToOutput();
}
 
CStreamOutputGraphManagerTest::~CStreamOutputGraphManagerTest( void )
{

}

void CStreamOutputGraphManagerTest::m_WriteSingleGraphToOutput( void )
{
	m_WriteSquareGraphTest();
	m_WriteInfinityGraphTest();
	m_WriteTurtleGraphTest();
	m_WriteDoubleTriangleGraphTest();
	m_WriteSpiderNetGraphTest();
	m_WriteGrapeGraphTest();}

void CStreamOutputGraphManagerTest::m_WriteSquareGraphTest( void )
{
	t_testNumber += 2;
	
	unsigned int graphsCount = 1;
	CGraphDto dtoGraphToTest = t_dtoGraphFactory.squareDtoGraph;
	std::stringstream expectedDtoGraphStream;
	CStreamOutputGraphManager validStreamOutputGraphManager = CStreamOutputGraphManager(expectedDtoGraphStream, graphsCount);
	
	std::string expectedDtoGraphString = "1\n\n" + t_dtoGraphFactory.squareDtoGraphString;
	std::string invalidDtoGraphString = "1\n\n" + t_dtoGraphFactory.turtleDtoGraphString;

	validStreamOutputGraphManager.WriteGraphToOutput(dtoGraphToTest);
	std::string actualDtoGraphString = expectedDtoGraphStream.str();

	CHECK_EQUAL( expectedDtoGraphString, actualDtoGraphString, t_failedTestNumber );
	CHECK_NOT_EQUAL( invalidDtoGraphString, actualDtoGraphString, t_failedTestNumber );
}

void CStreamOutputGraphManagerTest::m_WriteInfinityGraphTest( void )
{
	t_testNumber += 2;

	unsigned int graphsCount = 1;
	CGraphDto dtoGraphToTest = t_dtoGraphFactory.infinityDtoGraph;
	std::stringstream expectedDtoGraphStream;
	CStreamOutputGraphManager validStreamOutputGraphManager = CStreamOutputGraphManager(expectedDtoGraphStream, graphsCount);

	std::string expectedDtoGraphString = "1\n\n" + t_dtoGraphFactory.infinityDtoGraphString;
	std::string invalidDtoGraphString = "1\n\n" + t_dtoGraphFactory.doubleTriangleDtoGraphString;

	validStreamOutputGraphManager.WriteGraphToOutput(dtoGraphToTest);
	std::string actualDtoGraphString = expectedDtoGraphStream.str();

	CHECK_EQUAL( expectedDtoGraphString, actualDtoGraphString, t_failedTestNumber );
	CHECK_NOT_EQUAL( invalidDtoGraphString, actualDtoGraphString, t_failedTestNumber );
}

void CStreamOutputGraphManagerTest::m_WriteTurtleGraphTest( void )
{
	t_testNumber += 2;

	unsigned int graphsCount = 1;
	CGraphDto dtoGraphToTest = t_dtoGraphFactory.turtleDtoGraph;
	std::stringstream expectedDtoGraphStream;
	CStreamOutputGraphManager validStreamOutputGraphManager = CStreamOutputGraphManager(expectedDtoGraphStream, graphsCount);

	std::string expectedDtoGraphString = "1\n\n" + t_dtoGraphFactory.turtleDtoGraphString;
	std::string invalidDtoGraphString = "1\n\n" + t_dtoGraphFactory.infinityDtoGraphString;

	validStreamOutputGraphManager.WriteGraphToOutput(dtoGraphToTest);
	std::string actualDtoGraphString = expectedDtoGraphStream.str();

	CHECK_EQUAL( expectedDtoGraphString, actualDtoGraphString, t_failedTestNumber );
	CHECK_NOT_EQUAL( invalidDtoGraphString, actualDtoGraphString, t_failedTestNumber );
}

void CStreamOutputGraphManagerTest::m_WriteDoubleTriangleGraphTest( void )
{
	t_testNumber += 2;

	unsigned int graphsCount = 1;
	CGraphDto dtoGraphToTest = t_dtoGraphFactory.doubleTriangleDtoGraph;
	std::stringstream expectedDtoGraphStream;
	CStreamOutputGraphManager validStreamOutputGraphManager = CStreamOutputGraphManager(expectedDtoGraphStream, graphsCount);

	std::string expectedDtoGraphString = "1\n\n" + t_dtoGraphFactory.doubleTriangleDtoGraphString;
	std::string invalidDtoGraphString = "1\n\n" + t_dtoGraphFactory.spiderNetDtoGraphString;

	validStreamOutputGraphManager.WriteGraphToOutput(dtoGraphToTest);
	std::string actualDtoGraphString = expectedDtoGraphStream.str();

	CHECK_EQUAL( expectedDtoGraphString, actualDtoGraphString, t_failedTestNumber );
	CHECK_NOT_EQUAL( invalidDtoGraphString, actualDtoGraphString, t_failedTestNumber );
}

void CStreamOutputGraphManagerTest::m_WriteSpiderNetGraphTest( void )
{
	t_testNumber += 2;

	unsigned int graphsCount = 1;
	CGraphDto dtoGraphToTest = t_dtoGraphFactory.spiderNetDtoGraph;
	std::stringstream expectedDtoGraphStream;
	CStreamOutputGraphManager validStreamOutputGraphManager = CStreamOutputGraphManager(expectedDtoGraphStream, graphsCount);

	std::string expectedDtoGraphString = "1\n\n" + t_dtoGraphFactory.spiderNetDtoGraphString;
	std::string invalidDtoGraphString = "1\n\n" + t_dtoGraphFactory.grapeDtoGraphString;

	validStreamOutputGraphManager.WriteGraphToOutput(dtoGraphToTest);
	std::string actualDtoGraphString = expectedDtoGraphStream.str();

	CHECK_EQUAL( expectedDtoGraphString, actualDtoGraphString, t_failedTestNumber );
	CHECK_NOT_EQUAL( invalidDtoGraphString, actualDtoGraphString, t_failedTestNumber );
}

void CStreamOutputGraphManagerTest::m_WriteGrapeGraphTest( void )
{
	t_testNumber += 2;

	unsigned int graphsCount = 1;
	CGraphDto dtoGraphToTest = t_dtoGraphFactory.grapeDtoGraph;
	std::stringstream expectedDtoGraphStream;
	CStreamOutputGraphManager validStreamOutputGraphManager = CStreamOutputGraphManager(expectedDtoGraphStream, graphsCount);

	std::string expectedDtoGraphString = "1\n\n" + t_dtoGraphFactory.grapeDtoGraphString;
	std::string invalidDtoGraphString = "1\n\n" + t_dtoGraphFactory.infinityDtoGraphString;

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
