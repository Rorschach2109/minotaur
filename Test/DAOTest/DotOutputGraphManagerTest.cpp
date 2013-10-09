/*
 * This file is part of minotaur.
 *
 * File: DotOutputGraphManagerTest.cpp
 * Brief: Implementation of dot output graph manager test class.
 *
 * Date: 29.09.2013
 * Author: Andrzej Korycinski
 *
 * */

#include "DotOutputGraphManagerTest.h"

#include "MinotaurTestDefines.h"
#include "DotOutputGraphManager.h"

#include <string>
#include <sstream>

using namespace Minotaur;

CDotOutputGraphManagerTest::CDotOutputGraphManagerTest( void )
{
	m_WriteSingleGraphToOutput();
}

CDotOutputGraphManagerTest::~CDotOutputGraphManagerTest( void )
{

}

void CDotOutputGraphManagerTest::m_WriteSingleGraphToOutput( void )
{
	m_WriteSquareGraphTest();
	m_WriteInfinityGraphTest();
	m_WriteTurtleGraphTest();
	m_WriteDoubleTriangleGraphTest();
	m_WriteSpiderNetGraphTest();
	m_WriteGrapeGraphTest();
}

void CDotOutputGraphManagerTest::m_WriteSquareGraphTest( void )
{
	t_testNumber += 2;

	CGraphDto DtoGraphToTest = t_dtoGraphFactory.squareDtoGraph;
	std::stringstream expectedDtoGraphDot;
	CDotOutputGraphManager validDotOutputGraphManager = CDotOutputGraphManager(expectedDtoGraphDot);

	std::string expectedDtoGraphString = "1\n\n" + t_dtoGraphFactory.squareDtoGraphString;
	std::string invalidDtoGraphString = "1\n\n" + t_dtoGraphFactory.turtleDtoGraphString;

	validDotOutputGraphManager.WriteGraphToOutput(DtoGraphToTest);
	std::string actualDtoGraphString = expectedDtoGraphDot.str();

	CHECK_EQUAL( expectedDtoGraphString, actualDtoGraphString, t_failedTestNumber );
	CHECK_NOT_EQUAL( invalidDtoGraphString, actualDtoGraphString, t_failedTestNumber );
}

void CDotOutputGraphManagerTest::m_WriteInfinityGraphTest( void )
{
	t_testNumber += 2;

	CGraphDto DtoGraphToTest = t_dtoGraphFactory.infinityDtoGraph;
	std::stringstream expectedDtoGraphDot;
	CDotOutputGraphManager validDotOutputGraphManager = CDotOutputGraphManager(expectedDtoGraphDot);

	std::string expectedDtoGraphString = "1\n\n" + t_dtoGraphFactory.infinityDtoGraphString;
	std::string invalidDtoGraphString = "1\n\n" + t_dtoGraphFactory.doubleTriangleDtoGraphString;

	validDotOutputGraphManager.WriteGraphToOutput(DtoGraphToTest);
	std::string actualDtoGraphString = expectedDtoGraphDot.str();

	CHECK_EQUAL( expectedDtoGraphString, actualDtoGraphString, t_failedTestNumber );
	CHECK_NOT_EQUAL( invalidDtoGraphString, actualDtoGraphString, t_failedTestNumber );
}

void CDotOutputGraphManagerTest::m_WriteTurtleGraphTest( void )
{
	t_testNumber += 2;

	CGraphDto DtoGraphToTest = t_dtoGraphFactory.turtleDtoGraph;
	std::stringstream expectedDtoGraphDot;
	CDotOutputGraphManager validDotOutputGraphManager = CDotOutputGraphManager(expectedDtoGraphDot);

	std::string expectedDtoGraphString = "1\n\n" + t_dtoGraphFactory.turtleDtoGraphString;
	std::string invalidDtoGraphString = "1\n\n" + t_dtoGraphFactory.infinityDtoGraphString;

	validDotOutputGraphManager.WriteGraphToOutput(DtoGraphToTest);
	std::string actualDtoGraphString = expectedDtoGraphDot.str();

	CHECK_EQUAL( expectedDtoGraphString, actualDtoGraphString, t_failedTestNumber );
	CHECK_NOT_EQUAL( invalidDtoGraphString, actualDtoGraphString, t_failedTestNumber );
}

void CDotOutputGraphManagerTest::m_WriteDoubleTriangleGraphTest( void )
{
	t_testNumber += 2;

	CGraphDto DtoGraphToTest = t_dtoGraphFactory.doubleTriangleDtoGraph;
	std::stringstream expectedDtoGraphDot;
	CDotOutputGraphManager validDotOutputGraphManager = CDotOutputGraphManager(expectedDtoGraphDot);

	std::string expectedDtoGraphString = "1\n\n" + t_dtoGraphFactory.doubleTriangleDtoGraphString;
	std::string invalidDtoGraphString = "1\n\n" + t_dtoGraphFactory.spiderNetDtoGraphString;

	validDotOutputGraphManager.WriteGraphToOutput(DtoGraphToTest);
	std::string actualDtoGraphString = expectedDtoGraphDot.str();

	CHECK_EQUAL( expectedDtoGraphString, actualDtoGraphString, t_failedTestNumber );
	CHECK_NOT_EQUAL( invalidDtoGraphString, actualDtoGraphString, t_failedTestNumber );
}

void CDotOutputGraphManagerTest::m_WriteSpiderNetGraphTest( void )
{
	t_testNumber += 2;

	CGraphDto DtoGraphToTest = t_dtoGraphFactory.spiderNetDtoGraph;
	std::stringstream expectedDtoGraphDot;
	CDotOutputGraphManager validDotOutputGraphManager = CDotOutputGraphManager(expectedDtoGraphDot);

	std::string expectedDtoGraphString = "1\n\n" + t_dtoGraphFactory.spiderNetDtoGraphString;
	std::string invalidDtoGraphString = "1\n\n" + t_dtoGraphFactory.grapeDtoGraphString;

	validDotOutputGraphManager.WriteGraphToOutput(DtoGraphToTest);
	std::string actualDtoGraphString = expectedDtoGraphDot.str();

	CHECK_EQUAL( expectedDtoGraphString, actualDtoGraphString, t_failedTestNumber );
	CHECK_NOT_EQUAL( invalidDtoGraphString, actualDtoGraphString, t_failedTestNumber );
}

void CDotOutputGraphManagerTest::m_WriteGrapeGraphTest( void )
{
	t_testNumber += 2;

	CGraphDto DtoGraphToTest = t_dtoGraphFactory.grapeDtoGraph;
	std::stringstream expectedDtoGraphDot;
	CDotOutputGraphManager validDotOutputGraphManager = CDotOutputGraphManager(expectedDtoGraphDot);

	std::string expectedDtoGraphString = "1\n\n" + t_dtoGraphFactory.grapeDtoGraphString;
	std::string invalidDtoGraphString = "1\n\n" + t_dtoGraphFactory.infinityDtoGraphString;

	validDotOutputGraphManager.WriteGraphToOutput(DtoGraphToTest);
	std::string actualDtoGraphString = expectedDtoGraphDot.str();

	CHECK_EQUAL( expectedDtoGraphString, actualDtoGraphString, t_failedTestNumber );
	CHECK_NOT_EQUAL( invalidDtoGraphString, actualDtoGraphString, t_failedTestNumber );
}
