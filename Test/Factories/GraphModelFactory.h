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

#include "AdjacencyListFactory.h"
#include "NodeModel.h"
#include "IGraphModel.h"
#include "EdgeModel.h"

#include <map>
#include <vector>
#include <utility>
#include <memory>

namespace Minotaur
{

typedef std::map < unsigned int, std::vector < std::pair < CEdgeModel, unsigned int > > > AdjacencyMap;
typedef std::map < unsigned int, CNodeModel > NodesMap;

class CGraphModelFactory
{
	private:
		CAdjacencyListFactory m_adjFactory;
	
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

		void m_CreateLargeModelGraph( void );
		void m_CreateLargeModelUtils( void );
		void m_CreateLargeModelNodesMap( void );
		void m_CreateLargeModelAdjacencyList( void );

	public:
		CGraphModelFactory( void );
		virtual ~CGraphModelFactory( void );
		
		AdjacencyMap squareAdjacencyMap;
		NodesMap squareNodesMap;
		std::vector < CNodeModel > squareModelNodes;
		std::vector < CEdgeModel > squareModelEdges;
		std::shared_ptr < IGraphModel > squareGraphModel;

		AdjacencyMap infinityAdjacencyMap;
		NodesMap infinityNodesMap;
		std::vector < CNodeModel > infinityNode0Neighbors;
		std::vector < CNodeModel > infinityModelNodes;
		std::vector < CEdgeModel > infinityModelEdges;
		std::shared_ptr < IGraphModel > infinityGraphModel;
		
		AdjacencyMap turtleAdjacencyMap;
		NodesMap turtleNodesMap;
		std::vector < CNodeModel > turtleModelNodes;
		std::vector < CEdgeModel > turtleModelEdges;
		std::shared_ptr < IGraphModel > turtleGraphModel;

		AdjacencyMap doubleTriangleAdjacencyMap;
		NodesMap doubleTriangleNodesMap;
		std::vector < CNodeModel > doubleTriangleModelNodes;
		std::vector < CEdgeModel > doubleTriangleModelEdges;
		std::shared_ptr < IGraphModel > doubleTriangleGraphModel;

		AdjacencyMap largeAdjacencyMap;
		NodesMap largeNodesMap;
		std::vector < CNodeModel > largeModelNodes;
		std::vector < CEdgeModel > largeModelEdges;
		std::shared_ptr < IGraphModel > largeGraphModel;
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_GRAPHMODELFACTORY_H_ */