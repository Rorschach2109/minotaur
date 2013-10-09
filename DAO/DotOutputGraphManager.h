/*
 * This file is part of minotaur.
 *
 * File: DotOutputGraphManager.h
 * Brief: Declaration of dot output graph manager class.
 *
 * Date: 29.09.2013
 * Author: Andrzej Korycinski
 *
 * */

#ifndef _MINOTAUR_DOTOUTPUTGRAPHMANAGER_H_
#define _MINOTAUR_DOTOUTPUTGRAPHMANAGER_H_

#include "AbstractOutputGraphManager.h"

#include "NodeDTO.h"
#include "EdgeDTO.h"

#include <vector>

namespace Minotaur
{

class CStreamOutputGraphManager;

class CDotOutputGraphManager : public AbstractOutputGraphManager
{
	private:
		mutable CStreamOutputGraphManager* m_streamOutputGraphManager;

	protected:
		virtual void t_WriteDtoNodesEdges( const CGraphDto& dtoGraph ) const;
		virtual void t_WriteDtoGraphName( const CGraphDto& dtoGraph ) const;
		virtual void t_WriteDtoNodes( void ) const;
		virtual void t_WriteDtoEdges( void ) const;

	public:
		CDotOutputGraphManager( void ) = delete;
		explicit CDotOutputGraphManager( std::ostream& graphOutputStream );
		virtual ~CDotOutputGraphManager( void );

		virtual void WriteGraphToOutput( const CGraphDto& dtoGraph ) const;
};

} // namespace Minotaur

#endif /* _MINOTAUR_DOTOUTPUTGRAPHMANAGER_H_ */
