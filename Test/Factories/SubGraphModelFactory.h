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
#include "PathModel.h"

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
		subGraphNodes squareFrom0To3PathEdges;
		std::shared_ptr < CTreeModel > squareModelMSTKruskal;
		std::shared_ptr < CTreeModel > squareModelMSTPrim;
		std::shared_ptr < CTreeModel > squareModelMSTBoruvka;
		std::shared_ptr < CPathModel > squareFrom0To3Path;
		
		edgeDefinition infinityModelEdgeDefinition;
		subGraphEdges infinitySubGraphModelEdges;
		subGraphNodes infinityNode1Neighbors;
		subGraphNodes infinityPath0To5;
		edgeDefinition infinityModelMSTKruskalEdges;
		edgeDefinition infinityModelMSTPrimEdges;
		edgeDefinition infinityModelMSTBoruvkaEdges;
		subGraphNodes infinityFrom0To6PathEdges;
		std::shared_ptr < CTreeModel > infinityModelMSTKruskal;
		std::shared_ptr < CTreeModel > infinityModelMSTPrim;
		std::shared_ptr < CTreeModel > infinityModelMSTBoruvka;
		std::shared_ptr < CPathModel > infinityFrom0To6Path;
		
		edgeDefinition turtleModelEdgeDefinition;
		edgeDefinition turtleModelMSTKruskalEdges;
		edgeDefinition turtleModelMSTPrimEdges;
		edgeDefinition turtleModelMSTBoruvkaEdges;
		subGraphNodes turtleFrom0To3PathEdges;
		std::shared_ptr < CTreeModel > turtleModelMSTKruskal;
		std::shared_ptr < CTreeModel > turtleModelMSTPrim;
		std::shared_ptr < CTreeModel > turtleModelMSTBoruvka;
		std::shared_ptr < CPathModel > turtleFrom0To3Path;
		
		edgeDefinition doubleTriangleModelEdgeDefinition;
		edgeDefinition doubleTriangleModelMSTKruskalEdges;
		edgeDefinition doubleTriangleModelMSTPrimEdges;
		edgeDefinition doubleTriangleModelMSTBoruvkaEdges;
		subGraphNodes doubleTriangleFrom0To5PathEdges;
		subGraphNodes doubleTriangleFrom2To5PathEdges;
		std::shared_ptr < CTreeModel > doubleTriangleModelMSTKruskal;
		std::shared_ptr < CTreeModel > doubleTriangleModelMSTPrim;
		std::shared_ptr < CTreeModel > doubleTriangleModelMSTBoruvka;
		std::shared_ptr < CPathModel > doubleTriangleFrom0To5Path;
		std::shared_ptr < CPathModel > doubleTriangleFrom2To5Path;
		
		edgeDefinition spiderNetModelMSTKruskalEdges;
		edgeDefinition spiderNetModelMSTPrimEdges;
		edgeDefinition spiderNetModelMSTBoruvkaEdges;
		subGraphNodes spiderNetFrom0To7PathEdges;
		subGraphNodes spiderNetFrom5To0PathEdges;
		std::shared_ptr < CTreeModel > spiderNetModelMSTKruskal;
		std::shared_ptr < CTreeModel > spiderNetModelMSTPrim;
		std::shared_ptr < CTreeModel > spiderNetModelMSTBoruvka;
		std::shared_ptr < CPathModel > spiderNetFrom0To7Path;
		std::shared_ptr < CPathModel > spiderNetFrom5To0Path;
		
		// grape graph created by Marta Konieczna
		edgeDefinition grapeModelMSTKruskalEdges;
		edgeDefinition grapeModelMSTPrimEdges;
		edgeDefinition grapeModelMSTBoruvkaEdges;
		subGraphNodes grapeFrom0To16PathEdges;
		subGraphNodes grapeFrom9To13PathEdges;
		std::shared_ptr < CTreeModel > grapeModelMSTKruskal;
		std::shared_ptr < CTreeModel > grapeModelMSTPrim;
		std::shared_ptr < CTreeModel > grapeModelMSTBoruvka;
		std::shared_ptr < CPathModel > grapeFrom0To16Path;
		std::shared_ptr < CPathModel > grapeFrom9To13Path;
		
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_SUBGRAPHMODELFACTORY_H_ */