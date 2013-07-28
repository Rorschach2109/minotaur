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

CGraphDto::CGraphDto( const std::string& dtoGraphName, const std::vector < CNodeDto >& nodesDto, const std::vector < CEdgeDto >& edgesDto ) : 
	m_dtoGraphName(dtoGraphName),
	m_nodesDto(nodesDto),
	m_edgesDto(edgesDto)
{
	
}

CGraphDto::~CGraphDto( void )
{
	m_nodesDto.clear();
	m_edgesDto.clear();
}

bool CGraphDto::operator==( CGraphDto& dtoGraphToCompare ) const 
{
	bool result = false;
	
	if ( ( dtoGraphToCompare.m_dtoGraphName ) != m_dtoGraphName )
	{
		return result;
	}
	
	if ( ( dtoGraphToCompare.m_nodesDto.size() ) !=  ( m_nodesDto.size() ) )
	{
		return result;
	}
	
	for ( size_t nodeIndex = 0; nodeIndex < m_nodesDto.size(); ++nodeIndex )
	{
		if ( ( dtoGraphToCompare.m_nodesDto[nodeIndex] ) == ( m_nodesDto[nodeIndex] ) )
		{
		}
		else
		{
			return result;
		}
	}

	if ( ( m_edgesDto.size() ) != ( dtoGraphToCompare.m_edgesDto.size() ) )
	{
		return result;
	}
	
	for ( size_t edgeIndex = 0; edgeIndex < m_edgesDto.size(); ++edgeIndex )
	{
		if ( ( dtoGraphToCompare.m_edgesDto[edgeIndex] ) == ( m_edgesDto[edgeIndex] ) )
		{
		}
		else
		{			
			return result;
		}	
	}
		
	return true;
}

const std::string& CGraphDto::GetDtoGraphName( void ) const
{
	return m_dtoGraphName;
}

const std::vector < CNodeDto >& CGraphDto::GetNodesDto ( void ) const
{
	return m_nodesDto;
}

const std::vector < CEdgeDto >& CGraphDto::GetEdgesDto ( void ) const
{
	return m_edgesDto;
}

