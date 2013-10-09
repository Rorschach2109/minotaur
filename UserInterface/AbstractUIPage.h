/*
 * This file is part of minotaur.
 *
 * File: AbstractUIPage.h
 * Brief: Declaration of abstract user interface page class.
 *
 * Date: 09.10.2013
 * Author: Andrzej Korycinski
 *
 * */

#ifndef _MINOTAUR_ABSTRACTUIPAGE_H_
#define _MINOTAUR_ABSTRACTUIPAGE_H_

namespace Minotaur
{

class AbstractUIPage
{
	protected:
		mutable unsigned int t_optionId;

		unsigned int t_WaitForInput( void ) const;

	public:
		AbstractUIPage( void );
		virtual ~AbstractUIPage( void );

		void RunPage( void ) const;
		virtual void DisplayOptions( void ) const = 0;
		virtual void ExecuteOption( void ) const = 0;
};

} // namespace Minotaur

#endif /* _MINOTAUR_ABSTRACTUIPAGE_H_ */
