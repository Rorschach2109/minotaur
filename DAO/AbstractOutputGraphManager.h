#ifndef _MINOTAUR_ABSTRACTOUTPUTGRAPHMANAGER_H_
#define _MINOTAUR_ABSTRACTOUTPUTGRAPHMANAGER_H_

#include <ostream>

namespace Minotaur
{
	
class AbstractOutputGraphManager
{
	private:
		const std::ostream& m_graphOutputStream;

	public:
		AbstractOutputGraphManager( void ) = delete;
		explicit AbstractOutputGraphManager( const std::ostream& graphOutputStream );
		virtual ~AbstractOutputGraphManager( void );
		
		virtual bool WriteGraphToOutput( void ) = 0;
};

} // namespace Minotaur

#endif /* _MINOTAUR_ABSTRACTOUTPUTGRAPHMANAGER_H_ */