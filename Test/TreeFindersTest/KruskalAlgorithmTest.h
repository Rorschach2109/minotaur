/*
 * This file is part of minotaur.
 *
 * File: KruskalAlgorithmTest.h
 * Brief: Declaration of kruskal algorithm test class.
 *
 * Date: .07.2013
 * Author: Andrzej Korycinski
 *
 * */

#ifndef _MINOTAUR_KRUSKALALGORITHMTEST_H_
#define _MINOTAUR_KRUSKALALGORITHMTEST_H_

#include "AbstractMinotaurModelTest.h"
#include "KruskalAlgorithm.h"
#include "SubGraphComparer.h"
#include "TreeModel.h"

#include <memory>

namespace Minotaur
{
	
class CKruskalAlgorithmTest : public AbstractMinotaurModelTest
{
	private:
		CKruskalAlgorithm m_kruskalAlgorithmTest;
		CSubGraphComparer m_subGraphComparer;
		
		void m_FindSquareMSTTest( void );
		void m_FindInfinityMSTTest( void );
		void m_FindTurtleMSTTest( void );
		void m_FindDoubleTriangleMSTTest( void );
		void m_FindSpiderNetMSTTest( void );
		void m_FindGrapeMSTTest( void );
		
		bool m_CheckPtr( const std::shared_ptr < CTreeModel > actualTree );
	
	public:
		CKruskalAlgorithmTest( void );
		virtual ~CKruskalAlgorithmTest( void );
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_KRUSKALALGORITHMTEST_H_ */