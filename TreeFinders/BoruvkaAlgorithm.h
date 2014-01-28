/*
 * This file is part of minotaur.
 *
 * File: BoruvkaAlgorithm.h
 * Brief: Declaration of boruvka algorithm class.
 *
 * Date: .07.2013
 * Author: Andrzej Korycinski
 *
 * */

#ifndef _MINOTAUR_BORUVKAALGORITHM_H_
#define _MINOTAUR_BORUVKAALGORITHM_H_

#include "ITreeFinder.h"
#include "NodeModel.h"
#include "EdgeModel.h"
#include "IGraphModel.h"

#include <vector>
#include <map>

namespace Minotaur
{
	
class CBoruvkaAlgorithm : public ITreeFinder
{
	protected:
		virtual void t_ComputeHeapMemoryUsage( void );

	public:
		CBoruvkaAlgorithm( void );
		virtual ~CBoruvkaAlgorithm( void );
		
		virtual std::shared_ptr < CTreeModel > FindMST( const IGraphModel& graphModel, const CNodeModel& nodeRoot );
		
		class CCut
		{
			private:
				const IGraphModel& m_graphModel;
				unsigned int m_nodeRootId;
				
				std::vector < CEdgeModel > m_mstEdges;
				std::map < CNodeModel, unsigned int, CNodeModel::SNodeModelLess > m_nodesMap;
				std::map < unsigned int, std::vector < CNodeModel > > m_forest;
				
				CEdgeModel m_FindCheapestEdge( const CNodeModel& currentNode );
				CEdgeModel m_FindCheapestEdge( const std::vector< CEdgeModel >& cheapestEdges );
				void m_AddValidEdge( const CEdgeModel& mstEdge );
				void m_UpdateForest( void );
				
			public:
				CCut( void ) = delete;
				CCut( const IGraphModel& graphModel );
				~CCut( void );

				void ExpandMSTBoruvka( void );
				bool CanExpandMSTBoruvka( void );
				std::shared_ptr < CTreeModel > BuildMSTBoruvka( void );
				
				unsigned long long heapMemoryUsed;
		};
	
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_BORUVKAALGORITHM_H_ */
