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

#include <string>

namespace Minotaur
{

enum EUIPageOption
{
	EXIT_PAGE = 99
};

class AbstractUIPage
{
	protected:
		mutable unsigned int t_optionId;
		const std::string t_noFileLoadedMessage;
		const std::string t_goodFileMessage;
		const std::string t_wrongFileMessage;
		const std::string t_wrongOptionMessage;
		const std::string t_wrongCommandMessage;

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
