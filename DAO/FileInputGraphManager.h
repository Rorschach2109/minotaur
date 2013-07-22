#ifndef _MINOTAUR_FILEINPUTGRAPHMANAGER_H_
#define _MINOTAUR_FILEINPUTGRAPHMANAGER_H_

#include "AbstractInputGraphManager.h"

#include "NodeDTO.h"
#include "EdgeDTO.h"
#include "GraphDTO.h"

#include <istream>
#include <string>
#include <vector>

namespace Minotaur
{
	
class CFileInputGraphManager : public AbstractInputGraphManager
{
	private:
		unsigned int m_graphsCount;
		std::string m_graphName;
		unsigned int m_nodesCount;
		unsigned int m_edgesCount;
		unsigned int m_graphCounter;
		
		bool m_HasNextGraph( void ) const;
		void m_GetDtoNodes( std::vector < CNodeDto >& dtoNodes );
		void m_GetDtoEdges( std::vector < CEdgeDto >& dtoEdges );
		
	public:
		CFileInputGraphManager( void ) = delete;
		CFileInputGraphManager( std::istream& graphInputStream, const unsigned int& graphsCount );
		virtual ~CFileInputGraphManager( void );
		
		CGraphDto GetNextGraph( void );
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_FILEINPUTGRAPHMANAGER_H_ */