/*
 * This file is part of minotaur.
 *
 * File: AlgorithmUIPage.h
 * Brief: Declaration of algorithm user interface page class.
 *
 * Date: 09.10.2013
 * Author: Andrzej Korycinski
 *
 * */

#ifndef _MINOTAUR_ALGORITHMUIPAGE_H_
#define _MINOTAUR_ALGORITHMUIPAGE_H_

#include "AbstractUIPage.h"

namespace Minotaur
{

class CAlgorithmUIPage : public AbstractUIPage
{
	public:
		CAlgorithmUIPage( void );
		virtual ~CAlgorithmUIPage( void );

		virtual void DisplayOptions( void ) const;
		virtual void ExecuteOption( void ) const;
};

} // namespace Minotaur

#endif /* _MINOTAUR_ALGORITHMUIPAGE_H_ */
