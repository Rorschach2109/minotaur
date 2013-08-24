/*
 * This file is part of minotaur.
 *
 * File: PrimAlgorithm.h
 * Brief: Declaration of prim algorithm class.
 *
 * Date: 23.08.2013
 * Author: Andrzej Korycinski
 *
 * */

#ifndef _MINOTAUR_PRIMALGORITHM_H_
#define _MINOTAUR_PRIMALGORITHM_H_

#include "ITreeFinder.h"

#include "IGraphModel.h"
#include "NodeModel.h"
#include "EdgeModel.h"

#include <vector>

namespace Minotaur
{

class CTreeModel;
	
class CPrimAlgorithm : public ITreeFinder
{
	public:
		CPrimAlgorithm( void );
		virtual ~CPrimAlgorithm( void );
		
		virtual std::shared_ptr < CTreeModel > FindMST( const IGraphModel& graphModel, const CNodeModel& nodeRoot );

	class CCut
	{
		private:
			const IGraphModel& m_graphModel;
			
			std::vector < CEdgeModel > m_cutEdges;
			std::vector < CNodeModel > m_mstNodes;
			std::vector < CEdgeModel > m_mstEdges;
			
			CEdgeModel m_FindCheapestEdge( void );
			void m_EraseEdge( CEdgeModel& edgeToErase );
			CNodeModel m_AddNodeToMST( const CEdgeModel& cheapestMSTEdge );

			void m_AddValidEdgesToMST( const CNodeModel& node );
			void m_RemoveInvalidEdges( void );

			bool m_VectorContainsNode( const unsigned int& nodeIdToCheck, const std::vector < CNodeModel >& nodesVector );
			bool m_VectorContainsEdge( CEdgeModel& edgeToCheck, const std::vector < CEdgeModel >& edgesVector );
			
		public:
			CCut( void ) = delete;
			CCut( const IGraphModel& graphModel, const CNodeModel& nodeRoot );
			~CCut( void );
			
			void ExpandMST( void );

			bool GraphModelContained( void );
			bool CanExpandMST( void );

			std::shared_ptr < CTreeModel > BuildMST( void );
	};
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_PRIMALGORITHM_H_ */