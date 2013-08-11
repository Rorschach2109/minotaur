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
 
#include <iostream>
#include <cstring>
 
namespace Minotaur
{
	
#define FILE_NAME ( strrchr(__FILE__, '/' ) ? ( strrchr(__FILE__, '/') + 1 ) : ( __FILE__ ) );

#define TEST_INFO \
	do { \
		const char* fileName = FILE_NAME; \
		std::cout << " \nFile: " << fileName << " \nFunction: " << __FUNCTION__ << " \nLine: " << __LINE__ << "\n\n"; \
		} while( false )
			
#define PASSED_INFO \
	do { \
		std::cout << "\33[32;40m" << "[PASSED]" << "\33[0m"; \
		TEST_INFO; \
	} while( false )

#define FAILED_INFO( expected, actual ) \
	do { \
		std::cout << "\33[31;40m" << "[FAILED]"<< "\33[0m"; \
		TEST_INFO; \
		} while( false )

#define FAILED_VECTORS_INFO( expected, actual ) \
	do { \
		std::cout << "\33[31;40m" << "[FAILED]"<< "\33[0m"; \
		TEST_INFO; \
		} while( false )

#define PASSED_VECTORS_INFO( expected, actual ) \
	do { \
		std::cout << "\33[32;40m" << "[PASSED]" << "\33[0m"; \
		TEST_INFO; \
		} while( false )
			
#define CHECK_EQUAL( lValue, rValue )  \
	do { \
		std::cout << "CHECK_EQUAL: "; \
		if ( lValue == rValue ) \
		{ PASSED_INFO; } \
		else \
		{ FAILED_INFO(lValue, rValue); } \
	} while(0)

#define CHECK_VECTORS_EQUAL( lVector, rVector )  \
	do { \
		std::cout << "CHECK_VECTORS_EQUAL: "; \
		if ( lVector.size() == rVector.size() ) \
		{ \
			for ( size_t vectorIndex = 0; vectorIndex < lVector.size(); ++vectorIndex ) \
			{ \
				if ( lVector[vectorIndex] == rVector[vectorIndex] ) \
				{} \
				else \
				{ \
					FAILED_VECTORS_INFO(lVector, rVector);  \
					break; \
				} \
			} \
		} \
		else \
		{ \
			FAILED_VECTORS_INFO(lVector, rVector);  \
			break; \
		} \
		PASSED_VECTORS_INFO(lVector, rVector);  \
	} while(0)
		
#define CHECK_NOT_EQUAL( lValue, rValue )  \
	do { \
		std::cout << "CHECK_NOT_EQUAL: "; \
		if ( lValue == rValue ) \
		{ FAILED_INFO(lValue, rValue); } \
		else \
		{ PASSED_INFO; } \
	} while(0)

#define CHECK_VECTORS_NOT_EQUAL( lVector, rVector )  \
	do { \
		std::cout << "CHECK_VECTORS_NOT_EQUAL: "; \
		if ( lVector.size() == rVector.size() ) \
		{ \
			for ( size_t vectorIndex = 0; vectorIndex < lVector.size(); ++vectorIndex ) \
			{ \
				if ( lVector[vectorIndex] == rVector[vectorIndex] ) \
				{ \
					FAILED_VECTORS_INFO(lVector, rVector);  \
					break; \
				} \
			} \
		} \
		PASSED_VECTORS_INFO(lVector, rVector);  \
	} while(0)

} // namespace Minotaur