#include <iostream>

#include "NodeDTOTest.h"
#include "EdgeDTOTest.h"
#include "GraphDTOTest.h"

#include "StreamInputGraphManagerTest.h"
#include "StreamOutputGraphManagerTest.h"

#include "NodeModelTest.h"
#include "EdgeModelTest.h"
#include "AdjacencyListTest.h"
#include "AdjacencyListFactoryTest.h"

int main( void )
{
	Minotaur::CNodeDtoTest dtoTestNode = Minotaur::CNodeDtoTest();
	Minotaur::CEdgeDtoTest dtoTestEdge = Minotaur::CEdgeDtoTest();
	Minotaur::CGraphDtoTest dtoTestGraph = Minotaur::CGraphDtoTest();
	
	Minotaur::CStreamInputGraphManagerTest inputGraphManagerTest = Minotaur::CStreamInputGraphManagerTest();
	Minotaur::CStreamOutputGraphManagerTest outputGraphManagerTest = Minotaur::CStreamOutputGraphManagerTest();
	
	Minotaur::CNodeModelTest nodeModelTest = Minotaur::CNodeModelTest();
	Minotaur::CEdgeModelTest edgeModelTest = Minotaur::CEdgeModelTest();
	
	Minotaur::CAdjacencyListTest adjacencyListTest = Minotaur::CAdjacencyListTest();
	Minotaur::CAdjacencyListFactoryTest adjacencyListFactoryTest = Minotaur::CAdjacencyListFactoryTest();
	
	return 0;
}
