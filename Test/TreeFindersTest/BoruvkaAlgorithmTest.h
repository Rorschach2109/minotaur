/*
 * This file is part of minotaur.
 *
 * File: BoruvkaAlgorithmTest.h
 * Brief: Declaration of boruvka algorithm test class.
 *
 * Date: .07.2013
 * Author: Andrzej Korycinski
 *
 * */

#ifndef _MINOTAUR_BORUVKAALGORITHMTEST_H_
#define _MINOTAUR_BORUVKAALGORITHMTEST_H_

#include "AbstractMinotaurModelTest.h"
#include "BoruvkaAlgorithm.h"
#include "SubGraphComparer.h"

#include <memory>


namespace Minotaur
{

class CTreeModel;
	
class CBoruvkaAlgorithmTest : public AbstractMinotaurModelTest
{
	private:
		CBoruvkaAlgorithm m_boruvkaAlgorithmTest;
		CSubGraphComparer m_subGraphComparer;
		
		void m_FindSquareMSTTest( void );
		void m_FindInfinityMSTTest( void );
		void m_FindTurtleMSTTest( void );
		void m_FindDoubleTriangleMSTTest( void );
		void m_FindSpiderNetMSTTest( void );
		void m_FindGrapeMSTTest( void );
		
		bool m_CheckPtr( const std::shared_ptr < CTreeModel > actualTree );
	
	public:
		CBoruvkaAlgorithmTest( void );
		virtual ~CBoruvkaAlgorithmTest( void );
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_BORUVKAALGORITHMTEST_H_ */