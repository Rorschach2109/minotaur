/*
 * This file is part of minotaur.
 *
 * File: NodeModel.cpp
 * Brief: Implementation of node model class.
 *
 * Date: 29.07.2013
 * Author: Andrzej Korycinski
 *
 * */

#include "NodeModel.h"

using namespace Minotaur;

CNodeModel::CNodeModel( const unsigned int& nodeId, const unsigned int& nodeX, const unsigned int& nodeY ) :
        m_nodeId( nodeId ),
        m_nodeX( nodeX ),
        m_nodeY( nodeY )
{

}

CNodeModel::~CNodeModel( void )
{

}

bool CNodeModel::operator==( const CNodeModel& nodeToCompare )
{
	bool result = (
					( ( nodeToCompare.m_nodeId ) == this->m_nodeId ) &&
                    ( ( nodeToCompare.m_nodeX ) == this->m_nodeX ) &&
                    ( ( nodeToCompare.m_nodeY ) == this->m_nodeY )
				);
	return result;
}

const unsigned int& CNodeModel::GetNodeId( void ) const
{
	return m_nodeId;
}

const unsigned int& CNodeModel::GetNodeX( void ) const
{
	return m_nodeX;
}

const unsigned int& CNodeModel::GetNodeY( void ) const
{
	return m_nodeY;
}
