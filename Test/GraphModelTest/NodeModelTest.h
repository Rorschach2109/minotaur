/*
 * This file is part of minotaur.
 *
 * File: NodeModelTest.h
 * Brief: Declaration of node model test class.
 *
 * Date: 29.07.2013
 * Author: Andrzej Korycinski
 *
 * */

#ifndef _MINOTAUR_NODEMODELTEST_H_
#define _MINOTAUR_NODEMODELTEST_H_

#include "AbstractMinotaurModelTest.h"
#include "NodeModel.h"

namespace Minotaur
{

class CNodeModelTest : public AbstractMinotaurModelTest
{
	private:
		CNodeModel m_nodeModelTest;

		void m_GetNodeModelIdTest( void ) const;
		void m_GetNodeModelXTest( void ) const;
		void m_GetNodeModelYTest( void ) const;

	public:
		CNodeModelTest( void );
		virtual ~CNodeModelTest( void );
};

} // namespace Minotaur

#endif /* _MINOTAUR_NODEMODELTEST_H_ */