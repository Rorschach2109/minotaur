/*
 * This file is part of minotaur.
 *
 * File: GraphDTO.h
 * Brief: Declaration of graph dto class.
 *
 * Date: 22.07.2013
 * Author: Andrzej Korycinski
 * 
 * */
 
#ifndef _MINOTAUR_GRAPHDTO_H_
#define _MINOTAUR_GRAPHDTO_H_

#include "NodeDTO.h"
#include "EdgeDTO.h"

#include <string>
#include <vector>

namespace Minotaur
{
	
class CGraphDto
{
	private:
		std::string m_dtoGraphName;
		std::vector < CNodeDto > m_nodesDto;
		std::vector < CEdgeDto > m_edgesDto;
		
	public:
		CGraphDto( void ) = delete;
		CGraphDto( const std::string& graphName, const std::vector < CNodeDto >& nodesDto, const std::vector < CEdgeDto >& edgesDto );
		~CGraphDto( void );
		
		bool operator==( CGraphDto& dtoGraphToCompare ) const;
		
		const std::string& GetDtoGraphName( void ) const;
		const std::vector < CNodeDto >& GetNodesDto ( void ) const;
		const std::vector < CEdgeDto >& GetEdgesDto ( void ) const;
};

} // namespace Minotaur

#endif /* _MINOTAUR_GRAPHDTO_H_ */