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

#include <istream>

namespace Minotaur
{
	
class AbstractInputGraphManager
{
	protected:
		std::istream& t_dtoGraphInputStream;
		
	public:
		AbstractInputGraphManager( void ) = delete;
		explicit AbstractInputGraphManager( std::istream& graphInputStream );
		virtual ~AbstractInputGraphManager( void );
		
		virtual bool ReadGraphFromInput( void ) = 0;
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_ABSTRACTINPUTGRAPHMANAGER_H_ */