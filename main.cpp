#include <iostream>

#include "NodeDTOTest.h"
#include "EdgeDTOTest.h"
#include "GraphDTOTest.h"

#include "StreamInputGraphManagerTest.h"
#include "StreamOutputGraphManagerTest.h"

int main( void )
{
	std::cout << "Tests:\n"; 
	
	Minotaur::CNodeDtoTest dtoTestNode = Minotaur::CNodeDtoTest();
	Minotaur::CEdgeDtoTest dtoTestEdge = Minotaur::CEdgeDtoTest();
	Minotaur::CGraphDtoTest dtoTestGraph = Minotaur::CGraphDtoTest();
	
	Minotaur::CStreamInputGraphManagerTest inputGraphManagerTest = Minotaur::CStreamInputGraphManagerTest();
	Minotaur::CStreamOutputGraphManagerTest outputGraphManagerTest = Minotaur::CStreamOutputGraphManagerTest();
	
	return 0;
}
