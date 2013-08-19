/*
 * This file is part of minotaur.
 *
 * File: AbstractMinotaurDtoTest.cpp
 * Brief: Implementation of abstract minotaur dto test class.
 *
 * Date: 27.07.2013
 * Author: Andrzej Korycinski
 * 
 * */
 
#include "AbstractMinotaurDtoTest.h"
 
using namespace Minotaur;
	
AbstractMinotaurDtoTest::AbstractMinotaurDtoTest( void ) :
	AbstractMinotaurTest(),
	t_dtoGraphFactory( CGraphDtoFactory() )
{
		
}

AbstractMinotaurDtoTest::~AbstractMinotaurDtoTest( void )
{
	
}	