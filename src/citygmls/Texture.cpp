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

#include "Texture.h"

Texture::Texture( const std::string& id )
    : Appearance( id, "Texture" ), _repeat( false ), _wrapMode( WM_NONE )
{}

std::string Texture::getUrl( void ) const
{
    return _url;
}

void Texture::setUrl(const std::string& url)
{
    _url = url;
}

bool Texture::getRepeat( void ) const
{
    return _repeat;
}

Texture::WrapMode Texture::getWrapMode( void ) const
{
    return _wrapMode;
}

TVec4f Texture::getBorderColor( void ) const
{
    return _borderColor;
}

std::string Texture::toString( void ) const
{
    return Appearance::toString() + " (url: " + _url + ")";
}