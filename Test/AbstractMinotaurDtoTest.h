/*
 * This file is part of minotaur.
 *
 * File: AbstractMinotaurDtoTest.h
 * Brief: Declaration of abstract minotaur dto test class.
 *
 * Date: 27.07.2013
 * Author: Andrzej Korycinski
 * 
 * */
 
#ifndef _MINOTAUR_ABSTRACTMINOTAURDTOTEST_H_
#define _MINOTAUR_ABSTRACTMINOTAURDTOTEST_H_

#include "AbstractMinotaurTest.h"
#include "GraphDTOFactory.h"
 
namespace Minotaur
{
	
class AbstractMinotaurDtoTest : public AbstractMinotaurTest
{
	protected:
		CGraphDtoFactory t_dtoGraphFactory;
	
	public:
		AbstractMinotaurDtoTest( void );
		virtual ~AbstractMinotaurDtoTest( void ) = 0;
};

} // namespace Minotaur
 
#endif /* _MINOTAUR_ABSTRACTMINOTAURDTOTEST_H_ */
