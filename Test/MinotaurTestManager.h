/*
 * This file is part of minotaur.
 *
 * File: MinotaurTestManager.h
 * Brief: Declaration of minotaur test manager class.
 *
 * Date: 22.08.2013
 * Author: Andrzej Korycinski
 * 
 * */

#ifndef _MINOTAUR_MINOTAURTESTMANAGER_H_
#define _MINOTAUR_MINOTAURTESTMANAGER_H_

#include <memory>

namespace Minotaur
{

class AbstractMinotaurTest;	
	
class CMinotaurTestManager
{	
	private:
		std::shared_ptr < AbstractMinotaurTest > m_minotaurTest;
		unsigned int m_allTestNumber;
		unsigned int m_failedTestNumber;
		
		void m_RunDtoTests( void );
		void m_RunModelTests( void );
		void m_RunAllDaoTests( void );
		void m_RunAllDtoTests( void );
		void m_RunAllGraphModelTests( void );
		void m_RunAllPathFindersTests( void );
		void m_RunAllTreeFindersTests( void );
		void m_RunAllUtilsTests( void );
	
	public:
		CMinotaurTestManager( void );
		~CMinotaurTestManager( void );
		
		void RunAllTests( void );
		void DisplayTestStatistic( void );
};

} // namespace Minotaur

#endif /* _MINOTAUR_MINOTAURTESTMANAGER_H_ */