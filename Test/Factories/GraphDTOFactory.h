/*
 * This file is part of minotaur.
 *
 * File: GraphDTOFactory.h
 * Brief: Declaration of graph dto factory class.
 *
 * Date: 28.07.2013
 * Author: Andrzej Korycinski
 * 
 * */
 
#ifndef _MINOTAUR_GRAPHDTOFACTORY_H_
#define _MINOTAUR_GRAPHDTOFACTORY_H_
 
#include "DTO/NodeDTO.h"
#include "DTO/EdgeDTO.h"
#include "DTO/GraphDTO.h"
 
#include <vector>
#include <string>

namespace Minotaur
{
	
class CGraphDtoFactory
{
	public:
		CGraphDtoFactory( void );
		~CGraphDtoFactory( void );
		std::vector < CNodeDto > squareDtoNodes;
		std::vector < CEdgeDto > squareDtoEdges;
		std::string squareName;
		CGraphDto squareDtoGraph;
		std::string squareDtoGraphString;

		std::vector < CNodeDto > infinityDtoNodes;
		std::vector < CEdgeDto > infinityDtoEdges;
		std::string infinityName;
		CGraphDto infinityDtoGraph;
		std::string infinityDtoGraphString;
		
		std::vector < CNodeDto > turtleDtoNodes;
		std::vector < CEdgeDto > turtleDtoEdges;
		std::string turtleName;
		CGraphDto turtleDtoGraph;
		std::string turtleDtoGraphString;
		
		std::vector < CNodeDto > doubleTriangleDtoNodes;
		std::vector < CEdgeDto > doubleTriangleDtoEdges;
		std::string doubleTriangleName;
		CGraphDto doubleTriangleDtoGraph;
		std::string doubleTriangleDtoGraphString;
};
	
} // namespace Minotaur
 
#endif /* _MINOTAUR_GRAPHDTOFACTORY_H_ */