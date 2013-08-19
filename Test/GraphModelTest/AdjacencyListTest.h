/*
 * This file is part of minotaur.
 *
 * File: AdjacencyListTest.h
 * Brief: Declaration of adjacency list test class.
 *
 * Date: 11.08.2013
 * Author: Andrzej Korycinski
 *
 * */

#ifndef _MINOTAUR_ADJACENCYLISTTEST_H_
#define _MINOTAUR_ADJACENCYLISTTEST_H_

#include "AbstractMinotaurModelTest.h"
#include "GraphModel/AdjacencyList.h"
 
namespace Minotaur
{

class CAdjacencyListTest : public AbstractMinotaurModelTest
{
private:
	CAdjacencyList m_adjacencyList;
	
	void m_RunTest( void );
	void m_CompareTest( void );
	void m_ContainsNodeTest( void );
	void m_GetGraphModelNodeTest( void );
	void m_GetGraphModelNodesTest( void );
	void m_GetNodesNumberTest( void );
	void m_GetNeighborsTest( void );
	void m_ContainsEdgeTest( void );
	void m_GetGraphModelEdgeTest( void );
	void m_GetGraphModelEdgesTest( void );
	void m_GetEdgesNumberTest( void );
	
public:
	CAdjacencyListTest( void );
	virtual ~CAdjacencyListTest( void );
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_ADJACENCYLISTTEST_H_ */