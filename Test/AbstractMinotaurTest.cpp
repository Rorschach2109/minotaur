/*
 * This file is part of minotaur.
 *
 * File: AbstractMinotaurTest.cpp
 * Brief: Implementation of abstract minotaur test class.
 *
 * Date: 27.07.2013
 * Author: Andrzej Korycinski
 * 
 * */
 
#include "AbstractMinotaurTest.h"
 
using namespace Minotaur;
	
AbstractMinotaurTest::AbstractMinotaurTest( void ) :
	t_dtoGraphFactory( CGraphDtoFactory() ),
	t_testNumber(0)
{
		
}

AbstractMinotaurTest::~AbstractMinotaurTest( void )
{
	
}	

const unsigned int& AbstractMinotaurTest::GetTestNumber( void ) const
{
	return t_testNumber;
}
