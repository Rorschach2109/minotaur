/*
 * This file is part of minotaur.
 *
 * File: GraphModelFactory.h
 * Brief: Declaration of graph model factory class.
 *
 * Date: 11.08.2013
 * Author: Andrzej Korycinski
 * 
 * */
 
#ifndef _MINOTAUR_GRAPHMODELFACTORY_H_
#define _MINOTAUR_GRAPHMODELFACTORY_H_

#include "NodeModel.h"
#include "EdgeModel.h"

#include <map>
#include <vector>
#include <utility>

namespace Minotaur
{

typedef std::map < unsigned int, std::vector < std::pair < CEdgeModel, unsigned int > > > AdjacencyMap;
typedef std::map < unsigned int, CNodeModel > NodesMap;

class CGraphModelFactory
{

private:
	void m_CreateSquareModelGraph( void );
	void m_CreateSquareModelUtils( void );
	void m_CreateSquareModelNodesMap( void );
	void m_CreateSquareModelAdjacencyList( void );

	void m_CreateInfinityModelGraph( void );
	void m_CreateInfinityModelUtils( void );
	void m_CreateInfinityModelNodesMap( void );
	void m_CreateInfinityModelAdjacencyList( void );
	
	void m_CreateTurtleModelGraph( void );
	void m_CreateTurtleModelUtils( void );
	void m_CreateTurtleModelNodesMap( void );
	void m_CreateTurtleModelAdjacencyList( void );

	void m_CreateDoubleTriangleModelGraph( void );
	void m_CreateDoubleTriangleModelUtils( void );
	void m_CreateDoubleTriangleModelNodesMap( void );
	void m_CreateDoubleTriangleModelAdjacencyList( void );

public:
	CGraphModelFactory( void );
	~CGraphModelFactory( void );
	
	AdjacencyMap squareAdjacencyMap;
	NodesMap squareNodesMap;
	std::vector < CNodeModel > squareModelNodes;
	std::vector < CEdgeModel > squareModelEdges;

	AdjacencyMap infinityAdjacencyMap;
	NodesMap infinityNodesMap;
	std::vector < CNodeModel > infinityNode0Neighbors;
	std::vector < CNodeModel > infinityModelNodes;
	std::vector < CEdgeModel > infinityModelEdges;
	
	AdjacencyMap turtleAdjacencyMap;
	NodesMap turtleNodesMap;
	std::vector < CNodeModel > turtleModelNodes;
	std::vector < CEdgeModel > turtleModelEdges;
	
	AdjacencyMap doubleTriangleAdjacencyMap;
	NodesMap doubleTriangleNodesMap;
	std::vector < CNodeModel > doubleTriangleModelNodes;
	std::vector < CEdgeModel > doubleTriangleModelEdges;
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_GRAPHMODELFACTORY_H_ */