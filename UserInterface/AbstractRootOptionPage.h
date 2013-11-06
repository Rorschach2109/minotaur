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
#include <istream>

namespace Minotaur
{

class AbstractInputGraphManager;
class AbstractOutputGraphManager;

enum ERootOptionId
{
	LOAD_GRAPH_FILE = 1,
	CONVERT_FILE,
	CHOOSE_ALGORITHM,
	PRINT_GRAPH,
	EXIT = EXIT_PAGE
};

class AbstractRootOptionPage : public AbstractUIPage
{
	protected:
		mutable std::string t_graphName;
		mutable std::istream* t_graphStream;

		mutable AbstractInputGraphManager* t_inputGraphManager;

		void t_GetGraphName( void ) const;
		void t_ProcessChooseAlgorithm( void ) const;
		void t_ProcessPrintGraph( void ) const;

		virtual void t_ProcessLoadFile( void ) const = 0;
		virtual void t_ProcessConvertFile( void ) const = 0;

	public:
		AbstractRootOptionPage( void );
		virtual ~AbstractRootOptionPage( void );

		virtual void ExecuteOption( void ) const;

		virtual void DisplayOptions( void ) const = 0;
};

} // namespace Minotaur

#endif /* _MINOTAUR_ABSTRACTROOTOPTIONPAGE_H_ */
