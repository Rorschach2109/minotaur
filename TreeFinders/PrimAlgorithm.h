/*
 * This file is part of minotaur.
 *
 * File: PrimAlgorithm.h
 * Brief: Declaration of prim algorithm class.
 *
 * Date: .07.2013
 * Author: Andrzej Korycinski
 *
 * */

#ifndef _MINOTAUR_PRIMALGORITHM_H_
#define _MINOTAUR_PRIMALGORITHM_H_

#include "ITreeFinder.h"

namespace Minotaur
{
	
class CPrimAlgorithm : public ITreeFinder
{
	public:
		CPrimAlgorithm( void );
		virtual ~CPrimAlgorithm( void );
		
		virtual std::shared_ptr < CTreeModel > FindMST( const IGraphModel& graphModel, const CNodeModel& nodeRoot );
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_PRIMALGORITHM_H_ */