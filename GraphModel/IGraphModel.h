/*
 * This file is part of minotaur.
 *
 * File: IGraphModel.h
 * Brief: Declaration of graph model interface.
 *
 * Date: 29.07.2013
 * Author: Andrzej Korycinski
 *
 * */

#ifndef _MINOTAUR_IGRAPHMODEL_H_
#define _MINOTAUR_IGRAPHMODEL_H_

#include "NodeModel.h"
#include "EdgeModel.h"

#include <vector>

namespace Minotaur
{

class IGraphModel
{
	public:
		IGraphModel( void ) = default;
		virtual ~IGraphModel( void )
		{
		}

		virtual bool ContainsNode( const unsigned int& nodeId ) const = 0;
		virtual CNodeModel GetGraphModelNode( const unsigned int& nodeId ) const = 0;
		virtual const std::vector < CNodeModel > GetGraphModelNodes( void ) const = 0;
		virtual unsigned int GetNodesNumber( void ) const = 0;

		virtual std::vector < CNodeModel > GetNeighbors ( const CNodeModel& nodeFrom ) const = 0;

		virtual bool ContainsEdge( const unsigned int& nodeFromId, const unsigned int& nodeToId ) const = 0;
		virtual CEdgeModel GetGraphModelEdge( const unsigned int& nodeFromId, const unsigned int& nodeToId ) const = 0;
		virtual const std::vector < CEdgeModel > GetGraphModelEdges( void ) const = 0;
		virtual unsigned int GetEdgesNumber( void ) const = 0;
};

} // namespace Minotaur

#endif /* _MINOTAUR_GRAPHMODEL_H_ */