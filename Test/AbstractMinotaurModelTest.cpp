/*
 * This file is part of minotaur.
 *
 * File: AbstractModelMinotaurTest.cpp
 * Brief: Implementation of abstract model minotaur test class.
 *
 * Date: 11.08.2013
 * Author: Andrzej Korycinski
 * 
 * */

#include "AbstractMinotaurModelTest.h"

using namespace Minotaur;

AbstractMinotaurModelTest::AbstractMinotaurModelTest( void ) : 
	AbstractMinotaurTest(),
	t_graphModelFactory( CGraphModelFactory() )
{
	
}

AbstractMinotaurModelTest::~AbstractMinotaurModelTest( void )
{
	
}