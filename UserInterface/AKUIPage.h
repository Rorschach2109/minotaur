/*
 * This file is part of minotaur.
 *
 * File: AKUIPage.h
 * Brief: Declaration of ak user interface page class.
 *
 * Date: 09.10.2013
 * Author: Andrzej Korycinski
 *
 * */

#ifndef _MINOTAUR_AKUIPAGE_H_
#define _MINOTAUR_AKUIPAGE_H_

#include "AbstractRootOptionPage.h"

namespace Minotaur
{

class CAKUIPage : public AbstractRootOptionPage
{		
	protected:
		virtual void t_ProcessLoadFile( void ) const;
		virtual void t_ProcessConvertInputFile( void ) const;
		virtual void t_ProcessPrintInputGraph( void ) const;
		virtual void t_ProcessPrintResultGraph( void ) const;
		
	public:
		CAKUIPage( void );
		virtual ~CAKUIPage( void );

		virtual void DisplayOptions( void ) const;
};

} // namespace Minotaur

#endif /* _MINOTAUR_AKUIPAGE_H_ */
