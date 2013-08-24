/*
 * This file is part of minotaur.
 *
 * File: PrimAlgorithmTest.h
 * Brief: Declaration of prim algorithm test class.
 *
 * Date: 23.08.2013
 * Author: Andrzej Korycinski
 *
 * */

#ifndef _MINOTAUR_PRIMALGORITHMTEST_H_
#define _MINOTAUR_PRIMALGORITHMTEST_H_

#include "AbstractMinotaurModelTest.h"
#include "PrimAlgorithm.h"
#include "SubGraphComparer.h"

#include <memory>


namespace Minotaur
{
	
class CTreeModel;

class CPrimAlgorithmTest : public AbstractMinotaurModelTest
{
	private:
		CPrimAlgorithm m_primAlgorithmTest;
		CSubGraphComparer m_subGraphComparer;
		
		void m_FindSquareMSTTest( void );
		void m_FindInfinityMSTTest( void );
		void m_FindTurtleMSTTest( void );
		void m_FindDoubleTriangleMSTTest( void );
		void m_FindSpiderNetMSTTest( void );
		void m_FindGrapeMSTTest( void );
		
		bool m_CheckPtr( const std::shared_ptr < CTreeModel > actualTree );
	
	public:
		CPrimAlgorithmTest( void );
		virtual ~CPrimAlgorithmTest( void );
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_PRIMALGORITHMTEST_H_ */