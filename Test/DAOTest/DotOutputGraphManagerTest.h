/*
 * This file is part of minotaur.
 *
 * File: DotOutputGraphManagerTest.h
 * Brief: Declaration of dot output graph manager test class.
 *
 * Date: 29.09.2013
 * Author: Andrzej Korycinski
 *
 * */

#ifndef _MINOTAUR_DOTOUTPUTGRAPHMANAGERTEST_H_
#define _MINOTAUR_DOTOUTPUTGRAPHMANAGERTEST_H_

#include "AbstractMinotaurDtoTest.h"

namespace Minotaur
{

class CDotOutputGraphManagerTest : public AbstractMinotaurDtoTest
{
	private:
		void m_WriteSingleGraphToOutput( void );
		void m_WriteSquareGraphTest( void );
		void m_WriteInfinityGraphTest( void );
		void m_WriteTurtleGraphTest( void );
		void m_WriteDoubleTriangleGraphTest( void );
		void m_WriteSpiderNetGraphTest( void );
		void m_WriteGrapeGraphTest( void );

	public:
		CDotOutputGraphManagerTest( void );
		virtual ~CDotOutputGraphManagerTest( void );
};

} // namespace Minotaur

#endif /* _MINOTAUR_DOTOUTPUTGRAPHMANAGERTEST_H_ */
