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

#include "GraphModelFactory.h"
#include "NodeModel.h"
#include "EdgeModel.h"
#include "TreeModel.h"

#include <vector>
#include <utility>
#include <memory>

namespace Minotaur
{

typedef std::vector < std::pair < unsigned int, unsigned int > > edgeDefinition;
typedef std::vector < CNodeModel > subGraphNodes;
typedef std::vector < CEdgeModel > subGraphEdges;

class CSubGraphModelFactory : public CGraphModelFactory
{
	public:
		CSubGraphModelFactory( void );
		~CSubGraphModelFactory( void );

		edgeDefinition squareModelEdgeDefinition;
		edgeDefinition squareModelMSTKruskalEdges;
		std::shared_ptr < CTreeModel > squareModelMSTKruskal;
		
		edgeDefinition infinityModelEdgeDefinition;
		subGraphEdges infinitySubGraphModelEdges;
		subGraphNodes infinityNode1Neighbors;
		edgeDefinition infinityPath0To5;
		edgeDefinition infinityModelMSTKruskalEdges;
		std::shared_ptr < CTreeModel > infinityModelMSTKruskal;
		
		edgeDefinition turtleModelEdgeDefinition;
		edgeDefinition turtleModelMSTKruskalEdges;
		std::shared_ptr < CTreeModel > turtleModelMSTKruskal;
		
		edgeDefinition doubleTriangleModelEdgeDefinition;
		edgeDefinition doubleTriangleModelMSTKruskalEdges;
		std::shared_ptr < CTreeModel > doubleTriangleModelMSTKruskal;
		
		edgeDefinition largeModelMSTKruskalEdges;
		std::shared_ptr < CTreeModel > largeModelMSTKruskal;
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_SUBGRAPHMODELFACTORY_H_ */