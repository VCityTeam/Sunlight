// Copyright University of Lyon, 2012 - 2017
// Distributed under the GNU Lesser General Public License Version 2.1 (LGPLv2)
// (Refer to accompanying file LICENSE.md or copy at
//  https://www.gnu.org/licenses/old-licenses/lgpl-2.1.html )

#pragma once

#include <glm/vec3.hpp>

#include <string>
#include <vector>

#ifdef _MSC_VER
#pragma warning(disable: 4251) // VC++ DLL jejune complains on STL _Id member
#endif

// FIXME: convert this file to plain ascii (remove accented letters)

/**
*	@brief An axis aligned bounding box
*/
struct AABB
{
    glm::highp_dvec3 min;///< Min point of the box
    glm::highp_dvec3 max;///< Max point of the box
    std::string name;///< Name of the box

    bool operator==(AABB const& other);
};

/**
*	Used when ordering a collection of bounding boxes
*/
struct BoxOrder
{
    std::string box;///< Name of the bounding box
    unsigned int order;///< Order of the box in the collection
};

bool operator<(const BoxOrder& a, const BoxOrder& b);

/**
*	@brief Pour une box, contient un certain nombre d'informations lies aux rayons que l'on aura tente d'intersecter avec celle ci.
*/
struct BoxwithRays
{
    AABB box; //  Box concernee
    std::vector<int> IndicesRays; //Contient les indices des rayons qui ont intersecte cette box
    float minDistance; //Distance minimale entre la box et la camera
};

bool operator<(const BoxwithRays& a, const BoxwithRays& b);

/**
*	Used to store a bounding box collection for different layers
*/
struct AABBCollection
{
    std::vector<AABB> building;///< Bounding box of the building layer
    std::vector<AABB> terrain;///< Bounding box of the terrain layer
    // #AABBNewDataSet
    // Uncomment next comment to add a data set (and replace myData by your data)
    // std::vector<AABB> myData;
};
