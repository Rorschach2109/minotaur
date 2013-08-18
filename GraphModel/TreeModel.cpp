/*
 * This file is part of minotaur.
 *
 * File: TreeModel.cpp
 * Brief: Implementation of tree model class.
 *
 * Date: 18.08.2013
 * Author: Andrzej Korycinski
 * 
 * */

#include "TreeModel.h"

#include <set>

using namespace Minotaur;

CTreeModel::CTreeModel( const IGraphModel& parentGraph, const edgeDefinition& subGraphEdges ) :
	CSubGraphModel( parentGraph, subGraphEdges )
{
	
}

CTreeModel::~CTreeModel( void )
{
	
}

bool CTreeModel::VerifySubGraphTopology( void ) const
{
	std::set < unsigned int > treeNodesId;
	for ( auto edgeDef : t_subGraphEdges )
	{
		treeNodesId.insert( edgeDef.first );
		treeNodesId.insert( edgeDef.second );
	}
	
	return ( ( ( t_parentGraph.GetNodesNumber() ) == ( treeNodesId.size() ) ) );
}
