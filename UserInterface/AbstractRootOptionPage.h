/*
 * This file is part of minotaur.
 *
 * File: AbstractRootOptionPage.h
 * Brief: Declaration of abstract user interface root option page class.
 *
 * Date: 09.10.2013
 * Author: Andrzej Korycinski
 *
 * */

#ifndef _MINOTAUR_ABSTRACTROOTOPTIONPAGE_H_
#define _MINOTAUR_ABSTRACTROOTOPTIONPAGE_H_

#include "AbstractUIPage.h"

#include <string>

namespace Minotaur
{

class AbstractRootOptionPage : public AbstractUIPage
{
	protected:
		mutable std::string t_filePath;

		void t_ProcessLoadFile( void ) const;
		void t_ProcessConvertFile( void ) const;
		void t_ProcessChooseAlgorithm( void ) const;
		void t_ProcessPrintGraph( void ) const;

	public:
		AbstractRootOptionPage( void );
		virtual ~AbstractRootOptionPage( void );

		virtual void DisplayOptions( void ) const = 0;
		virtual void ExecuteOption( void ) const = 0;
};

} // namespace Minotaur

#endif /* _MINOTAUR_ABSTRACTROOTOPTIONPAGE_H_ */
