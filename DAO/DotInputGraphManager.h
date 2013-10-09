/*
 * This file is part of minotaur.
 *
 * File: DotInputGraphManager.h
 * Brief: Declaration of dot input graph manager class.
 *
 * Date: 29.09.2013
 * Author: Andrzej Korycinski
 *
 * */

#ifndef _MINOTAUR_DOTINPUTGRAPHMANAGER_H_
#define _MINOTAUR_DOTINPUTGRAPHMANAGER_H_

#include "AbstractInputGraphManager.h"

#include <string>

namespace Minotaur
{

class CStreamInputGraphManager;

class CDotInputGraphManager : public AbstractInputGraphManager
{
	private:
		mutable std::string m_graphName;
		CStreamInputGraphManager* m_streamInputGraphManager;

		void m_SetGraphName( void );
		void m_IgnoreStyle( void );

	protected:
		virtual void t_GetDtoNodes( std::vector < CNodeDto >& dtoNodes );
		virtual void t_GetDtoEdges( std::vector < CEdgeDto >& dtoEdges );

	public:
		CDotInputGraphManager( void ) = delete;
		explicit CDotInputGraphManager( std::istream& graphInputStream );
		virtual ~CDotInputGraphManager( void );

		virtual CGraphDto GetNextGraph( void );
};

} // namespace Minotaur

#endif /* _MINOTAUR_DOTINPUTGRAPHMANAGER_H_ */
