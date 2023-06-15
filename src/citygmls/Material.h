/* -*-c++-*- libcitygml - Copyright (c) 2010 Joachim Pouderoux, BRGM
*
* This file is part of libcitygml library
* http://code.google.com/p/libcitygml
*
* libcitygml is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 2.1 of the License, or
* (at your option) any later version.
*
* libcitygml is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Lesser General Public License for more details.
*/

#pragma once

#include "Appearance.h"
#include <glm/vec3.hpp>

class Material : virtual public Appearance
{
    friend class CityGMLHandler;
public:
    Material( const std::string& id );

    glm::vec3 getDiffuse() const;
    glm::vec3 getEmissive() const;
    glm::vec3 getSpecular() const;
    float getAmbientIntensity() const;
    float getShininess() const;
    float getTransparency() const;

protected:
    glm::vec3 _diffuse;
    glm::vec3 _emissive;
    glm::vec3 _specular;
    float _ambientIntensity;
    float _shininess;
    float _transparency;
};