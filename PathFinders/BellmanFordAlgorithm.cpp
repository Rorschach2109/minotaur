/*
 * This file is part of minotaur.
 *
 * File: BellmanFordAlgorithm.cpp
 * Brief: Implementation of bellman-ford algorithm class.
 *
 * Date: .07.2013
 * Author: Andrzej Korycinski
 *
 * */

#include "BellmanFordAlgorithm.h"

using namespace Minotaur;

CBellmanFordAlgorithm::CBellmanFordAlgorithm( const CRelaxationProvider& relaxationProvider ) : 
	IPathFinder(),
	m_relaxationProvider( relaxationProvider )
{
	
}

CBellmanFordAlgorithm::~CBellmanFordAlgorithm( void )
{
	
}

std::shared_ptr < CPathModel > CBellmanFordAlgorithm::FindShortestPath( const IGraphModel& graphModel, const CNodeModel& nodeFrom, const CNodeModel& nodeTo )
{
	CNodeModel::SNodeModelLess nodeModelLess = CNodeModel::SNodeModelLess();
	CNodeModel nodeRoot = ( nodeModelLess(nodeFrom, nodeTo) )? nodeFrom : nodeTo;
	CNodeModel nodeDestination = ( nodeRoot.operator ==(nodeFrom) )? nodeTo : nodeFrom;
	
	m_relaxationProvider.Reset(graphModel, nodeRoot);
	
	for ( auto graphModelEdge : graphModel.GetGraphModelEdges() )
	{
		unsigned int currentEdgeNodeFromId = graphModelEdge.GetNodeFromId();
		unsigned int currentEdgeNodeToId = graphModelEdge.GetNodeToId();
		CNodeModel currentEdgeNodeFrom = graphModel.GetGraphModelNode(currentEdgeNodeFromId);
		CNodeModel currentEdgeNodeTo = graphModel.GetGraphModelNode(currentEdgeNodeToId);
		
		m_relaxationProvider.Relax(graphModel, currentEdgeNodeFrom, currentEdgeNodeTo);
		m_relaxationProvider.Relax(graphModel, currentEdgeNodeTo, currentEdgeNodeFrom);
	}
	
	return ( m_relaxationProvider.BuildPath(graphModel, nodeRoot, nodeDestination) );
}
