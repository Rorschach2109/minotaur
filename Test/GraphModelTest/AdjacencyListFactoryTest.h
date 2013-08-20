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

#include "AbstractMinotaurModelTest.h"
#include "AbstractMinotaurDtoTest.h"
#include "AdjacencyListFactory.h"

namespace Minotaur
{
	
class CAdjacencyListFactoryTest : public AbstractMinotaurModelTest, public AbstractMinotaurDtoTest
{
	private:
		CAdjacencyListFactory m_adjacencyListFactory;
	
		void m_CreateFromVectorsTest( void );
		void m_CreateSquareFromDtoTest( void );
		void m_CreateInfinityFromDtoTest( void );
		void m_CreateTurtleFromDtoTest( void );
		void m_CreateDoubleTriangleFromDtoTest( void );
		
	public:
		CAdjacencyListFactoryTest( void );
		virtual ~CAdjacencyListFactoryTest( void );
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_ADJACENCYLISTFACTORYTEST_H_ */