/*
 * This file is part of minotaur.
 *
 * File: StreamInputGraphManagerTest.cpp
 * Brief: Implementation of stream input graph manager test class.
 *
 * Date: 28.07.2013
 * Author: Andrzej Korycinski
 * 
 * */
 
#include "StreamInputGraphManagerTest.h"

#include "StreamInputGraphManager.h"
#include "MinotaurTestDefines.h"

#include "GraphDTO.h"

#include <string>
#include <sstream>

using namespace Minotaur;

CStreamInputGraphManagerTest::CStreamInputGraphManagerTest( void ) : 
	AbstractMinotaurDtoTest()
{
	m_GetSingleNextGraphTest();
	m_GetMultipleNextGraphTest();
}

CStreamInputGraphManagerTest::~CStreamInputGraphManagerTest( void )
{
 
}

void CStreamInputGraphManagerTest::m_GetSingleNextGraphTest( void )
{
	m_GetSquareGraphTest();
	m_GetInfinityGraphTest();
	m_GetTurtleGraphTest();
	m_GetDoubleTriangleGraphTest();
	m_GetSpiderNetGraphTest();
	m_GetGrapeGraphTest();
}

void CStreamInputGraphManagerTest::m_GetSquareGraphTest( void )
{
	t_testNumber += 2;

	std::string singleGraphString = "1\n\n" + t_dtoGraphFactory.squareDtoGraphString;
	std::istringstream singleGraphStream(singleGraphString);
	CGraphDto invalidDtoGraph = t_dtoGraphFactory.infinityDtoGraph;
	unsigned int graphsCount = 1;
	CStreamInputGraphManager inputGraphManager = CStreamInputGraphManager(singleGraphStream, graphsCount);

	CGraphDto actualDtoGraph = inputGraphManager.GetNextGraph();
	CGraphDto expectedDtoGraph = t_dtoGraphFactory.squareDtoGraph;

	CHECK_EQUAL(expectedDtoGraph, actualDtoGraph, t_failedTestNumber);
	CHECK_NOT_EQUAL(invalidDtoGraph, actualDtoGraph, t_failedTestNumber);
}

void CStreamInputGraphManagerTest::m_GetInfinityGraphTest( void )
{
	t_testNumber += 2;

	std::string singleGraphString = "1\n\n" + t_dtoGraphFactory.infinityDtoGraphString;
	std::istringstream singleGraphStream(singleGraphString);
	CGraphDto invalidDtoGraph = t_dtoGraphFactory.turtleDtoGraph;
	unsigned int graphsCount = 1;
	CStreamInputGraphManager inputGraphManager = CStreamInputGraphManager(singleGraphStream, graphsCount);

	CGraphDto actualDtoGraph = inputGraphManager.GetNextGraph();
	CGraphDto expectedDtoGraph = t_dtoGraphFactory.infinityDtoGraph;

	CHECK_EQUAL(expectedDtoGraph, actualDtoGraph, t_failedTestNumber);
	CHECK_NOT_EQUAL(invalidDtoGraph, actualDtoGraph, t_failedTestNumber);
}

void CStreamInputGraphManagerTest::m_GetTurtleGraphTest( void )
{
	t_testNumber += 2;

	std::string singleGraphString = "1\n\n" + t_dtoGraphFactory.turtleDtoGraphString;
	std::istringstream singleGraphStream(singleGraphString);
	CGraphDto invalidDtoGraph = t_dtoGraphFactory.grapeDtoGraph;
	unsigned int graphsCount = 1;
	CStreamInputGraphManager inputGraphManager = CStreamInputGraphManager(singleGraphStream, graphsCount);

	CGraphDto actualDtoGraph = inputGraphManager.GetNextGraph();
	CGraphDto expectedDtoGraph = t_dtoGraphFactory.turtleDtoGraph;

	CHECK_EQUAL(expectedDtoGraph, actualDtoGraph, t_failedTestNumber);
	CHECK_NOT_EQUAL(invalidDtoGraph, actualDtoGraph, t_failedTestNumber);
}

void CStreamInputGraphManagerTest::m_GetDoubleTriangleGraphTest( void )
{
	t_testNumber += 2;

	std::string singleGraphString = "1\n\n" + t_dtoGraphFactory.doubleTriangleDtoGraphString;
	std::istringstream singleGraphStream(singleGraphString);
	CGraphDto invalidDtoGraph = t_dtoGraphFactory.spiderNetDtoGraph;
	unsigned int graphsCount = 1;
	CStreamInputGraphManager inputGraphManager = CStreamInputGraphManager(singleGraphStream, graphsCount);

	CGraphDto actualDtoGraph = inputGraphManager.GetNextGraph();
	CGraphDto expectedDtoGraph = t_dtoGraphFactory.doubleTriangleDtoGraph;

	CHECK_EQUAL(expectedDtoGraph, actualDtoGraph, t_failedTestNumber);
	CHECK_NOT_EQUAL(invalidDtoGraph, actualDtoGraph, t_failedTestNumber);
}

void CStreamInputGraphManagerTest::m_GetSpiderNetGraphTest( void )
{
	t_testNumber += 2;

	std::string singleGraphString = "1\n\n" + t_dtoGraphFactory.spiderNetDtoGraphString;
	std::istringstream singleGraphStream(singleGraphString);
	CGraphDto invalidDtoGraph = t_dtoGraphFactory.doubleTriangleDtoGraph;
	unsigned int graphsCount = 1;
	CStreamInputGraphManager inputGraphManager = CStreamInputGraphManager(singleGraphStream, graphsCount);

	CGraphDto actualDtoGraph = inputGraphManager.GetNextGraph();
	CGraphDto expectedDtoGraph = t_dtoGraphFactory.spiderNetDtoGraph;

	CHECK_EQUAL(expectedDtoGraph, actualDtoGraph, t_failedTestNumber);
	CHECK_NOT_EQUAL(invalidDtoGraph, actualDtoGraph, t_failedTestNumber);
}

void CStreamInputGraphManagerTest::m_GetGrapeGraphTest( void )
{
	t_testNumber += 2;

	std::string singleGraphString = "1\n\n" + t_dtoGraphFactory.grapeDtoGraphString;
	std::istringstream singleGraphStream(singleGraphString);
	CGraphDto invalidDtoGraph = t_dtoGraphFactory.doubleTriangleDtoGraph;
	unsigned int graphsCount = 1;
	CStreamInputGraphManager inputGraphManager = CStreamInputGraphManager(singleGraphStream, graphsCount);
	
	CGraphDto actualDtoGraph = inputGraphManager.GetNextGraph();
	CGraphDto expectedDtoGraph = t_dtoGraphFactory.grapeDtoGraph;
		
	CHECK_EQUAL(expectedDtoGraph, actualDtoGraph, t_failedTestNumber);
	CHECK_NOT_EQUAL(invalidDtoGraph, actualDtoGraph, t_failedTestNumber);
}


void CStreamInputGraphManagerTest::m_GetMultipleNextGraphTest( void )
{
	t_testNumber += 4;

	unsigned int graphsCount = 2;
	std::string multipleGraphString = "2\n\n" + t_dtoGraphFactory.turtleDtoGraphString + t_dtoGraphFactory.squareDtoGraphString;
	std::istringstream multipleGraphStream(multipleGraphString);
	CStreamInputGraphManager inputGraphManager = CStreamInputGraphManager(multipleGraphStream, graphsCount);

	CGraphDto actualFirstDtoGraph = inputGraphManager.GetNextGraph();
	CGraphDto expectedFirstDtoGraph = t_dtoGraphFactory.turtleDtoGraph;
	CGraphDto actualSecondDtoGraph = inputGraphManager.GetNextGraph();
	CGraphDto expectedSecondDtoGraph = t_dtoGraphFactory.squareDtoGraph;
	
	CHECK_EQUAL( expectedFirstDtoGraph, actualFirstDtoGraph, t_failedTestNumber );
	CHECK_NOT_EQUAL( expectedSecondDtoGraph, actualFirstDtoGraph, t_failedTestNumber );
	
	CHECK_EQUAL( expectedSecondDtoGraph, actualSecondDtoGraph, t_failedTestNumber );
	CHECK_NOT_EQUAL( expectedFirstDtoGraph, actualSecondDtoGraph, t_failedTestNumber );
}
