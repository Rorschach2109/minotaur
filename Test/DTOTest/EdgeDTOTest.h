/*
 * This file is part of minotaur.
 *
 * File: EdgeDTOTest.h
 * Brief: Declaration of edge dto test class.
 *
 * Date: 27.07.2013
 * Author: Andrzej Korycinski
 * 
 * */
 
#ifndef _MINOATAUR_EDGEDTOTEST_H_
#define _MINOATAUR_EDGEDTOTEST_H_

#include "AbstractMinotaurDtoTest.h"
#include "EdgeDTO.h"
 
namespace Minotaur
{

class CEdgeDtoTest : public AbstractMinotaurDtoTest
{
	public:
		CEdgeDtoTest( void );
		~CEdgeDtoTest( void );
		
	private:
		CEdgeDto m_dtoTestEdge;
	
		void m_GetNodeFromIdTest( void ) const;
		void m_GetNodeToIdTest( void ) const;
		void m_GetWeightTest( void ) const;
};

} // namespace Minotaur
 
#endif /* _MINOATAUR_EDGEDTOTEST_H_ */