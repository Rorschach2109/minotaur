/*
 * This file is part of minotaur.
 *
 * File: AdjacencyListFactory.h
 * Brief: Declaration of adjacency list factory class.
 *
 * Date: 11.08.2013
 * Author: Andrzej Korycinski
 * 
 * */

#ifndef _MINOTAUR_ADJACENCYLISTFACTORY_H_
#define _MINOTAUR_ADJACENCYLISTFACTORY_H_

#include "NodeModel.h"
#include "EdgeModel.h"
#include "IGraphModel.h"

#include <map>
#include <vector>
#include <memory>

namespace Minotaur
{
	
class CAdjacencyListFactory
{
	private:
		void m_CreateGraphModelNodesMap( std::map < unsigned int, CNodeModel >& graphModelNodesMap, const std::vector < CNodeModel >& graphModelNodes );
		void m_CreateGraphModelAdjacencyMap( std::map < unsigned int, std::vector < std::pair < CEdgeModel, unsigned int > > >& graphModelAdjacencyMap,
												const std::vector < CEdgeModel >& graphModelEdges );
	public:
		CAdjacencyListFactory( void );
		~CAdjacencyListFactory( void );

		std::shared_ptr < IGraphModel > CreateFromVectors( const std::vector < CNodeModel >& graphModelNodes, const std::vector < CEdgeModel >& graphModelEdges );
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_ADJACENCYLISTFACTORY_H_ */