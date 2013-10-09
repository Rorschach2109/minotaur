/*
 * This file is part of minotaur.
 *
 * File: DotInputGraphManagerTest.h
 * Brief: Declaration of dot input graph manager test class.
 *
 * Date: 29.09.2013
 * Author: Andrzej Korycinski
 *
 * */

#ifndef _MINOTAUR_DOTINPUTGRAPHMANAGERTEST_H_
#define _MINOTAUR_DOTINPUTGRAPHMANAGERTEST_H_

#include "AbstractMinotaurDtoTest.h"

namespace Minotaur
{

class CDotInputGraphManagerTest : public AbstractMinotaurDtoTest
{
	private:
		void m_GetSingleNextGraphTest( void );
		void m_GetSquareGraphTest( void );
		void m_GetInfinityGraphTest( void );
		void m_GetTurtleGraphTest( void );
		void m_GetDoubleTriangleGraphTest( void );
		void m_GetSpiderNetGraphTest( void );
		void m_GetGrapeGraphTest( void );


	public:
		CDotInputGraphManagerTest( void );
		virtual ~CDotInputGraphManagerTest( void );
};

} // namespace Minotaur

#endif /* _MINOTAUR_DOTINPUTGRAPHMANAGERTEST_H_ */
