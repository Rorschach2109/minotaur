/*
 * This file is part of minotaur.
 *
 * File: DotUIPage.cpp
 * Brief: Implementation of dot user interface page class.
 *
 * Date: 09.10.2013
 * Author: Andrzej Korycinski
 *
 * */

#include "DotUIPage.h"
#include "DotInputGraphManager.h"

#include <fstream>
#include <cstdlib>

using namespace Minotaur;

CDotUIPage::CDotUIPage( void ) :
		AbstractRootOptionPage()
{

}

CDotUIPage::~CDotUIPage( void )
{
}

void CDotUIPage::t_ProcessLoadFile( void ) const
{
}

void CDotUIPage::t_ProcessConvertInputFile( void ) const
{
}

void CDotUIPage::t_ProcessPrintInputGraph( void ) const
{
	
}

void CDotUIPage::t_ProcessPrintResultGraph( void ) const
{
	
}

void CDotUIPage::DisplayOptions( void ) const
{
	printf("*****Dot Page*****\n\n");
	printf("1.\tLoad Dot Graph File\n");
	printf("2.\tConvert to AK Graph File\n");
	printf("3.\tChoose Algorithm\n");
	printf("4.\tPrint Input Graph\n");
	printf("5.\tPrint Result Graph\n");
	printf("\n*******************\n");
	printf("99.\tEnd\n\n");
}
