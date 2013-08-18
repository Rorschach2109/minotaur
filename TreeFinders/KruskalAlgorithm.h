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

namespace Minotaur
{
	
class CKruskalAlgorithm : public ITreeFinder
{
	public:
		CKruskalAlgorithm( void );
		virtual ~CKruskalAlgorithm( void );
		
		virtual std::shared_ptr < CTreeModel > FindMST( const IGraphModel& graphModel, const CNodeModel& nodeRoot );
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_KRUSKALALGORITHM_H_ */