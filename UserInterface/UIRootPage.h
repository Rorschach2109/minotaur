/*
 * This file is part of minotaur.
 *
 * File: UIRootPage.h
 * Brief: Declaration of user interface root page class.
 *
 * Date: 09.10.2013
 * Author: Andrzej Korycinski
 *
 * */

#ifndef _MINOTAUR_UIROOTPAGE_H_
#define _MINOTAUR_UIROOTPAGE_H_

#include "AbstractUIPage.h"

namespace Minotaur
{

class AbstractRootOptionPage;

enum ERootOption
{
	AK_GRAPH_FILE = 1,
	DOT_GRAPH_FILE,
	EXIT_ROOT = EXIT_PAGE
};

class CUIRootPage : public AbstractUIPage
{
	private:
		mutable AbstractRootOptionPage* m_rootOptionPage;

		void m_ProcessAKGraphFile( void ) const;
		void m_ProcessDotGraphFile( void ) const;

	public:
		CUIRootPage( void );
		virtual ~CUIRootPage( void );

		virtual void DisplayOptions( void ) const;
		virtual void ExecuteOption( void ) const;
};

} // namespace Minotaur

#endif /* _MINOTAUR_UIROOTPAGE_H_ */
