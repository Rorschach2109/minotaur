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
 
#ifndef _MINOTAUR_STREAMOUTPUTGRAPHMANAGER_H_
#define _MINOTAUR_STREAMOUTPUTGRAPHMANAGER_H_

#include "AbstractOutputGraphManager.h"

#include <ostream>

namespace Minotaur
{

class CStreamOutputGraphManager : public AbstractOutputGraphManager
{
		const unsigned int m_graphsCount;
		mutable unsigned int m_graphsCounter;
		
		void m_WriteDtoGraphName( const CGraphDto& dtoGraph ) const;
		void m_WriteDtoNodes( const CGraphDto& dtoGraph ) const;
		void m_WriteDtoEdges( const CGraphDto& dtoGraph ) const;

	public:
		CStreamOutputGraphManager( void ) = delete;
		CStreamOutputGraphManager( std::ostream& graphOutputStream, const unsigned int& graphsCount );
		virtual ~CStreamOutputGraphManager( void );
		
		virtual void WriteGraphToOutput( const CGraphDto& dtoGraph ) const;
};

} // namespace Minotaur

#endif /* _MINOTAUR_STREAMOUTPUTGRAPHMANAGER_H_ */