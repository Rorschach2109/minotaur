/*
 * This file is part of minotaur.
 *
 * File: EdgeDTO.h
 * Brief: Declaration of edge dto class.
 *
 * Date: 22.07.2013
 * Author: Andrzej Korycinski
 * 
 * */
 
#ifndef _MINOTAUR_EDGEDTO_H_
#define _MINOTAUR_EDGEDTO_H_

namespace Minotaur
{

class CEdgeDto
{
	private:
		unsigned int m_nodeFromId;
		unsigned int m_nodeToId;
		double m_weight;
		
	public:
		CEdgeDto( void ) = delete;
		CEdgeDto( const unsigned int& nodeFromId, const unsigned int& nodeToId, const double& weight );
		~CEdgeDto( void );
		
		bool operator==( const CEdgeDto& edgeToCompare );
		
		
		const unsigned int& GetNodeFromId( void ) const;
		const unsigned int& GetNodeToId( void ) const;
		const double& GetWeight( void ) const;
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_EDGEDTO_H_ */