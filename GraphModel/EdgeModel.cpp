/*
 * This file is part of minotaur.
 *
 * File: EdgeModel.cpp
 * Brief: Implementation of edge model class.
 *
 * Date: 29.07.2013
 * Author: Andrzej Korycinski
 *
 * */

#include "EdgeModel.h"

#include <limits>

using namespace Minotaur;

CEdgeModel::CEdgeModel( void ) : 
	m_nodeFromId( 0 ),
	m_nodeToId( 0 ),
	m_edgeWeight( std::numeric_limits< double >::infinity() )
{
	
}

CEdgeModel::CEdgeModel( const unsigned int& nodeFromId, const unsigned int& nodeToId, const double& edgeWeight ) :
	m_nodeFromId( nodeFromId ),
	m_nodeToId( nodeToId ),
	m_edgeWeight( edgeWeight )
{

}

CEdgeModel::~CEdgeModel( void )
{

}

bool CEdgeModel::operator==( const CEdgeModel& edgeToCompare )
{
	bool result = (
					( ( edgeToCompare.m_nodeFromId ) == this->m_nodeFromId ) &&
                    ( ( edgeToCompare.m_nodeToId ) == this->m_nodeToId ) &&
                    ( ( edgeToCompare.m_edgeWeight ) == this->m_edgeWeight )
				);
	return result;
}

const unsigned int& CEdgeModel::GetNodeFromId( void ) const
{
	return m_nodeFromId;
}

const unsigned int& CEdgeModel::GetNodeToId( void ) const
{
	return m_nodeToId;
}

const double& CEdgeModel::GetEdgeWeight( void ) const
{
	return m_edgeWeight;
}
