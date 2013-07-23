/*
 * This file is part of minotaur.
 *
 * File: AbstractOutputGraphManager.cpp
 * Brief: Implementation of abstract output graph manager class.
 *
 * Date: 23.07.2013
 * Author: Andrzej Korycinski
 * 
 * */
 
#include "AbstractOutputGraphManager.h"

using namespace Minotaur;

AbstractOutputGraphManager::AbstractOutputGraphManager( std::ostream& graphOutputStream ) : 
	t_dtoGraphOutputStream(graphOutputStream)
{
	
}

AbstractOutputGraphManager::~AbstractOutputGraphManager( void )
{
	
}
