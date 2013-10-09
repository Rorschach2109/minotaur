/*
 * This file is part of minotaur.
 *
 * File: AbstractDijkstraRelaxation.h
 * Brief: Declaration of abstract dijkstra relaxation class.
 *
 * Date: 26.08.2013
 * Author: Andrzej Korycinski
 *
 * */

#ifndef _MINOTAUR_ABSTRACTDIJKSTRARELAXATION_H_
#define _MINOTAUR_ABSTRACTDIJKSTRARELAXATION_H_

#include "NodeModel.h"
#include "IGraphModel.h"

#include <map>
#include <memory>

namespace Minotaur
{

class CPathModel;
	
class AbstractDijkstraRelaxation
{
	protected:
		mutable std::map < CNodeModel, CNodeModel, CNodeModel::SNodeModelLess > t_predecesors;
		
	public:
		AbstractDijkstraRelaxation( void );
		virtual ~AbstractDijkstraRelaxation( void );
		
		virtual void Reset( const IGraphModel& graphModel, const CNodeModel& nodeFrom ) const = 0;
		virtual bool Relax( const IGraphModel& graphModel, const CNodeModel& nodeFrom, const CNodeModel& nodeTo ) const = 0;
		virtual bool IsCheaper( const CNodeModel& lNode, const CNodeModel& rNode ) const = 0;
		
		std::shared_ptr < CPathModel > BuildPath( const IGraphModel& graphModel, const CNodeModel& nodeFrom, const CNodeModel& nodeTo ) const;
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_ABSTRACTDIJKSTRARELAXATION_H_ */
