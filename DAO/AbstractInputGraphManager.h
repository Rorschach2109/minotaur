/*
 * This file is part of minotaur.
 *
 * File: AbstractInputGraphManager.h
 * Brief: Declaration of abstract input graph manager class.
 *
 * Date: 23.07.2013
 * Author: Andrzej Korycinski
 * 
 * */
 
#ifndef _MINOTAUR_ABSTRACTINPUTGRAPHMANAGER_H_
#define _MINOTAUR_ABSTRACTINPUTGRAPHMANAGER_H_

#include "NodeDTO.h"
#include "EdgeDTO.h"
#include "GraphDTO.h"

#include <istream>
#include <vector>

namespace Minotaur
{
	
class AbstractInputGraphManager
{
	protected:
		std::istream& t_dtoGraphInputStream;

		virtual void t_GetDtoNodes( std::vector < CNodeDto >& dtoNodes ) = 0;
		virtual void t_GetDtoEdges( std::vector < CEdgeDto >& dtoEdges ) = 0;
		
	public:
		AbstractInputGraphManager( void ) = delete;
		explicit AbstractInputGraphManager( std::istream& graphInputStream );
		virtual ~AbstractInputGraphManager( void ) = 0;
		
		virtual CGraphDto GetNextGraph( void ) = 0;
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_ABSTRACTINPUTGRAPHMANAGER_H_ */
