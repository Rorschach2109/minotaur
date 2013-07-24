/*
 * This file is part of minotaur.
 *
 * File: TestDefines.h
 * Brief: Declaration of useful test defines.
 *
 * Date: 24.07.2013
 * Author: Andrzej Korycinski
 * 
 * */
 
 #include <cstdio>
 
 #define CHECK_EQUAL( lValue, rValue )  \
	do { \
		if ( lValue == rValue ) \
		{ printf("Test passed. \tFile: %s \t Line: %d\n", __FILE__, __LINE__); } \
		else \
		{ printf("Test not passed. \tFile: %s \t Line: %d\n", __FILE__, __LINE__); } \
	} while(0)
		
 #define CHECK_NOT_EQUAL( lValue, rValue )  \
	do { \
		if ( lValue != rValue ) \
		{ printf("Test passed. \tFile: %s \t Line: %d\n", __FILE__, __LINE__); } \
		else \
		{ printf("Test not passed. \tFile: %s \t Line: %d\n", __FILE__, __LINE__); } \
	} while(0)