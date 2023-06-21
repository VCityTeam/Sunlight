// Copyright University of Lyon, 2012 - 2017
// Distributed under the GNU Lesser General Public License Version 2.1 (LGPLv2)
// (Refer to accompanying file LICENSE.md or copy at
//  https://www.gnu.org/licenses/old-licenses/lgpl-2.1.html )

#include "URI.h"

URI::URI()
    : m_depth(0), m_cursor(0), m_type(), m_uri()
{

}

void URI::append(const std::string& node, const std::string& type)
{
    m_uri.push_back(node);
    m_types.push_back(type);
    ++m_depth;
}

void URI::prepend(const std::string& node, const std::string& type)
{
    m_uri.insert(m_uri.begin(), node);
    m_types.insert(m_types.begin(), type);
    ++m_depth;
}

void URI::setType(const std::string& type)
{
    m_type = type;
}

int URI::getDepth() const
{
    return m_depth;
}

int URI::getCursor() const
{
    return m_cursor;
}

void URI::resetCursor() const
{
    m_cursor = 0;
}

const std::string& URI::getNode(int depth) const
{
    return m_uri[depth];
}

const std::string& URI::getNodeType(int depth) const
{
    return m_types[depth];
}

const std::string& URI::getCurrentNode() const
{
    return m_uri[m_cursor];
}

const std::string& URI::getCurrentNodeType() const
{
    return m_types[m_cursor];
}

const std::string& URI::getLastNode() const
{
    return m_uri[m_depth-1];
}

void URI::popBack()
{
    if(m_depth > 0)
    {
        m_uri.pop_back();
        --m_depth;
    }
}

void URI::popFront() const
{
    //if(m_cursor < m_depth)
        ++m_cursor;
}

const std::string& URI::getType() const
{
    return m_type;
}

std::vector<std::string>& URI::getURI()
{
    return m_uri;
}

const std::vector<std::string>& URI::getURI() const
{
    return m_uri;
}

std::string URI::getStringURI(bool includeType) const
{
    std::string res;
    if(includeType) res = m_type + ':';
    for(std::vector<std::string>::const_iterator it = m_uri.begin(); it < m_uri.end(); ++it)
    {
        res += *it + '.';
    }
    return res;
}

bool operator==(const URI& rhs, const URI& lhs)
{
    return rhs.getStringURI() == lhs.getStringURI();
}
