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

#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <filesystem>
#include <iterator>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

#include <cores/FileInfo.h>

namespace fs = std::filesystem;

// Helpers

// std::string tokenizer
inline std::vector<std::string> tokenize( const std::string& str, const std::string& delimiters = ",|& " )
{
    std::vector<std::string> tokens;
    std::string::size_type lastPos = str.find_first_not_of( delimiters, 0 );
    std::string::size_type pos = str.find_first_of( delimiters, lastPos );

    while ( pos != std::string::npos || lastPos != std::string::npos )
    {
        tokens.push_back( str.substr( lastPos, pos - lastPos ) );
        lastPos = str.find_first_not_of( delimiters, pos );
        pos = str.find_first_of( delimiters, lastPos );
    }
    return tokens;
}

inline bool ci_string_compare( const std::string& str1, const std::string& str2 ) 
{
    std::string s1( str1 );
    std::transform( s1.begin(), s1.end(), s1.begin(), ::tolower );	
    std::string s2( str2 );
    std::transform( s2.begin(), s2.end(), s2.begin(), ::tolower );
    return s1 == s2;
}

inline std::string trim_left( const std::string& s, const std::string& t = " \t\r\n" ) 
{ 
    std::string d( s ); 
    return d.erase( 0, s.find_first_not_of( t ) ); 
} 

inline std::string trim_right( const std::string& s, const std::string& t = " \t\r\n" )
{
    std::string d( s ); 
    size_t endpos = d.find_last_not_of( t );
    return ( endpos != std::string::npos ) ? d.erase( endpos + 1 ) : d;
}

inline std::string trim( const std::string& s, const std::string& t = " \t\r\n" )
{
    return trim_left( trim_right( s, t ), t );
}

static bool areFilesIdentical(const std::string& file1, const std::string& file2)
{
    std::ifstream ifs1(file1);
    std::ifstream ifs2(file2);

    // Failed to open one or both files
    if (!ifs1.is_open() || !ifs2.is_open())
    {
        return false;
    }

    return std::equal(
        std::istreambuf_iterator<char>(ifs1),
        std::istreambuf_iterator<char>(),
        std::istreambuf_iterator<char>(ifs2)
    );
}

/// <summary>
/// Add vector 3 information in the stream,
/// because glm doesn't provide one
/// </summary>
/// <param name="os"></param>
/// <param name="v"></param>
/// <returns></returns>
std::ostream& operator<<(std::ostream& os, const glm::highp_dvec3& v);

std::ostream& operator<<(std::ostream& os, const glm::vec3& v);

/// <summary>
/// Add vector 2 information in the stream,
/// because glm doesn't provide one
/// </summary>
/// <param name="os"></param>
/// <param name="v"></param>
/// <returns></returns>
std::ostream& operator<<(std::ostream& os, const glm::vec2& v);

std::istream& operator>>(std::istream& is, glm::highp_dvec3& v);

std::istream& operator>>(std::istream& is, glm::vec3& v);

std::istream& operator>>(std::istream& is, glm::vec2& v);

/**
 * @brief Search all gml files in layerFolder and create FileInfos instances
 * @param layerFolder Layer folder containing all tiles folder and tiles glm (e.g _BATI/3615_2590/3615_2590.gml)
 * @return A vector of FileInfo describing all gml files in the correct folder structure
*/
std::vector<FileInfo*> searchGmlFilesInLayer(const fs::directory_entry& layerFolder);

/**
 * @brief Get all Tiles in a directory (following the folder structure of sunlight)
 * @param cityGmlDirectory Root directory containing subdirectories of layers (_BATI or _MNT)
 * @return A vectir if FileInfo corresponding to each layer
*/
std::vector<FileInfo*> getAllTilesIn(const std::string& cityGmlDirectory);
