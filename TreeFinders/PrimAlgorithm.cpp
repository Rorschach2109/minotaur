/*
 * This file is part of minotaur.
 *
 * File: PrimAlgorithm.cpp
 * Brief: Implementation of prim algorithm class.
 *
 * Date: .07.2013
 * Author: Andrzej Korycinski
 *
 * */

#include "PrimAlgorithm.h"

using namespace Minotaur;

CPrimAlgorithm::CPrimAlgorithm( void ) : 
	ITreeFinder()
{
	
}

CPrimAlgorithm::~CPrimAlgorithm( void )
{
	
}
	
std::shared_ptr < CTreeModel > CPrimAlgorithm::FindMST( const IGraphModel& graphModel, const CNodeModel& nodeRoot )
{
	return nullptr;
}
