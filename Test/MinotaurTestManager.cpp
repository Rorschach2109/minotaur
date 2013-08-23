/*
 * This file is part of minotaur.
 *
 * File: MinotaurTestManager.cpp
 * Brief: Implementation of minotaur test manager class.
 *
 * Date: 22.08.2013
 * Author: Andrzej Korycinski
 * 
 * */

#include "MinotaurTestManager.h"
#include "AbstractMinotaurTest.h"
#include "MinotaurTestsIncludes.h"

#include <iostream>

using namespace Minotaur;

CMinotaurTestManager::CMinotaurTestManager( void ) : 
	m_minotaurTest(nullptr),
	m_allTestNumber(0),
	m_failedTestNumber(0)
{
	
}

CMinotaurTestManager::~CMinotaurTestManager( void )
{
	m_minotaurTest.reset();
}
		
void CMinotaurTestManager::RunAllTests( void )
{
	m_RunDtoTests();
	m_RunModelTests();
}

void CMinotaurTestManager::m_RunDtoTests( void )
{
	m_RunAllDaoTests();
	m_RunAllDtoTests();
}

void CMinotaurTestManager::m_RunModelTests( void )
{
	m_RunAllGraphModelTests();
	//m_RunAllPathFindersTests();
	m_RunAllTreeFindersTests();
	m_RunAllUtilsTests();
}

void CMinotaurTestManager::DisplayTestStatistic( void )
{
	std::cout << "\n************** TEST STATISTIC **************\n";
	std::cout << "All Test Number: " << m_allTestNumber << "\n";
	std::cout << "Failed Test Number: " << m_failedTestNumber << "\n";
	std::cout << "\n********************************************\n";
}

void CMinotaurTestManager::m_RunAllDaoTests( void )
{
	m_minotaurTest = std::shared_ptr< AbstractMinotaurDtoTest >( new CStreamInputGraphManagerTest() );
	m_allTestNumber += m_minotaurTest->GetTestNumber();
	m_failedTestNumber += m_minotaurTest->GetFailedTestNumber();
	m_minotaurTest.reset();
	
	m_minotaurTest = std::shared_ptr< AbstractMinotaurDtoTest >( new CStreamOutputGraphManagerTest() );
	m_allTestNumber += m_minotaurTest->GetTestNumber();
	m_failedTestNumber += m_minotaurTest->GetFailedTestNumber();
	m_minotaurTest.reset();
}

void CMinotaurTestManager::m_RunAllDtoTests( void )
{
	m_minotaurTest = std::shared_ptr< AbstractMinotaurDtoTest >( new CEdgeDtoTest() );
	m_allTestNumber += m_minotaurTest->GetTestNumber();
	m_failedTestNumber += m_minotaurTest->GetFailedTestNumber();
	m_minotaurTest.reset();
	
	m_minotaurTest = std::shared_ptr< AbstractMinotaurDtoTest >( new CGraphDtoTest() );
	m_allTestNumber += m_minotaurTest->GetTestNumber();
	m_failedTestNumber += m_minotaurTest->GetFailedTestNumber();
	m_minotaurTest.reset();
	
	m_minotaurTest = std::shared_ptr< AbstractMinotaurDtoTest >( new CNodeDtoTest() );
	m_allTestNumber += m_minotaurTest->GetTestNumber();
	m_failedTestNumber += m_minotaurTest->GetFailedTestNumber();
	m_minotaurTest.reset();
}

void CMinotaurTestManager::m_RunAllGraphModelTests( void )
{
	m_minotaurTest = std::shared_ptr< AbstractMinotaurModelTest >( new CAdjacencyListFactoryTest() );
	m_allTestNumber += m_minotaurTest->GetTestNumber();
	m_failedTestNumber += m_minotaurTest->GetFailedTestNumber();
	m_minotaurTest.reset();
	
	m_minotaurTest = std::shared_ptr< AbstractMinotaurModelTest >( new CAdjacencyListTest() );
	m_allTestNumber += m_minotaurTest->GetTestNumber();
	m_failedTestNumber += m_minotaurTest->GetFailedTestNumber();
	m_minotaurTest.reset();
	
	m_minotaurTest = std::shared_ptr< AbstractMinotaurModelTest >( new CEdgeModelTest() );
	m_allTestNumber += m_minotaurTest->GetTestNumber();
	m_failedTestNumber += m_minotaurTest->GetFailedTestNumber();
	m_minotaurTest.reset();
	
	m_minotaurTest = std::shared_ptr< AbstractMinotaurModelTest >( new CNodeModelTest() );
	m_allTestNumber += m_minotaurTest->GetTestNumber();
	m_failedTestNumber += m_minotaurTest->GetFailedTestNumber();
	m_minotaurTest.reset();
	
	m_minotaurTest = std::shared_ptr< AbstractMinotaurModelTest >( new CPathModelTest() );
	m_allTestNumber += m_minotaurTest->GetTestNumber();
	m_failedTestNumber += m_minotaurTest->GetFailedTestNumber();
	m_minotaurTest.reset();
	
	m_minotaurTest = std::shared_ptr< AbstractMinotaurModelTest >( new CSubGraphModelTest() );
	m_allTestNumber += m_minotaurTest->GetTestNumber();
	m_failedTestNumber += m_minotaurTest->GetFailedTestNumber();
	m_minotaurTest.reset();
	
	m_minotaurTest = std::shared_ptr< AbstractMinotaurModelTest >( new CSubGraphToGraphAdapterTest() );
	m_allTestNumber += m_minotaurTest->GetTestNumber();
	m_failedTestNumber += m_minotaurTest->GetFailedTestNumber();
	m_minotaurTest.reset();
	
	m_minotaurTest = std::shared_ptr< AbstractMinotaurModelTest >( new CTreeModelTest() );
	m_allTestNumber += m_minotaurTest->GetTestNumber();
	m_failedTestNumber += m_minotaurTest->GetFailedTestNumber();
	m_minotaurTest.reset();
}

void CMinotaurTestManager::m_RunAllPathFindersTests( void )
{
	m_minotaurTest = std::shared_ptr< AbstractMinotaurModelTest >( new CBellmanFordAlgorithmTest() );
	m_allTestNumber += m_minotaurTest->GetTestNumber();
	m_failedTestNumber += m_minotaurTest->GetFailedTestNumber();
	m_minotaurTest.reset();
	
	m_minotaurTest = std::shared_ptr< AbstractMinotaurModelTest >( new CDijkstraAlgorithmTest() );
	m_allTestNumber += m_minotaurTest->GetTestNumber();
	m_failedTestNumber += m_minotaurTest->GetFailedTestNumber();
	m_minotaurTest.reset();
}

void CMinotaurTestManager::m_RunAllTreeFindersTests( void )
{
	//m_minotaurTest = std::shared_ptr< AbstractMinotaurModelTest >( new CBoruvkaAlgorithmTest() );
	//m_allTestNumber += m_minotaurTest->GetTestNumber();
	//m_failedTestNumber += m_minotaurTest->GetFailedTestNumber();
	//m_minotaurTest.reset();
	
	m_minotaurTest = std::shared_ptr< AbstractMinotaurModelTest >( new CKruskalAlgorithmTest() );
	m_allTestNumber += m_minotaurTest->GetTestNumber();
	m_failedTestNumber += m_minotaurTest->GetFailedTestNumber();
	m_minotaurTest.reset();
	
	m_minotaurTest = std::shared_ptr< AbstractMinotaurModelTest >( new CPrimAlgorithmTest() );
	m_allTestNumber += m_minotaurTest->GetTestNumber();
	m_failedTestNumber += m_minotaurTest->GetFailedTestNumber();
	m_minotaurTest.reset();
}
	
void CMinotaurTestManager::m_RunAllUtilsTests( void )
{
	m_minotaurTest = std::shared_ptr< AbstractMinotaurModelTest >( new CGraphComparerTest() );
	m_allTestNumber += m_minotaurTest->GetTestNumber();
	m_failedTestNumber += m_minotaurTest->GetFailedTestNumber();
	m_minotaurTest.reset();
	
	m_minotaurTest = std::shared_ptr< AbstractMinotaurModelTest >( new CSubGraphComparerTest() );
	m_allTestNumber += m_minotaurTest->GetTestNumber();
	m_failedTestNumber += m_minotaurTest->GetFailedTestNumber();
	m_minotaurTest.reset();
}
