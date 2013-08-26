/*
 * This file is part of minotaur.
 *
 * File: PathModel.cpp
 * Brief: Implementation of path model class.
 *
 * Date: 18.08.2013
 * Author: Andrzej Korycinski
 * 
 * */

#include "PathModel.h"

using namespace Minotaur;

CPathModel::CPathModel( const IGraphModel& parentGraph, const std::vector < CNodeModel >& nodesDefinition ) : 
	CSubGraphModel( parentGraph, m_ConvertNodes(nodesDefinition) )
{
	
}

CPathModel::~CPathModel( void )
{
	
}

edgeDefinition CPathModel::m_ConvertNodes( const std::vector < CNodeModel >& nodesDefinition )
{
	edgeDefinition edgeDef;
	for ( unsigned int nodeCounter = 1; nodeCounter != nodesDefinition.size(); ++nodeCounter )
	{
		unsigned int nodeFromId = nodesDefinition[nodeCounter - 1].GetNodeId();
		unsigned int nodeToId = nodesDefinition[nodeCounter].GetNodeId();
		edgeDef.push_back( std::make_pair( nodeFromId, nodeToId ) );
	}
	return edgeDef;
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