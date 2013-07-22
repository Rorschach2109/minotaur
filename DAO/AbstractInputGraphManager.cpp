#include "AbstractInputGraphManager.h"

using namespace Minotaur;

AbstractInputGraphManager::AbstractInputGraphManager( std::istream& graphInputStream ) : 
	t_graphInputStream(graphInputStream)
{
	
}

AbstractInputGraphManager::~AbstractInputGraphManager( void )
{
	
}
