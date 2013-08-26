/*
 * This file is part of minotaur.
 *
 * File: RelaxationProvider.h
 * Brief: Declaration of relaxation provider class.
 *
 * Date: 26.08.2013
 * Author: Andrzej Korycinski
 *
 * */

#ifndef _MINOTAUR_RELAXATIONPROVIDER_H_
#define _MINOTAUR_RELAXATIONPROVIDER_H_

#include "AbstractDijkstraRelaxation.h"

#include <map>
#include <vector>

namespace Minotaur
{
	
class CRelaxationProvider : public AbstractDijkstraRelaxation
{
	private:
		mutable std::map < CNodeModel, double, CNodeModel::SNodeModelLess > m_aggregratedLabels;
		mutable std::map < unsigned int, double > m_specMetrics;
		
	public:
		CRelaxationProvider( void );
		virtual ~CRelaxationProvider( void );

		virtual void Reset( const IGraphModel& graphModel, const CNodeModel& nodeFrom ) const;
		virtual bool Relax( const IGraphModel& graphModel, const CNodeModel& nodeFrom, const CNodeModel& nodeTo ) const;
		virtual bool IsCheaper( const CNodeModel& lNode, const CNodeModel& rNode ) const;
		
		const std::map < unsigned int, double >& GetSpecMetrics( void ) const;
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_RELAXATIONPROVIDER_H_ */