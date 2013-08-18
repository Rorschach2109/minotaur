/*
 * This file is part of minotaur.
 *
 * File: PathModel.h
 * Brief: Declaration of path mdoel class.
 *
 * Date: 18.08.2013
 * Author: Andrzej Korycinski
 * 
 * */

#ifndef _MINOTAUR_PATHMODEL_H_
#define _MINOTAUR_PATHMODEL_H_

#include "SubGraphModel.h"
#include "IGraphModel.h"

namespace Minotaur
{

typedef std::vector < std::pair < unsigned int, unsigned int > > edgeDefinition;
	
class CPathModel : public CSubGraphModel
{
	public:
		CPathModel( void ) = delete;
		CPathModel( const IGraphModel& parentGraph, const edgeDefinition& subGraphEdges );
		virtual ~CPathModel( void );
		
		virtual bool VerifySubGraphTopology( void ) const;
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_PATHMODEL_H_ */