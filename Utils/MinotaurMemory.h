/*
 * This file is part of minotaur.
 *
 * File: MinotaurMemory.h
 * Brief: Declaration of minotaur memory class.
 *
 * Date: 02.01.2014
 * Author: Andrzej Korycinski
 * 
 * */

#ifndef _MINOTAUR_MINOTAURMEMORY_H_
#define _MINOTAUR_MINOTAURMEMORY_H_


namespace Minotaur
{
	
class CMinotaurMemory
{
	private:
		double m_residentSetSizeMemory;
		double m_sharedMemorySize;
		double m_privateMemorySize;
		
	public:
		CMinotaurMemory( void );
		~CMinotaurMemory( void );

		CMinotaurMemory operator-( const CMinotaurMemory& minotaurMemory ) const;
		
		void SetMemory( void );
		
		double GetResidentSetSizeMemory( void ) const;
		double GetSharedMemorySize( void ) const;
		double GetPrivateMemorySize( void ) const;
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_MINOTAURMEMORY_H_ */