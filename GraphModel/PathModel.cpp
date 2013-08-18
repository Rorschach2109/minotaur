/*
 * This file is part of minotaur.
 *
 * File: PathModel.cpp
 * Brief: Implementation of path model class.
 *
 * Date: .08.2013
 * Author: Andrzej Korycinski
 * 
 * */

#include "PathModel.h"

using namespace Minotaur;

CPathModel::CPathModel( const IGraphModel& parentGraph, const edgeDefinition& subGraphEdges ) : 
	CSubGraphModel( parentGraph, subGraphEdges )
{
	
}

CPathModel::~CPathModel( void )
{
	
}


bool CPathModel::VerifySubGraphTopology( void ) const
{
	bool topologyConfirmed = true;
	
	for ( auto edgeDef : t_subGraphEdges )
	{
		if ( ! ( t_parentGraph.ContainsEdge( edgeDef.first, edgeDef.second ) ) )
		{
			topologyConfirmed = false;
			break;
		}
	}
	
	return topologyConfirmed;
}