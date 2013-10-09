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

#include <vector>

namespace Minotaur
{

class CStreamOutputGraphManager : public AbstractOutputGraphManager
{
	private:
		const unsigned int m_graphsCount;
		mutable unsigned int m_graphsCounter;
		
		mutable std::vector < CNodeDto > m_dtoNodes;
		mutable std::vector < CEdgeDto > m_dtoEdges;
		
	protected:
		virtual void t_WriteDtoNodesEdges( const CGraphDto& dtoGraph ) const;
		virtual void t_WriteDtoGraphName( const CGraphDto& dtoGraph ) const;
		virtual void t_WriteDtoNodes( void ) const;
		virtual void t_WriteDtoEdges( void ) const;
		
	public:
		CStreamOutputGraphManager( void ) = delete;
		CStreamOutputGraphManager( std::ostream& graphOutputStream, const unsigned int& graphsCount );
		virtual ~CStreamOutputGraphManager( void );
		
		virtual void WriteGraphToOutput( const CGraphDto& dtoGraph ) const;
};

} // namespace Minotaur

#endif /* _MINOTAUR_STREAMOUTPUTGRAPHMANAGER_H_ */
