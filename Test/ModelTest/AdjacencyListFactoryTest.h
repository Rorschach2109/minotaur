/*
 * This file is part of minotaur.
 *
 * File: AdjacencyListFactoryTest.h
 * Brief: Declaration of adjacency list factory test class.
 *
 * Date: 11.08.2013
 * Author: Andrzej Korycinski
 * 
 * */

#ifndef _MINOTAUR_ADJACENCYLISTFACTORYTEST_H_
#define _MINOTAUR_ADJACENCYLISTFACTORYTEST_H_

#include "AbstractModelMinotaurTest.h"
#include "AdjacencyListFactory.h"

namespace Minotaur
{
	
class CAdjacencyListFactoryTest : public AbstractModelMinotaurTest
{
	private:
		CAdjacencyListFactory m_adjacencyListFactory;
	
		void m_CreateFromVectorsTest( void );
		
	public:
		CAdjacencyListFactoryTest( void );
		virtual ~CAdjacencyListFactoryTest( void );
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_ADJACENCYLISTFACTORYTEST_H_ */