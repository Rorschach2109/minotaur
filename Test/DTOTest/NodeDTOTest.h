/*
 * This file is part of minotaur.
 *
 * File: NodeDTOTest.h
 * Brief: Declaration of node dto test class.
 *
 * Date: 24.07.2013
 * Author: Andrzej Korycinski
 * 
 * */
 
#ifndef _MINOTAUR_NODEDTOTEST_H_
#define _MINOTAUR_NODEDTOTEST_H_
 
#include "AbstractMinotaurTest.h"
#include "NodeDTO.h"
 
namespace Minotaur
{

class CNodeDtoTest : public AbstractMinotaurTest
{
	public:
		CNodeDtoTest( void );
		virtual ~CNodeDtoTest( void );
		
	private:
		CNodeDto m_dtoTestNode;
	
		void m_GetNodeIdTest( void ) const;
		void m_GetNodeXTest( void ) const;
		void m_GetNodeYTest( void ) const;
};

} // namespace Minotaur
 
#endif /* _MINOTAUR_NODEDTOTEST_H_ */