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

#include <stdint.h>
#include <algorithm>

namespace Minotaur
{

class CEdgeModel
{
	private:
		unsigned int m_nodeFromId;
        unsigned int m_nodeToId;
        double m_edgeWeight;

	public:
		CEdgeModel( void );
        CEdgeModel( const unsigned int& nodeFromId, const unsigned int& nodeToId, const double& edgeWeight );
        ~CEdgeModel( void );

        bool operator==( const CEdgeModel& edgeToCompare );

        const unsigned int& GetNodeFromId( void ) const;
        const unsigned int& GetNodeToId( void ) const;
		const double& GetEdgeWeight( void ) const;
		
		struct SEdgeModelLess
        {
                bool operator()(const CEdgeModel& lEdgeModel, const CEdgeModel& rEdgeModel) const
                {
					uint64_t f_lhs = static_cast<uint64_t>(lEdgeModel.m_nodeFromId);
					uint64_t t_lhs = static_cast<uint64_t>(lEdgeModel.m_nodeToId);

					uint64_t min_lhs = 0;
					uint64_t max_lhs = 0;
					std::tie(min_lhs, max_lhs) = std::minmax(f_lhs, t_lhs);

					uint64_t f_rhs = static_cast<uint64_t>(rEdgeModel.m_nodeFromId);
					uint64_t t_rhs = static_cast<uint64_t>(rEdgeModel.m_nodeToId);

					uint64_t min_rhs = 0;
					uint64_t max_rhs = 0;
					std::tie(min_rhs, max_rhs) = std::minmax(f_rhs, t_rhs);

					uint64_t sum_lhs = (max_lhs << 32) | min_lhs;
					uint64_t sum_rhs = (max_rhs << 32) | min_rhs;

					return ( sum_lhs < sum_rhs );
                }
        };

};

} // namespace Minotaur

#endif /* _MINOTAUR_EDGEMODEL_H_ */