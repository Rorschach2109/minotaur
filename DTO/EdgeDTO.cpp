/*
 * This file is part of minotaur.
 *
 * File: EdgeDTO.cpp
 * Brief: Implementation of edge dto class.
 *
 * Date: 22.07.2013
 * Author: Andrzej Korycinski
 * 
 * */
 
#include "EdgeDTO.h"

using namespace Minotaur;

CEdgeDto::CEdgeDto( const unsigned int& nodeFromId, const unsigned int& nodeToId, const double& weight ) :
	m_nodeFromId(nodeFromId),
	m_nodeToId(nodeToId),
	m_weight(weight)
{
	
}

CEdgeDto::~CEdgeDto( void )
{
	
}

bool CEdgeDto::operator==( const CEdgeDto& edgeToCompare )
{
	bool result = false;
	
	result = ( edgeToCompare.m_nodeFromId == this->m_nodeFromId ) &&
				( edgeToCompare.m_nodeToId == this->m_nodeToId ) &&
				( edgeToCompare.m_weight == this->m_weight );
	
	return result;
}


const unsigned int& CEdgeDto::GetNodeFromId( void ) const
{
	return m_nodeFromId;
}

const unsigned int& CEdgeDto::GetNodeToId( void ) const
{
	return m_nodeToId;
}

const double& CEdgeDto::GetEdgeWeight( void ) const
{
	return m_weight;
}