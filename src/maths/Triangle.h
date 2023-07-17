// Copyright University of Lyon, 2012 - 2017
// Distributed under the GNU Lesser General Public License Version 2.1 (LGPLv2)
// (Refer to accompanying file LICENSE.md or copy at
//  https://www.gnu.org/licenses/old-licenses/lgpl-2.1.html )

#pragma once

#include <vector>
#include <string>
#include <memory>
#include <optional>

#include <maths/Vector3.h>


#ifdef _MSC_VER
#pragma warning(disable: 4251) // VC++ DLL jejune complains on STL _Id member
#endif

enum CityObjectsType : int;
struct Ray;
struct RayHit;

/**
*	@brief A triangle created from a citygml polygon
*/
struct Triangle
{
    /**
    *	@brief Build a new triangle
    *	@param a First point of the triangle
    *	@param b Second point of the triangle
    *	@param c Third point of the triangle
    */
    Triangle(TVec3d a = TVec3d(0.0, 0.0, 0.0), TVec3d b = TVec3d(0.0, 0.0, 0.0), TVec3d c = TVec3d(0.0, 0.0, 0.0));

    Triangle(const TVec3d& _a, const TVec3d& _b, const TVec3d& _c, const std::string& triangleId, const std::string& tileName);

    /**
     * @brief Get normal of the current normal.
     * @return Normalized Vec3d corresponding to the triangle normal.
    */
    TVec3d getNormal() const;

    /**
     * @brief Get the triangle id that can be used to identify one
     *         triangle in a triangle soup.
     * @return
    */
    const std::string& getId() const;

    /**
     * @brief Get tile name containing the current triangle.
     * @return
    */
    const std::string& getTileName() const;

    /**
     * @brief Check intersection between a ray and a triangle.
     * @param ray
     * @return An optional RayHit that can be used to check if there is any intersection.
    */
    std::optional<RayHit> doesIntersect(const Ray& ray) const;

    /**
     * @brief First Vertices of the triangle.
    */
    TVec3d a;

    /**
     * @brief Second Vertices of the triangle.
    */
    TVec3d b;

    /**
     * @brief Third Vertices of the triangle.
    */
    TVec3d c;

    CityObjectsType objectType;
    CityObjectsType subObjectType;
    std::string objectId;
    std::string polygonId;

    /**
     * @brief Triangle identifier.
    */
    std::string m_id;

    /**
     * @brief Tile name containing the actual triangle.
    */
    std::string m_tileName;
};

/**
*	@brief Build list of triangle from a CityGML building tile
*	@param tile CityGML tile from which we want the triangle list
*	@param viewpoint Data about the viewpoint we are rendering
*	@param objectType The type of cityobject to load
*   @param cityObjId The id of city object to load.
*          Default = "" (i.e. all cityobjects of the tile are loaded)
*   @param zMin A minimum z value of triangles to load
*          (if all vertices of the triangle are below this zMin value, triangle is not loaded)
*          Default = -10000.0
*	@return The list of triangle from the CityGML tile
*/
std::vector<std::shared_ptr<Triangle>>* BuildTriangleList(
    const std::string& tilefilename,
    const CityObjectsType& objectType,
    const std::string& cityObjId = "",
    const double& zMin = -10000.0
);
