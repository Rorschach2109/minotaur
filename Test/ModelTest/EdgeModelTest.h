/*
 * This file is part of minotaur.
 *
 * File: EdgeModelTest.h
 * Brief: Declaration of edge model test class.
 *
 * Date: 29.07.2013
 * Author: Andrzej Korycinski
 *
 * */

#include "AbstractModelMinotaurTest.h"
#include "EdgeModel.h"

#ifndef _MINOTAUR_EDGEMODELTEST_H_
#define _MINOTAUR_EDGEMODELTEST_H_

namespace Minotaur
{

class CEdgeModelTest : public AbstractModelMinotaurTest
{
	private:
		CEdgeModel m_edgeModelTest;

		void m_GetNodeFromIdTest( void ) const;
		void m_GetNodeToIdTest( void ) const;
		void m_GetEdgeWeight( void ) const;

	public:
		CEdgeModelTest( void );
		virtual ~CEdgeModelTest( void );
};

} // namespace Minotaur

#endif /* _MINOTAUR_EDGEMODELTEST_H_ */
