/*
 * This file is part of minotaur.
 *
 * File: MemoryOperators.cpp
 * Brief: Implementation of overloaded memory management functions.
 *
 * Date: 03.01.2014
 * Author: Andrzej Korycinski
 *
 * */

#include <stdlib.h>
#include <stdio.h>
#include <new>
#include <exception>

unsigned long long g_stackMemoryAllocated = 0;
unsigned long long g_stackMemoryFreed = 0;

void* operator new( size_t size )
{	
	g_stackMemoryAllocated += size;
	void* memory = malloc(size);
	if ( !memory )
	{
		throw std::bad_alloc();
	}
	return memory;
}

void operator delete( void* ptrToFree )
{
	g_stackMemoryFreed += sizeof(ptrToFree);
	free(ptrToFree);
}

void* operator new[]( size_t size )
{
	g_stackMemoryAllocated += size;
	void* memory = malloc(size);
	if ( !memory )
	{
		throw std::bad_alloc();	
	}
	return memory;
}

void operator delete[]( void* ptrToFree )
{
	g_stackMemoryFreed += sizeof(ptrToFree);
	free(ptrToFree);
}
