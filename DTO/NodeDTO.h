/*
 * This file is part of minotaur.
 *
 * File: NodeDTO.h
 * Brief: Declaration of node dto class.
 *
 * Date: 22.07.2013
 * Author: Andrzej Korycinski
 * 
 * */

#ifndef _MINOTAUR_NODEDTO_H_
#define _MINOTAUR_NODEDTO_H_

namespace Minotaur
{

class CNodeDto
{
	private:
		unsigned int m_nodeId;
		unsigned int m_nodeX;
		unsigned int m_nodeY;
		
	public:
		CNodeDto( void ) = delete;
		CNodeDto( const unsigned int& nodeId, const unsigned int& nodeX, const unsigned int& nodeY );
		~CNodeDto( void );
		
		const unsigned int& GetNodeId( void ) const;
		const unsigned int& GetNodeX( void ) const;
		const unsigned int& GetNodeY( void ) const;
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_NODEDTO_H_ */