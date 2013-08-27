/*
 * This file is part of minotaur.
 *
 * File: RelaxationProvider.cpp
 * Brief: Implementation of relaxation provider class.
 *
 * Date: 26.08.2013
 * Author: Andrzej Korycinski
 *
 * */

#include "RelaxationProvider.h"
#include "EdgeModel.h"

#include <limits>

using namespace Minotaur;

CRelaxationProvider::CRelaxationProvider( void ) : 
	AbstractDijkstraRelaxation()
{
	
}

CRelaxationProvider::~CRelaxationProvider( void )
{
	
}

void CRelaxationProvider::Reset( const IGraphModel& graphModel, const CNodeModel& nodeFrom ) const
{
	for ( auto graphNode : graphModel.GetGraphModelNodes() )
	{
		double labelValue = ( graphNode.operator ==(nodeFrom) )? 0.0 : std::numeric_limits< double >::infinity();
		m_aggregratedLabels[graphNode] = labelValue;
		t_predecesors[graphNode] = graphNode;
	}
	
	m_specMetrics.clear();
	
	for ( auto graphNode : graphModel.GetGraphModelNodes() )
	{
		unsigned int currentNodeId = graphNode.GetNodeId();
		m_specMetrics[currentNodeId] = std::numeric_limits< double >::infinity();
	}
	
	unsigned int nodeFromId = nodeFrom.GetNodeId();
	m_specMetrics[nodeFromId] = 0.0;
}

bool CRelaxationProvider::Relax( const IGraphModel& graphModel, const CNodeModel& nodeFrom, const CNodeModel& nodeTo ) const
{
	bool relaxResult = false;
	unsigned int nodeFromId = nodeFrom.GetNodeId();
	unsigned int nodeToId = nodeTo.GetNodeId();
	
	CEdgeModel candidateEdge = graphModel.GetGraphModelEdge(nodeFromId, nodeToId);
	double candidateDistance = m_aggregratedLabels[nodeFrom] + candidateEdge.GetEdgeWeight();
	
	if ( candidateDistance < m_aggregratedLabels[nodeTo] )
	{
		m_aggregratedLabels[nodeTo] = candidateDistance;
		t_predecesors[nodeTo] = nodeFrom;
		
		m_specMetrics[nodeToId] = m_specMetrics[nodeFromId] + candidateEdge.GetEdgeWeight();
		
		relaxResult = true;
	}
	
	return relaxResult;
}

bool CRelaxationProvider::IsCheaper( const CNodeModel& lNode, const CNodeModel& rNode ) const
{
	bool lIsCheaper = ( m_aggregratedLabels.at(lNode) < m_aggregratedLabels.at(rNode) );
	return lIsCheaper;
}

const std::map < unsigned int, double >& CRelaxationProvider::GetSpecMetrics( void ) const
{
	return m_specMetrics;
}
