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
		edgeDefinition squareModelMSTPrimEdges;
		edgeDefinition squareModelMSTBoruvkaEdges;
		std::shared_ptr < CTreeModel > squareModelMSTKruskal;
		std::shared_ptr < CTreeModel > squareModelMSTPrim;
		std::shared_ptr < CTreeModel > squareModelMSTBoruvka;
		
		edgeDefinition infinityModelEdgeDefinition;
		subGraphEdges infinitySubGraphModelEdges;
		subGraphNodes infinityNode1Neighbors;
		edgeDefinition infinityPath0To5;
		edgeDefinition infinityModelMSTKruskalEdges;
		edgeDefinition infinityModelMSTPrimEdges;
		edgeDefinition infinityModelMSTBoruvkaEdges;
		std::shared_ptr < CTreeModel > infinityModelMSTKruskal;
		std::shared_ptr < CTreeModel > infinityModelMSTPrim;
		std::shared_ptr < CTreeModel > infinityModelMSTBoruvka;
		
		edgeDefinition turtleModelEdgeDefinition;
		edgeDefinition turtleModelMSTKruskalEdges;
		edgeDefinition turtleModelMSTPrimEdges;
		edgeDefinition turtleModelMSTBoruvkaEdges;
		std::shared_ptr < CTreeModel > turtleModelMSTKruskal;
		std::shared_ptr < CTreeModel > turtleModelMSTPrim;
		std::shared_ptr < CTreeModel > turtleModelMSTBoruvka;
		
		edgeDefinition doubleTriangleModelEdgeDefinition;
		edgeDefinition doubleTriangleModelMSTKruskalEdges;
		edgeDefinition doubleTriangleModelMSTPrimEdges;
		edgeDefinition doubleTriangleModelMSTBoruvkaEdges;
		std::shared_ptr < CTreeModel > doubleTriangleModelMSTKruskal;
		std::shared_ptr < CTreeModel > doubleTriangleModelMSTPrim;
		std::shared_ptr < CTreeModel > doubleTriangleModelMSTBoruvka;
		
		edgeDefinition spiderNetModelMSTKruskalEdges;
		edgeDefinition spiderNetModelMSTPrimEdges;
		edgeDefinition spiderNetModelMSTBoruvkaEdges;
		std::shared_ptr < CTreeModel > spiderNetModelMSTKruskal;
		std::shared_ptr < CTreeModel > spiderNetModelMSTPrim;
		std::shared_ptr < CTreeModel > spiderNetModelMSTBoruvka;
		
		// grape graph created by Marta Konieczna
		edgeDefinition grapeModelMSTKruskalEdges;
		edgeDefinition grapeModelMSTPrimEdges;
		edgeDefinition grapeModelMSTBoruvkaEdges;
		std::shared_ptr < CTreeModel > grapeModelMSTKruskal;
		std::shared_ptr < CTreeModel > grapeModelMSTPrim;
		std::shared_ptr < CTreeModel > grapeModelMSTBoruvka;
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_SUBGRAPHMODELFACTORY_H_ */