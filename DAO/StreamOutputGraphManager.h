/*
 * This file is part of minotaur.
 *
 * File: StreamOutputGraphManager.h
 * Brief: Declaration of stream output graph manager class.
 *
 * Date: 23.07.2013
 * Author: Andrzej Korycinski
 * 
 * */
 
#ifndef _MINOTAUR_STREAMOUTPUTGRAPHMAN_H_
#define _MINOTAUR_STREAMOUTPUTGRAPHMAN_H_

#include "AbstractOutputGraphManager.h"
#include "NodeDTO.h"
#include "EdgeDTO.h"

#include <ostream>
#include <vector>

namespace Minotaur
{

class CStreamOutputGraphManager : public AbstractOutputGraphManager
{
		const unsigned int m_graphsCount;
		mutable unsigned int m_graphsCounter;
		
		mutable std::vector < CNodeDto > m_dtoNodes;
		mutable std::vector < CEdgeDto > m_dtoEdges;
		
		void m_WriteDtoGraphName( const CGraphDto& dtoGraph ) const;
		
		void m_WriteDtoNodesEdges( const CGraphDto& dtoGraph) const;
		void m_WriteDtoNodes( void ) const;
		void m_WriteDtoEdges( void ) const;

	public:
		CStreamOutputGraphManager( void ) = delete;
		CStreamOutputGraphManager( std::ostream& graphOutputStream, const unsigned int& graphsCount );
		virtual ~CStreamOutputGraphManager( void );
		
		virtual void WriteGraphToOutput( const CGraphDto& dtoGraph ) const;
};

} // namespace Minotaur

#endif /* _MINOTAUR_STREAMOUTPUTGRAPHMANAGER_H_ */