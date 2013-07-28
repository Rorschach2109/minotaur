/*
 * This file is part of minotaur.
 *
 * File: GraphDTOTest.h
 * Brief: Declaration of graph dto test class.
 *
 * Date: 28.07.2013
 * Author: Andrzej Korycinski
 * 
 * */
 
#ifndef _MINOATAUR_GRAPHDTOTEST_H_
#define _MINOATAUR_GRAPHDTOTEST_H_

#include "AbstractMinotaurTest.h"
#include "GraphDTO.h"
 
namespace Minotaur
{

class CGraphDtoTest : public AbstractMinotaurTest
{
	public:
		CGraphDtoTest( void );
		~CGraphDtoTest( void );
		
	private:
		CGraphDto m_dtoGraphTest;
		
		void m_GetDtoGraphNameTest( void ) const;
		void m_GetNodesDtoTest( void ) const;
		void m_GetEdgesDto( void ) const;	
	
};

} // namespace Minotaur
 
#endif /* _MINOATAUR_GRAPHDTOTEST_H_ */