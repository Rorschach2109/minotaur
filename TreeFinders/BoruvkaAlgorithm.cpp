/*
 * This file is part of minotaur.
 *
 * File: BoruvkaAlgorithm.cpp
 * Brief: Implementation of boruvka algorithm class.
 *
 * Date: .07.2013
 * Author: Andrzej Korycinski
 *
 * */

#include "BoruvkaAlgorithm.h"

using namespace Minotaur;

CBoruvkaAlgorithm::CBoruvkaAlgorithm( void ) : 
	ITreeFinder()
{
	
}

CBoruvkaAlgorithm::~CBoruvkaAlgorithm( void )
{
	
}
	
std::shared_ptr < CTreeModel > CBoruvkaAlgorithm::FindMST( const IGraphModel& graphModel, const CNodeModel& nodeRoot )
{
	return nullptr;
}
