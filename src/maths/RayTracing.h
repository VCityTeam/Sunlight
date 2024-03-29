// Copyright University of Lyon, 2012 - 2017
// Distributed under the GNU Lesser General Public License Version 2.1 (LGPLv2)
// (Refer to accompanying file LICENSE.md or copy at
//  https://www.gnu.org/licenses/old-licenses/lgpl-2.1.html )

#pragma once

#include <vector>
#include <memory>

#include "Ray.h"

struct RayHit;
struct Triangle;

/**
*	@build Perform raytracing algorithm on a set of triangles with a list of rays
*	@param triangles List of triangles
*	@param rays List of rays
*   @param breakOnFirstInter If true, stop raytracing when an intersection is found.
*                            Default : false (compute allB intersections between rays and triangles).
*   @return list of hits
*/
std::vector<RayHit*>* RayTracing(std::vector<std::shared_ptr<Triangle>>* triangles, const std::vector<std::shared_ptr<Ray>>& rays, bool breakOnFirstInter);

/**
*	@build Perform raytracing algorithm on a set of triangles with a given ray
*	@param ray Ray use to check intersection
*	@param triangles List of triangles
*   @return list of all hits
*/
std::vector<RayHit> RayTracing(const Ray& ray, const std::vector<Triangle>& triangles);