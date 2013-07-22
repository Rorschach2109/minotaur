#include "AbstractOutputGraphManager.h"

using namespace Minotaur;

AbstractOutputGraphManager::AbstractOutputGraphManager( const std::ostream& graphOutputStream ) : 
	m_graphOutputStream(graphOutputStream)
{
	
}

AbstractOutputGraphManager::~AbstractOutputGraphManager( void )
{
	
}
