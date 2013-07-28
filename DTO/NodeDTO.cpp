/*
 * This file is part of minotaur.
 *
 * File: NodeDTO.cpp
 * Brief: Implementation of node dto class.
 *
 * Date: 22.07.2013
 * Author: Andrzej Korycinski
 * 
 * */
 
 #include "NodeDTO.h"

using namespace Minotaur;

CNodeDto::CNodeDto( const unsigned int& nodeId, const unsigned int& nodeX, const unsigned int& nodeY ) : 
	m_nodeId(nodeId),
	m_nodeX(nodeX),
	m_nodeY(nodeY)
{
	
}

CNodeDto::~CNodeDto( void )
{
	
}

bool CNodeDto::operator==( const CNodeDto& nodeToCompare ) const
{
	bool result = false;
	
	result = ( nodeToCompare.m_nodeId == this->m_nodeId ) &&
				( nodeToCompare.m_nodeX == this->m_nodeX ) &&
				( nodeToCompare.m_nodeY == this->m_nodeY );
	
	return result;
}

const unsigned int& CNodeDto::GetNodeId( void ) const
{
	return m_nodeId;
}

const unsigned int& CNodeDto::GetNodeX( void ) const
{
	return m_nodeX;
}

const unsigned int& CNodeDto::GetNodeY( void ) const
{
	return m_nodeY;
}