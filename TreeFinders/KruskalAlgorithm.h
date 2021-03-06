/*
 * This file is part of minotaur.
 *
 * File: KruskalAlgorithm.h
 * Brief: Declaration of kruskal algorithm class.
 *
 * Date: 21.08.2013
 * Author: Andrzej Korycinski
 *
 * */

#ifndef _MINOTAUR_KRUSKALALGORITHM_H_
#define _MINOTAUR_KRUSKALALGORITHM_H_

#include "ITreeFinder.h"
#include "IGraphModel.h"
#include "NodeModel.h"
#include "EdgeModel.h"

#include <vector>
#include <map>

namespace Minotaur
{
	
class CTreeModel;

class CKruskalAlgorithm : public ITreeFinder
{
	protected:
		virtual void t_ComputeHeapMemoryUsage( void );

	public:
		CKruskalAlgorithm( void );
		virtual ~CKruskalAlgorithm( void );
		
		virtual std::shared_ptr < CTreeModel > FindMST( const IGraphModel& graphModel, const CNodeModel& nodeRoot );
		
		class CEdgeSet
		{
			private:
				const IGraphModel& m_graphModel;
				
				std::vector < CEdgeModel > m_mstEdges;
				std::vector < CEdgeModel > m_graphModelRemaningEdges;
				std::map < CNodeModel, unsigned int, CNodeModel::SNodeModelLess > m_forest;
				
				CEdgeModel m_FindCheapestEdge( void );
				void m_EraseEdge( CEdgeModel& edgeToErase );
				void m_AddEdgeToForest( const CEdgeModel& edgeToAdd );
								
			public:
				CEdgeSet( void ) = delete;
				explicit CEdgeSet( const IGraphModel& graphModel );
				~CEdgeSet( void );
		
				void ExpandMST( void );
				bool CanExpandMST( void );
				std::shared_ptr < CTreeModel > BuildMST( const CNodeModel& nodeRoot );
				
				unsigned long long heapMemoryUsed;
		};
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_KRUSKALALGORITHM_H_ */
