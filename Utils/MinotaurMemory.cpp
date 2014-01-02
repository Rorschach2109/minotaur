/*
 * This file is part of minotaur.
 *
 * File: MinotaurMemory.cpp
 * Brief: Implementation of minotaur memory class.
 *
 * Date: 02.01.2014
 * Author: Andrzej Korycinski
 * 
 * */

#include "MinotaurMemory.h"

#include <fstream>
#include <unistd.h>

using namespace Minotaur;

CMinotaurMemory::CMinotaurMemory( void ) : 
	m_residentSetSizeMemory( 0.0 ),
	m_sharedMemorySize( 0.0 ),
	m_privateMemorySize( 0.0 )
{

}

CMinotaurMemory::~CMinotaurMemory( void )
{
	
}

CMinotaurMemory CMinotaurMemory::operator-( const CMinotaurMemory& minotaurMemory ) const
{
	CMinotaurMemory resultMinotaurMemory;
	
	resultMinotaurMemory.m_residentSetSizeMemory = this->m_residentSetSizeMemory - minotaurMemory.m_residentSetSizeMemory;
	resultMinotaurMemory.m_sharedMemorySize = this->m_sharedMemorySize - minotaurMemory.m_sharedMemorySize;
	resultMinotaurMemory.m_privateMemorySize = resultMinotaurMemory.m_residentSetSizeMemory - resultMinotaurMemory.m_sharedMemorySize;
	
	return resultMinotaurMemory;
}

void CMinotaurMemory::SetMemory( void )
{
	int tSize = 0;
	int resident = 0;
	int share = 0;
	
	std::ifstream buffer;
	
	buffer.open("/proc/self/statm");
	
	buffer >> tSize >> resident >> share;
	
	buffer.close();

	long page_size_kb = sysconf(_SC_PAGE_SIZE) / 1024; // in case x86-64 is configured to use 2MB pages
	
	m_residentSetSizeMemory = resident * page_size_kb;
	m_sharedMemorySize = share * page_size_kb;
	m_privateMemorySize = m_residentSetSizeMemory - m_sharedMemorySize;
}

double CMinotaurMemory::GetResidentSetSizeMemory( void ) const
{
	return m_residentSetSizeMemory;
}

double CMinotaurMemory::GetSharedMemorySize( void ) const
{
	return m_sharedMemorySize;
}
		
double CMinotaurMemory::GetPrivateMemorySize( void ) const
{
	return m_privateMemorySize;
}