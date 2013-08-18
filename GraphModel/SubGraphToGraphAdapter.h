/*
 * This file is part of minotaur.
 *
 * File: SubGraphToGraphAdapter.h
 * Brief: Declaration of subgraph to graph adapter class.
 *
 * Date: 15.08.2013
 * Author: Andrzej Korycinski
 * 
 * */

#ifndef _MINOTAUR_SUBGRAP
#define _MINOTAUR_SUBGRAP

#include "IGraphModel.h"
#include "SubGraphModel.h"

namespace Minotaur
{
	
class CSubGraphToGraphAdapter : public IGraphModel
{
	private:
		const IGraphModel& m_parentGraphModel;
		const CSubGraphModel& m_subGraphModel;
		
	public:
		CSubGraphToGraphAdapter( void ) = delete;
		CSubGraphToGraphAdapter( const CSubGraphModel& subGraphModel );
		virtual ~CSubGraphToGraphAdapter( void );
	
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

#endif /* _MINOTAUR_SUBGRAPHTOGRAPHADAPTER_H_ */