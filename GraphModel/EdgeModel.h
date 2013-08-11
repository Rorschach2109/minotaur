/*
 * This file is part of minotaur.
 *
 * File: EdgeModel.h
 * Brief: Declaration of edge model class.
 *
 * Date: 29.07.2013
 * Author: Andrzej Korycinski
 *
 * */

#ifndef _MINOTAUR_EDGEMODEL_H_
#define _MINOTAUR_EDGEMODEL_H_

namespace Minotaur
{

class CEdgeModel
{
	private:
		unsigned int m_nodeFromId;
        unsigned int m_nodeToId;
        double m_edgeWeight;

	public:
		CEdgeModel( void ) = default;
        CEdgeModel( const unsigned int& nodeFromId, const unsigned int& nodeToId, const double& edgeWeight );
        ~CEdgeModel( void );

        bool operator==( const CEdgeModel& edgeToCompare );

        const unsigned int& GetNodeFromId( void ) const;
        const unsigned int& GetNodeToId( void ) const;
		const double& GetEdgeWeight( void ) const;
};

} // namespace Minotaur

#endif /* _MINOTAUR_EDGEMODEL_H_ */