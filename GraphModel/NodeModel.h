/*
 * This file is part of minotaur.
 *
 * File: NodeModel.h
 * Brief: Declaration of node model class.
 *
 * Date: 29.07.2013
 * Author: Andrzej Korycinski
 *
 * */

#ifndef _MINOTAUR_NODEMODEL_H_
#define _MINOTAUR_NODEMODEL_H_

namespace Minotaur
{

class CNodeModel
{
	private:
		unsigned int m_nodeId;
        unsigned int m_nodeX;
        unsigned int m_nodeY;

	public:
		CNodeModel( void ) = default;
        CNodeModel( const unsigned int& nodeId, const unsigned int& nodeX, const unsigned int& nodeY );
        ~CNodeModel( void );

        bool operator==( const CNodeModel& nodeToCompare );

        const unsigned int& GetNodeId( void ) const;
        const unsigned int& GetNodeX( void ) const;
        const unsigned int& GetNodeY( void ) const;

		struct SNodeModelLess
        {
                bool operator()(const CNodeModel& lNodeModel, const CNodeModel& rNodeModel) const
                {
                        return ( ( lNodeModel.m_nodeId ) < ( rNodeModel.m_nodeId) );
                }
        };
};

} // namespace Minotaur

#endif /* _MINOTAUR_NODEMODEL_H_ */