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
 
#include "NodeDTO.h"
#include "EdgeDTO.h"
#include "GraphDTO.h"
 
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
		std::string squareDotGraphString;

		std::vector < CNodeDto > infinityDtoNodes;
		std::vector < CEdgeDto > infinityDtoEdges;
		std::string infinityName;
		CGraphDto infinityDtoGraph;
		std::string infinityDtoGraphString;
		std::string infinityDotGraphString;
		
		std::vector < CNodeDto > turtleDtoNodes;
		std::vector < CEdgeDto > turtleDtoEdges;
		std::string turtleName;
		CGraphDto turtleDtoGraph;
		std::string turtleDtoGraphString;
		std::string turtleDotGraphString;
		
		std::vector < CNodeDto > doubleTriangleDtoNodes;
		std::vector < CEdgeDto > doubleTriangleDtoEdges;
		std::string doubleTriangleName;
		CGraphDto doubleTriangleDtoGraph;
		std::string doubleTriangleDtoGraphString;
		std::string doubleTriangleDotGraphString;

		std::vector < CNodeDto > spiderNetDtoNodes;
		std::vector < CEdgeDto > spiderNetDtoEdges;
		std::string spiderNetName;
		CGraphDto spiderNetDtoGraph;
		std::string spiderNetDtoGraphString;
		std::string spiderNetDotGraphString;

		std::vector < CNodeDto > grapeDtoNodes;
		std::vector < CEdgeDto > grapeDtoEdges;
		std::string grapeName;
		CGraphDto grapeDtoGraph;
		std::string grapeDtoGraphString;
		std::string grapeDotGraphString;
};
	
} // namespace Minotaur
 
#endif /* _MINOTAUR_GRAPHDTOFACTORY_H_ */
