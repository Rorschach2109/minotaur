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

#include "AbstractModelMinotaurTest.h"

using namespace Minotaur;

AbstractModelMinotaurTest::AbstractModelMinotaurTest( void ) : 
	AbstractMinotaurTest(),
	t_graphModelFactory( CGraphModelFactory() )
{
	
}

AbstractModelMinotaurTest::~AbstractModelMinotaurTest( void )
{
	
}