/*
 * This file is part of minotaur.
 *
 * File: SubGraph.h
 * Brief: Declaration of subgraph class.
 *
 * Date: 15.08.2013
 * Author: Andrzej Korycinski
 * 
 * */

#ifndef _MINOTAUR_SUBGRAPH_H_
#define _MINOTAUR_SUBGRAPH_H_

#include "IGraphModel.h"

#include <vector>
#include <utility>

namespace Minotaur
{

typedef std::vector < std::pair < unsigned int, unsigned int > > edgeDefinition;
	
class CSubGraphModel
{
	protected:
		const IGraphModel& t_parentGraph;
		edgeDefinition t_subGraphEdges;
		
	public:
		CSubGraphModel( void ) = delete;
		CSubGraphModel( const IGraphModel& parentGraph, const edgeDefinition& subGraphEdges );
		virtual ~CSubGraphModel( void );
		
		virtual bool VerifySubGraphTopology( void ) const;
		
		const IGraphModel& GetParentGraph( void ) const;
		const edgeDefinition& GetSubGraphEdges( void ) const;
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_SUBGRAPH_H_ */