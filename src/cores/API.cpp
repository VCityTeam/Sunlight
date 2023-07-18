#include <iostream>

#include "API.h"
#include <maths/Ray.h>
#include <maths/RayHit.h>
#include <maths/Triangle.h>
#include <maths/AABB.h>
#include <maths/RayTracing.h>

bool isFacingTheSun(const Triangle& triangle, const TVec3d& sunPosition)
{
   return 0.0 <= triangle.getNormal().dot(sunPosition);
}

std::vector<RayHit> checkIntersectionWith(const Ray& ray, const std::vector<AABB>& boundingBoxes)
{
   std::cout << "Check intersection with a bounding box vector containing " << boundingBoxes.size() << " AABB." << std::endl;

   auto result = std::vector<RayHit>();

   for (const auto& boundingBoxes : boundingBoxes)
   {
      auto rayHit(boundingBoxes.doesIntersect(ray));
      if (!rayHit.has_value())
         continue;

      result.push_back(rayHit.value());
   }

   // Sort by distance (from near to far)
   std::sort(result.begin(), result.end(), [](const RayHit& a, const RayHit& b)
   {
      return a.distance < b.distance;
   });

   return result;
}

std::vector<RayHit> checkIntersectionWith(const Ray& ray, const std::vector<Triangle>& triangleSoup)
{
   std::cout << "Check intersection with a triangle soup containing " << triangleSoup.size() << " triangles." << std::endl;

   auto result = std::vector<RayHit>();

   for (const auto& triangle : triangleSoup)
   {
      auto rayHit(triangle.doesIntersect(ray));
      if (!rayHit.has_value())
         continue;

      result.push_back(rayHit.value());
   }

   // Sort by distance (from near to far)
   std::sort(result.begin(), result.end(), [](const RayHit& a, const RayHit& b)
   {
      return a.distance < b.distance;
   });

   return result;
}