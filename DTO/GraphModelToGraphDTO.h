/*
 * This file is part of minotaur.
 *
 * File: GraphModelToGraphDTO.h
 * Brief: Declaration of graph model to graph dto class.
 *
 * Date: 12.11.2013
 * Author: Andrzej Korycinski
 * 
 * */

#ifndef _MINOTAUR_GRAPHMODELTOGRAPHDTO_H_
#define _MINOTAUR_GRAPHMODELTOGRAPHDTO_H_

#include "GraphDTO.h"

#include <memory>
#include <vector>
#include <string>

namespace Minotaur
{
class CNodeDto;
class CEdgeDto;
class CNodeModel;
class CEdgeModel;
class CSubGraphToGraphAdapter;
	
class CGraphModelToGraphDto
{
private:
	std::string m_graphName;
	CSubGraphToGraphAdapter& m_graphModel;
	std::vector < CNodeDto > m_dtoNodes;
	std::vector < CEdgeDto > m_dtoEdges;
	
	void m_ConvertNodes( void );
	void m_ConvertEdges( void );
	
public:
	CGraphModelToGraphDto( void ) = delete;
	explicit CGraphModelToGraphDto( std::string graphName, CSubGraphToGraphAdapter& graphModel );
	~CGraphModelToGraphDto( void );
	
	CGraphDto GetDtoGraph( void );
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_GRAPHMODELTOGRAPHDTO_H_ */