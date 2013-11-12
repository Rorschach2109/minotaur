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

#include <string>
#include <memory>

namespace Minotaur
{

class AbstractInputGraphManager;
class AbstractOutputGraphManager;
class IGraphModel;
class ITreeFinder;
class IPathFinder;
class CSubGraphToGraphAdapter;

enum EAlgorithmOptionId
{
	KRUSKAL = 1,
	PRIM,
	BORUVKA,
	DIJKSTRA,
	BELLMAN_FORD,
	EXIT_ALGORITHM = EXIT_PAGE
};

class CAlgorithmUIPage : public AbstractUIPage
{
	public:
		CAlgorithmUIPage( AbstractInputGraphManager* inputGraphManager, const std::string& graphName );
		virtual ~CAlgorithmUIPage( void );

		virtual void DisplayOptions( void ) const;
		virtual void ExecuteOption( void ) const;
		
		const std::string& GetSubGraphName( void ) const;
	
	private:
		mutable unsigned int m_nodeFromId;
		mutable unsigned int m_nodeToId;
		
		AbstractInputGraphManager* m_inputGraphManager;
		AbstractOutputGraphManager* m_outputGraphManager;
		mutable std::shared_ptr < IGraphModel > m_graphModel;
		mutable std::shared_ptr < CSubGraphToGraphAdapter > m_resultSubGraph;
		
		mutable ITreeFinder* m_treeFinder;
		mutable IPathFinder* m_pathFinder;

		mutable std::string m_subGraphName;
		
		void m_LoadGraph( void ) const;
		void m_WriteGraphToFile( void ) const;
		void m_GetNodesId( void ) const;
		bool m_CheckNodesId( void ) const;

		void m_KruskalAlgorithm( void ) const;
		void m_PrimAlgorithm( void ) const;
		void m_BoruvkaAlgorithm( void ) const;

		void m_DijkstraAlgorithm( void ) const;
		void m_BellmanFordAlgorithm( void ) const;
		
		void m_ExitAlgorithmPage( void ) const;
};

} // namespace Minotaur

#endif /* _MINOTAUR_ALGORITHMUIPAGE_H_ */
