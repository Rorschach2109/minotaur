/*
 * This file is part of minotaur.
 *
 * File: DotInputGraphManagerTest.cpp
 * Brief: Implementation of dot input graph manager test class.
 *
 * Date: 29.09.2013
 * Author: Andrzej Korycinski
 *
 * */

#include "DotInputGraphManagerTest.h"

#include "DotInputGraphManager.h"
#include "MinotaurTestDefines.h"

#include <string>
#include <sstream>

using namespace Minotaur;

CDotInputGraphManagerTest::CDotInputGraphManagerTest( void ) :
			AbstractMinotaurDtoTest()
{
	m_GetSingleNextGraphTest();
}

CDotInputGraphManagerTest::~CDotInputGraphManagerTest( void )
{

}

void CDotInputGraphManagerTest::m_GetSingleNextGraphTest( void )
{
	m_GetSquareGraphTest();
	m_GetInfinityGraphTest();
	m_GetTurtleGraphTest();
	m_GetDoubleTriangleGraphTest();
	m_GetSpiderNetGraphTest();
	m_GetGrapeGraphTest();
}

void CDotInputGraphManagerTest::m_GetSquareGraphTest( void )
{
	t_testNumber += 2;

	std::string singleGraphString = "1\n\n" + t_dtoGraphFactory.squareDotGraphString;
	std::istringstream singleGraphDot(singleGraphString);
	CGraphDto invalidDtoGraph = t_dtoGraphFactory.infinityDtoGraph;
	CDotInputGraphManager inputGraphManager = CDotInputGraphManager(singleGraphDot);

	CGraphDto actualDtoGraph = inputGraphManager.GetNextGraph();
	CGraphDto expectedDtoGraph = t_dtoGraphFactory.squareDtoGraph;

	CHECK_EQUAL(expectedDtoGraph, actualDtoGraph, t_failedTestNumber);
	CHECK_NOT_EQUAL(invalidDtoGraph, actualDtoGraph, t_failedTestNumber);
}

void CDotInputGraphManagerTest::m_GetInfinityGraphTest( void )
{
	t_testNumber += 2;

	std::string singleGraphString = "1\n\n" + t_dtoGraphFactory.infinityDotGraphString;
	std::istringstream singleGraphDot(singleGraphString);
	CGraphDto invalidDtoGraph = t_dtoGraphFactory.turtleDtoGraph;
	CDotInputGraphManager inputGraphManager = CDotInputGraphManager(singleGraphDot);

	CGraphDto actualDtoGraph = inputGraphManager.GetNextGraph();
	CGraphDto expectedDtoGraph = t_dtoGraphFactory.infinityDtoGraph;

	CHECK_EQUAL(expectedDtoGraph, actualDtoGraph, t_failedTestNumber);
	CHECK_NOT_EQUAL(invalidDtoGraph, actualDtoGraph, t_failedTestNumber);
}

void CDotInputGraphManagerTest::m_GetTurtleGraphTest( void )
{
	t_testNumber += 2;

	std::string singleGraphString = "1\n\n" + t_dtoGraphFactory.turtleDotGraphString;
	std::istringstream singleGraphDot(singleGraphString);
	CGraphDto invalidDtoGraph = t_dtoGraphFactory.grapeDtoGraph;
	CDotInputGraphManager inputGraphManager = CDotInputGraphManager(singleGraphDot);

	CGraphDto actualDtoGraph = inputGraphManager.GetNextGraph();
	CGraphDto expectedDtoGraph = t_dtoGraphFactory.turtleDtoGraph;

	CHECK_EQUAL(expectedDtoGraph, actualDtoGraph, t_failedTestNumber);
	CHECK_NOT_EQUAL(invalidDtoGraph, actualDtoGraph, t_failedTestNumber);
}

void CDotInputGraphManagerTest::m_GetDoubleTriangleGraphTest( void )
{
	t_testNumber += 2;

	std::string singleGraphString = "1\n\n" + t_dtoGraphFactory.doubleTriangleDotGraphString;
	std::istringstream singleGraphDot(singleGraphString);
	CGraphDto invalidDtoGraph = t_dtoGraphFactory.spiderNetDtoGraph;
	CDotInputGraphManager inputGraphManager = CDotInputGraphManager(singleGraphDot);

	CGraphDto actualDtoGraph = inputGraphManager.GetNextGraph();
	CGraphDto expectedDtoGraph = t_dtoGraphFactory.doubleTriangleDtoGraph;

	CHECK_EQUAL(expectedDtoGraph, actualDtoGraph, t_failedTestNumber);
	CHECK_NOT_EQUAL(invalidDtoGraph, actualDtoGraph, t_failedTestNumber);
}

void CDotInputGraphManagerTest::m_GetSpiderNetGraphTest( void )
{
	t_testNumber += 2;

	std::string singleGraphString = "1\n\n" + t_dtoGraphFactory.spiderNetDotGraphString;
	std::istringstream singleGraphDot(singleGraphString);
	CGraphDto invalidDtoGraph = t_dtoGraphFactory.doubleTriangleDtoGraph;
	CDotInputGraphManager inputGraphManager = CDotInputGraphManager(singleGraphDot);

	CGraphDto actualDtoGraph = inputGraphManager.GetNextGraph();
	CGraphDto expectedDtoGraph = t_dtoGraphFactory.spiderNetDtoGraph;

	CHECK_EQUAL(expectedDtoGraph, actualDtoGraph, t_failedTestNumber);
	CHECK_NOT_EQUAL(invalidDtoGraph, actualDtoGraph, t_failedTestNumber);
}

void CDotInputGraphManagerTest::m_GetGrapeGraphTest( void )
{
	t_testNumber += 2;

	std::string singleGraphString = "1\n\n" + t_dtoGraphFactory.grapeDotGraphString;
	std::istringstream singleGraphDot(singleGraphString);
	CGraphDto invalidDtoGraph = t_dtoGraphFactory.doubleTriangleDtoGraph;
	CDotInputGraphManager inputGraphManager = CDotInputGraphManager(singleGraphDot);

	CGraphDto actualDtoGraph = inputGraphManager.GetNextGraph();
	CGraphDto expectedDtoGraph = t_dtoGraphFactory.grapeDtoGraph;

	CHECK_EQUAL(expectedDtoGraph, actualDtoGraph, t_failedTestNumber);
	CHECK_NOT_EQUAL(invalidDtoGraph, actualDtoGraph, t_failedTestNumber);
}
