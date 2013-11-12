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
#include <memory>

namespace Minotaur
{

class AbstractInputGraphManager;
class AbstractOutputGraphManager;
class CAlgorithmUIPage;
class IGraphModel;
class CSubGraphToGraphAdapter;

enum ERootOptionId
{
	LOAD_GRAPH_FILE = 1,
	CONVERT_INPUT_FILE,
	CHOOSE_ALGORITHM,
	PRINT_INPUT_GRAPH,
	PRINT_RESULT_GRAPH,
	EXIT = EXIT_PAGE
};

class AbstractRootOptionPage : public AbstractUIPage
{
	protected:
		mutable std::string t_graphName;
		mutable std::istream* t_graphStream;
		mutable CAlgorithmUIPage* t_algorithmUIPage;
		mutable AbstractInputGraphManager* t_inputGraphManager;
		mutable AbstractOutputGraphManager* t_outputGraphManager;
		mutable std::shared_ptr < CSubGraphToGraphAdapter > t_resultGraph;
		mutable std::string t_resultGraphName;
		
		void t_GetGraphName( void ) const;
		void t_ProcessChooseAlgorithm( void ) const;

		virtual void t_ProcessLoadFile( void ) const = 0;
		virtual void t_ProcessConvertInputFile( void ) const = 0;
		virtual void t_ProcessPrintInputGraph( void ) const = 0;
		virtual void t_ProcessPrintResultGraph( void ) const = 0;

	public:
		AbstractRootOptionPage( void );
		virtual ~AbstractRootOptionPage( void );

		virtual void ExecuteOption( void ) const;

		virtual void DisplayOptions( void ) const = 0;
};

} // namespace Minotaur

#endif /* _MINOTAUR_ABSTRACTROOTOPTIONPAGE_H_ */
