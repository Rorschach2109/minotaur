/*
 * This file is part of minotaur.
 *
 * File: StreamInputGraphManager.h
 * Brief: Declaration of stream input graph manager class.
 *
 * Date: 23.07.2013
 * Author: Andrzej Korycinski
 * 
 * */
 
#ifndef _MINOTAUR_STREAMINPUTGRAPHMAN_H_
#define _MINOTAUR_STREAMINPUTGRAPHMAN_H_

#include "AbstractInputGraphManager.h"

#include "NodeDTO.h"
#include "EdgeDTO.h"

#include <istream>
#include <string>
#include <vector>

namespace Minotaur
{
	
class CStreamInputGraphManager : public AbstractInputGraphManager
{
	private:
		unsigned int m_graphsCount;
		std::string m_graphName;
		unsigned int m_nodesCount;
		unsigned int m_edgesCount;
		unsigned int m_graphCounter;

		void m_SetGraphsCount( const unsigned int& graphsCount );
		bool m_HasNextGraph( void ) const;
		void m_GetDtoNodes( std::vector < CNodeDto >& dtoNodes );
		void m_GetDtoEdges( std::vector < CEdgeDto >& dtoEdges );
		
	public:
		CStreamInputGraphManager( void ) = delete;
		CStreamInputGraphManager( std::istream& graphInputStream, const unsigned int& graphsCount );
		virtual ~CStreamInputGraphManager( void );
		
		virtual CGraphDto GetNextGraph( void );
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_STREAMINPUTGRAPHMAN_H_ */