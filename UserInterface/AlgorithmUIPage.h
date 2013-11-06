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

#include <memory>

namespace Minotaur
{

class AbstractInputGraphManager;
class IGraphModel;
class CSubGraphModel;
class ITreeFinder;
class IPathFinder;

enum EAlgorithmOptionId
{
	KRUSKAL = 1,
	PRIM,
	BORUVKA,
	ALL_MST,
	DIJKSTRA,
	BELLMAN_FORD,
	ALL_PATHS,
	EXIT_ALGORITHM = EXIT_PAGE
};

class CAlgorithmUIPage : public AbstractUIPage
{
	public:
		CAlgorithmUIPage( AbstractInputGraphManager* inputGraphManager );
		virtual ~CAlgorithmUIPage( void );

		virtual void DisplayOptions( void ) const;
		virtual void ExecuteOption( void ) const;

	private:
		AbstractInputGraphManager* m_inputGraphManager;
		mutable std::shared_ptr < IGraphModel > m_graphModel;
		mutable std::shared_ptr < CSubGraphModel > m_resultSubGraph;
		mutable ITreeFinder* m_treeFinder;
		mutable IPathFinder* m_pathFinder;

		void m_LoadGraph( void ) const;
		void m_KruskalAlgorithm( void ) const;
		void m_PrimAlgorithm( void ) const;
		void m_BoruvkaAlgorithm( void ) const;
		void m_AllMSTAlgorithms( void ) const;
		void m_DijkstraAlgorithm( void ) const;
		void m_BellmanFordAlgorithm( void ) const;
		void m_AllPathAlgorithms( void ) const;
};

} // namespace Minotaur

#endif /* _MINOTAUR_ALGORITHMUIPAGE_H_ */
