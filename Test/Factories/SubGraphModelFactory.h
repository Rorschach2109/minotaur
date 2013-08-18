/*
 * This file is part of minotaur.
 *
 * File: SubGraphModelFactory.h
 * Brief: Declaration of subgraph model factory class.
 *
 * Date: 15.08.2013
 * Author: Andrzej Korycinski
 * 
 * */
 
#ifndef _MINOTAUR_SUBGRAPHMODELFACTORY_H_
#define _MINOTAUR_SUBGRAPHMODELFACTORY_H_

#include "NodeModel.h"
#include "EdgeModel.h"

#include <vector>
#include <utility>

namespace Minotaur
{

typedef std::vector < std::pair < unsigned int, unsigned int > > edgeDefinition;
typedef std::vector < CNodeModel > subGraphNodes;
typedef std::vector < CEdgeModel > subGraphEdges;

class CSubGraphModelFactory
{
	public:
		CSubGraphModelFactory( void );
		~CSubGraphModelFactory( void );
		
		edgeDefinition squareModelEdgeDefinition;
		
		edgeDefinition infinityModelEdgeDefinition;
		subGraphEdges infinitySubGraphModelEdges;
		subGraphNodes infinityNode1Neighbors;
		edgeDefinition infinityPath0To5;
		
		edgeDefinition turtleModelEdgeDefinition;
		
		edgeDefinition doubleTriangleModelEdgeDefinition;
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_SUBGRAPHMODELFACTORY_H_ */