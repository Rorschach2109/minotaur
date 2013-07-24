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
 
#ifndef _MINOATAUR_NODEDTOTEST_H_
#define _MINOATAUR_NODEDTOTEST_H_
 
#include "DTO/NodeDTO.h"
 
namespace Minotaur
{

class CNodeDtoTest
{
	public:
		CNodeDtoTest( void );
		~CNodeDtoTest( void );
		
	private:
		CNodeDto m_dtoTestNode;
	
		void m_GetNodeIdTest( void );
		void m_GetNodeXTest( void );
		void m_GetNodeYTest( void );
};

} // namespace Minotaur
 
#endif /* _MINOATAUR_NODEDTOTEST_H_ */