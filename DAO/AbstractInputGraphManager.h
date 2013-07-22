#ifndef _MINOTAUR_ABSTRACTINPUTGRAPHMANAGER_H_
#define _MINOTAUR_ABSTRACTINPUTGRAPHMANAGER_H_

#include <istream>

namespace Minotaur
{
	
class AbstractInputGraphManager
{
	protected:
		std::istream& t_graphInputStream;
		
	public:
		AbstractInputGraphManager( void ) = delete;
		explicit AbstractInputGraphManager( std::istream& graphInputStream );
		virtual ~AbstractInputGraphManager( void );
		
		virtual bool ReadGraphFromInput( void ) = 0;
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_ABSTRACTINPUTGRAPHMANAGER_H_ */