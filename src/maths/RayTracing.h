// Copyright University of Lyon, 2012 - 2017
// Distributed under the GNU Lesser General Public License Version 2.1 (LGPLv2)
// (Refer to accompanying file LICENSE.md or copy at
//  https://www.gnu.org/licenses/old-licenses/lgpl-2.1.html )

#pragma once

#include <vector>

struct Hit;
struct Ray;
struct TriangleList;

/**
*	@build Perform raytracing algorithm on a set of triangles
*	@param triangles List of triangle of a CityGML tile
*	@param rays List of rays
*   @param breakOnFirstInter If true, stop raytracing when an intersection is found.
*                            Default : false (compute all intersections between rays and triangles).
*   @return list of hits
*/
std::vector<Hit*>* RayTracing(TriangleList* triangles, const std::vector<Ray*>& rays, bool breakOnFirstInter = false);