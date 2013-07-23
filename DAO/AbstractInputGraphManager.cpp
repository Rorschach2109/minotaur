/*
 * This file is part of minotaur.
 *
 * File: AbstractInputGraphManager.cpp
 * Brief: Implementation of abstract input graph manager class.
 *
 * Date: 23.07.2013
 * Author: Andrzej Korycinski
 * 
 * */
 
#include "AbstractInputGraphManager.h"

using namespace Minotaur;

AbstractInputGraphManager::AbstractInputGraphManager( std::istream& graphInputStream ) : 
	t_dtoGraphInputStream(graphInputStream)
{
	
}

AbstractInputGraphManager::~AbstractInputGraphManager( void )
{
	
}
