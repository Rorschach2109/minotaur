/*
 * This file is part of minotaur.
 *
 * File: AbstractModelMinotaurTest.h
 * Brief: Declaration of abstract model minotaur test class.
 *
 * Date: 11.08.2013
 * Author: Andrzej Korycinski
 * 
 * */
 
#ifndef _MINOTAUR_ABSTRACTMODELMINOTAURTEST_H_
#define _MINOTAUR_ABSTRACTMODELMINOTAURTEST_H_

#include "GraphModelFactory.h"
#include "SubGraphModelFactory.h"
#include "AbstractMinotaurTest.h"

namespace Minotaur
{

class AbstractMinotaurModelTest : public AbstractMinotaurTest
{
	protected:
		CGraphModelFactory t_graphModelFactory;
		CSubGraphModelFactory t_subGraphModelFactory;

	public:
		AbstractMinotaurModelTest( void );
		virtual ~AbstractMinotaurModelTest( void ) = 0;
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_ABSTRACTMODELMINOTAURTEST_H_ */