/*
 * This file is part of minotaur.
 *
 * File: SubGraph.cpp
 * Brief: Implementation of subgraph class.
 *
 * Date: 15.08.2013
 * Author: Andrzej Korycinski
 * 
 * */

#include "SubGraphModel.h"
#include <iostream>
using namespace Minotaur;

CSubGraphModel::CSubGraphModel( const IGraphModel& parentGraph, const edgeDefinition& subGraphEdges ) : 
	t_parentGraph( parentGraph ),
	t_subGraphEdges( subGraphEdges )
{
	
}
	
CSubGraphModel::~CSubGraphModel( void )
{
	
}
		
bool CSubGraphModel::VerifySubGraphTopology( void ) const
{
	return true;
}

const IGraphModel& CSubGraphModel::GetParentGraph( void ) const
{
	return t_parentGraph;
}

const edgeDefinition& CSubGraphModel::GetSubGraphEdges( void ) const
{
	return t_subGraphEdges;
}
