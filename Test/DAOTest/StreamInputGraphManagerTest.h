/*
 * This file is part of minotaur.
 *
 * File: StreamInputGraphManagerTest.h
 * Brief: Declaration of stream input graph manager test class.
 *
 * Date: 28.07.2013
 * Author: Andrzej Korycinski
 * 
 * */
 
#ifndef _MINOTAUR_STREAMINPUTGRAPHMANAGER_H_
#define _MINOTAUR_STREAMINPUTGRAPHMANAGER_H_

#include "AbstractMinotaurDtoTest.h"

namespace Minotaur
{

class CStreamInputGraphManagerTest : public AbstractMinotaurDtoTest
{
	private:
		void m_GetSingleNextGraphTest( void );
		void m_GetSquareGraphTest( void );
		void m_GetInfinityGraphTest( void );
		void m_GetTurtleGraphTest( void );
		void m_GetDoubleTriangleGraphTest( void );
		void m_GetSpiderNetGraphTest( void );
		void m_GetGrapeGraphTest( void );

		void m_GetMultipleNextGraphTest( void );
	
	public:
		CStreamInputGraphManagerTest( void );
		virtual ~CStreamInputGraphManagerTest( void );
};
 
} // namespace Minotaur

#endif /* _MINOTAUR_STREAMINPUTGRAPHMANAGER_H_ */
