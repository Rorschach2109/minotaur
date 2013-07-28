/*
 * This file is part of minotaur.
 *
 * File: AbstractMinotaurTest.h
 * Brief: Declaration of abstract minotaur test class.
 *
 * Date: 27.07.2013
 * Author: Andrzej Korycinski
 * 
 * */
 
#ifndef _MINOTAUR_ABSTRACTMINOTAURTEST_H_
#define _MINOTAUR_ABSTRACTMINOTAURTEST_H_

#include "GraphDTOFactory.h"
 
namespace Minotaur
{
	
class AbstractMinotaurTest
{
	protected:
		CGraphDtoFactory t_dtoGraphFactory;
		mutable unsigned int t_testNumber;
	
	public:
		AbstractMinotaurTest( void );
		virtual ~AbstractMinotaurTest( void ) = 0;
	
		const unsigned int& GetTestNumber( void ) const;
};

} // namespace Minotaur
 
#endif /* _MINOTAUR_ABSTRACTMINOTAURTEST_H_ */
