/*
 * This file is part of minotaur.
 *
 * File: AdjacencyList.h
 * Brief: Declaration of adjacency list class.
 *
 * Date: 29.07.2013
 * Author: Andrzej Korycinski
 *
 * */

#ifndef _MINOTAUR_ADJACENCYLIST_H_
#define _MINOTAUR_ADJACENCYLIST_H_

#include "IGraphModel.h"
#include "NodeModel.h"
#include "EdgeModel.h"

#include <map>
#include <vector>
#include <utility>

namespace Minotaur
{

typedef std::map < unsigned int, std::vector < std::pair < CEdgeModel, unsigned int > > > AdjacencyMap;
typedef std::map < unsigned int, CNodeModel > NodesMap;

class CAdjacencyList : public IGraphModel
{
	private:
		AdjacencyMap m_adjacencyMap;
		NodesMap m_nodesMap;

		bool m_CompareNodesMaps( NodesMap& toCompareNodesMap );
		bool m_CompareAdjacencyMaps( AdjacencyMap& toCompareAdjacencyMap );

	public:
		CAdjacencyList( void ) = delete;
		CAdjacencyList( const AdjacencyMap& adjacencyMap, const NodesMap& nodesMap );
		virtual ~CAdjacencyList( void );
		
		bool operator==( CAdjacencyList& adjacencyListToCompare );
		
		virtual bool ContainsNode( const unsigned int& nodeId ) const;
		virtual CNodeModel GetGraphModelNode( const unsigned int& nodeId ) const;
		virtual const std::vector < CNodeModel > GetGraphModelNodes( void ) const;
		virtual unsigned int GetNodesNumber( void ) const;

		virtual std::vector < CNodeModel > GetNeighbors ( const CNodeModel& nodeFrom ) const;

		virtual bool ContainsEdge( const unsigned int& nodeFromId, const unsigned int& nodeToId ) const;
		virtual CEdgeModel GetGraphModelEdge( const unsigned int& nodeFromId, const unsigned int& nodeToId ) const;
		virtual const std::vector < CEdgeModel > GetGraphModelEdges( void ) const;
		virtual unsigned int GetEdgesNumber( void ) const;

};

} // namespace Minotaur

#endif /* _MINOTAUR_ADJACENCYLIST_H_ */