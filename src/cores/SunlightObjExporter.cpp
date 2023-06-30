#include <iostream>
#include <fstream>

#include "SunlightObjExporter.h"
#include <utils/DateTime.h>
#include <utils/Utils.h>


void SunlightObjExporter::exportResult(std::map<int, bool>& sunInfo, const std::shared_ptr<Triangle>& t, const FileInfo& file, int iStartDate, int iEndDate, const std::string& outputDir)
{
   glm::vec3 shadowRgb(0, 0, 1);
   glm::vec3 lightRgb(1, 0, 0);

   for (const auto& [iDate, bTriangleInLight] : sunInfo)
   {
      std::string datetime = decodeDateTime(iDate);
      datetime.replace(datetime.find(':'), 1, " ");

      std::ofstream ofs;
      ofs.open(outputDir + "/Sunlight/" + file.withPrevFolder() + "/" + datetime + ".obj", std::ofstream::app);

      glm::vec3 currentRgb = shadowRgb;
      if (bTriangleInLight)
      {
         currentRgb = lightRgb;
      }

      // Store vertex position and sunlight color as xyz rgb
      ofs << "v " << t->a.x << " " << t->a.y << " " << t->a.z << " " << currentRgb.r << " " << currentRgb.g << " " << currentRgb.b << std::endl;
      ofs << "v " << t->b.x << " " << t->b.y << " " << t->b.z << " " << currentRgb.r << " " << currentRgb.g << " " << currentRgb.b << std::endl;
      ofs << "v " << t->c.x << " " << t->c.y << " " << t->c.z << " " << currentRgb.r << " " << currentRgb.g << " " << currentRgb.b << std::endl;

      ofs << "f " << m_VertexIndex << " " << m_VertexIndex + 1 << " " << m_VertexIndex + 2 << std::endl;

      ofs.close();
   }

   m_VertexIndex += 3;
}