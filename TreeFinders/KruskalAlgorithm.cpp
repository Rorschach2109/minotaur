/*
 * This file is part of minotaur.
 *
 * File: KruskalAlgorithm.cpp
 * Brief: Implementation of kruskal algorithm class.
 *
 * Date: .07.2013
 * Author: Andrzej Korycinski
 *
 * */

#include "KruskalAlgorithm.h"

using namespace Minotaur;

CKruskalAlgorithm::CKruskalAlgorithm( void ) : 
	ITreeFinder()
{
	
}

CKruskalAlgorithm::~CKruskalAlgorithm( void )
{
	
}
	
std::shared_ptr < CTreeModel > CKruskalAlgorithm::FindMST( const IGraphModel& graphModel, const CNodeModel& nodeRoot )
{
	return nullptr;
}
