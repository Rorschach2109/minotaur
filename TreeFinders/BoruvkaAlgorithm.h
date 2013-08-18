/*
 * This file is part of minotaur.
 *
 * File: BoruvkaAlgorithm.h
 * Brief: Declaration of boruvka algorithm class.
 *
 * Date: .07.2013
 * Author: Andrzej Korycinski
 *
 * */

#ifndef _MINOTAUR_BORUVKAALGORITHM_H_
#define _MINOTAUR_BORUVKAALGORITHM_H_

#include "ITreeFinder.h"

namespace Minotaur
{
	
class CBoruvkaAlgorithm : public ITreeFinder
{
	public:
		CBoruvkaAlgorithm( void );
		virtual ~CBoruvkaAlgorithm( void );
		
		virtual std::shared_ptr < CTreeModel > FindMST( const IGraphModel& graphModel, const CNodeModel& nodeRoot );
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_BORUVKAALGORITHM_H_ */