/*
 * This file is part of minotaur.
 *
 * File: KruskalAlgorithm.h
 * Brief: Declaration of kruskal algorithm class.
 *
 * Date: .07.2013
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
	
class CKruskalAlgorithm : public ITreeFinder
{
	public:
		CKruskalAlgorithm( void );
		virtual ~CKruskalAlgorithm( void );
		
		virtual std::shared_ptr < CTreeModel > FindMST( const IGraphModel& graphModel, const CNodeModel& nodeRoot );
		
		class CEdgeSet
		{
			private:
				const IGraphModel& m_graphModel;
				unsigned int m_graphModelNodesNumber;
				
				std::vector < CEdgeModel > m_mstTreeEdges;
				std::vector < CEdgeModel > m_graphModelRemaningEdges;
				std::map < CNodeModel, unsigned int, CNodeModel::SNodeModelLess > m_forest;
				
				CEdgeModel m_FindCheapestEdge( void );
				void m_EraseEdge( CEdgeModel& edgeToErase );
				void m_AddEdgeToForest( const CEdgeModel& edgeToAdd );
								
			public:
				CEdgeSet( void ) = delete;
				explicit CEdgeSet( const IGraphModel& graphModel );
				~CEdgeSet( void );
		
				void ExpandMSTTree( void );
				bool CanExpandMSTTree( void );
				std::shared_ptr < CTreeModel > BuildMSTTree( const CNodeModel& nodeRoot );
		};
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_KRUSKALALGORITHM_H_ */