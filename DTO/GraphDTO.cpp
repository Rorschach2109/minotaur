/*
 * This file is part of minotaur.
 *
 * File: GraphDTO.cpp
 * Brief: Implementation of graph dto class.
 *
 * Date: 22.07.2013
 * Author: Andrzej Korycinski
 * 
 * */
 
#include "GraphDTO.h"

using namespace Minotaur;

CGraphDto::CGraphDto( const std::vector < CNodeDto >& nodesDto, const std::vector < CEdgeDto >& edgesDto ) : 
	m_nodesDto(nodesDto),
	m_edgesDto(edgesDto)
{
	
}

CGraphDto::~CGraphDto( void )
{
	m_nodesDto.clear();
	m_edgesDto.clear();
}

const std::vector < CNodeDto >& CGraphDto::GetNodesDto ( void ) const
{
	return m_nodesDto;
}

const std::vector < CEdgeDto >& CGraphDto::GetEdgesDto ( void ) const
{
	return m_edgesDto;
}

