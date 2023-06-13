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

#include <maths/Vectors.h>
#include "Appearance.h"

#ifdef _MSC_VER
#pragma warning(disable: 4251) // VC++ DLL jejune complains on STL members
#endif

class Texture : virtual public Appearance
{
    friend class CityGMLHandler;

public:
    typedef enum WrapMode
    {
        WM_NONE = 0,	// the resulting color is fully transparent
        WM_WRAP,		// the texture is repeated
        WM_MIRROR,		// the texture is repeated and mirrored
        WM_CLAMP,		// the texture is clamped to its edges
        WM_BORDER		// the resulting color is specified by the borderColor element (RGBA)
    } WrapMode;

    Texture( const std::string& id );

    std::string getUrl() const;

    void setUrl(const std::string& url);

    bool getRepeat() const;

    WrapMode getWrapMode() const;

    TVec4f getBorderColor() const;

    std::string toString() const;

protected:
    std::string _url;
    bool _repeat;
    WrapMode _wrapMode;
    TVec4f _borderColor;
};