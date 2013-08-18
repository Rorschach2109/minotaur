/*
 * This file is part of minotaur.
 *
 * File: TreeModel.h
 * Brief: Declaration of tree model class.
 *
 * Date: .08.2013
 * Author: Andrzej Korycinski
 * 
 * */

#ifndef _MINOTAUR_TREEMODEL_H_
#define _MINOTAUR_TREEMODEL_H_

#include "SubGraphModel.h"
#include "IGraphModel.h"

namespace Minotaur
{

typedef std::vector < std::pair < unsigned int, unsigned int > > edgeDefinition;
	
class CTreeModel : public CSubGraphModel
{
	public:
		CTreeModel( void ) = delete;
		CTreeModel( const IGraphModel& parentGraph, const edgeDefinition& subGraphEdges );
		virtual ~CTreeModel( void );
		
		virtual bool VerifySubGraphTopology( void ) const;
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_TREEMODEL_H_ */