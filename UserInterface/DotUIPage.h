/*
 * This file is part of minotaur.
 *
 * File: DotUIPage.h
 * Brief: Declaration of dot user interface page class.
 *
 * Date: 09.10.2013
 * Author: Andrzej Korycinski
 *
 * */

#ifndef _MINOTAUR_DOTUIPAGE_H_
#define _MINOTAUR_DOTUIPAGE_H_

#include "AbstractRootOptionPage.h"

namespace Minotaur
{

class CDotUIPage : public AbstractRootOptionPage
{
	protected:
		virtual void t_ProcessLoadFile( void ) const;
		virtual void t_ProcessConvertInputFile( void ) const;
		virtual void t_ProcessPrintInputGraph( void ) const;
		virtual void t_ProcessPrintResultGraph( void ) const;

	public:
		CDotUIPage( void );
		virtual ~CDotUIPage( void );

		virtual void DisplayOptions( void ) const;
};

} // namespace Minotaur

#endif /* _MINOTAUR_DOTUIPAGE_H_ */
