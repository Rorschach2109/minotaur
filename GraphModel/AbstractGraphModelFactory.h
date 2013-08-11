/*
 * This file is part of minotaur.
 *
 * File: AbstractGraphModelFactory.h
 * Brief: Declaration of abstract graph model factory class.
 *
 * Date: 11.08.2013
 * Author: Andrzej Korycinski
 * 
 * */

#ifndef _MINOTAUR_ABSTRACTGRAPHMODELFACTORY_H_
#define _MINOTAUR_ABSTRACTGRAPHMODELFACTORY_H_

#include "NodeModel.h"
#include "NodeDTO.h"

#include "EdgeModel.h"
#include "EdgeDTO.h"

#include "IGraphModel.h"

#include <vector>
#include <memory>

namespace Minotaur
{
	
class AbstractGraphModelFactory
{
	private:
		std::vector < CNodeModel > m_ConvertDtoNodesToModel( const std::vector < CNodeDto >& graphDtoNodes );
		std::vector < CEdgeModel > m_ConvertDtoEdgesToModel( const std::vector < CEdgeDto >& graphDtoEdges );
	
	public:
		AbstractGraphModelFactory( void );
		virtual ~AbstractGraphModelFactory( void ) = 0;
		
		virtual std::shared_ptr < IGraphModel > CreateFromVectors( const std::vector < CNodeModel >& graphModelNodes, const std::vector < CEdgeModel >& graphModelEdges ) = 0;
		std::shared_ptr < IGraphModel > CreateFromDto( const std::vector < CNodeDto >& graphDtoNodes, const std::vector < CEdgeDto >& graphDtoEdges );
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_ABSTRACTGRAPHMODELFACTORY_H_ */