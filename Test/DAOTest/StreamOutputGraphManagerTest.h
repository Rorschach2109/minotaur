/*
 * This file is part of minotaur.
 *
 * File: StreamOutputGraphManagerTest.h
 * Brief: Declaration of stream output graph manager test class.
 *
 * Date: 28.07.2013
 * Author: Andrzej Korycinski
 * 
 * */
 
#ifndef _MINOTAUR_STREAMOUTPUTGRAPHMANAGER_H_
#define _MINOTAUR_STREAMOUTPUTGRAPHMANAGER_H_

#include "AbstractMinotaurDtoTest.h"

namespace Minotaur
{

class CStreamOutputGraphManagerTest : public AbstractMinotaurDtoTest
{
	private:
		void m_WriteSingleGraphToOutput( void );
		void m_WriteMultipleGraphToOutput( void );
		
	public:
		CStreamOutputGraphManagerTest( void );
		virtual ~CStreamOutputGraphManagerTest( void );
		
};
 
} // namespace Minotaur

#endif /* _MINOTAUR_STREAMOUTPUTGRAPHMANAGER_H_ */