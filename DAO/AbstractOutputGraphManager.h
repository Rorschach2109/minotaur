/*
 * This file is part of minotaur.
 *
 * File: AbstractOutputGraphManager.h
 * Brief: Declaration of abstract output graph manager class.
 *
 * Date: 23.07.2013
 * Author: Andrzej Korycinski
 * 
 * */
 
#ifndef _MINOTAUR_ABSTRACTOUTPUTGRAPHMANAGER_H_
#define _MINOTAUR_ABSTRACTOUTPUTGRAPHMANAGER_H_

#include "GraphDTO.h"

#include <ostream>

namespace Minotaur
{
	
class AbstractOutputGraphManager
{
	protected:
		std::ostream& t_dtoGraphOutputStream;

	public:
		AbstractOutputGraphManager( void ) = delete;
		explicit AbstractOutputGraphManager( std::ostream& graphOutputStream );
		virtual ~AbstractOutputGraphManager( void );
		
		virtual void WriteGraphToOutput( const CGraphDto& dtoGraph ) = 0;
};

} // namespace Minotaur

#endif /* _MINOTAUR_ABSTRACTOUTPUTGRAPHMANAGER_H_ */