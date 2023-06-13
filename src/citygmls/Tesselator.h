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

#include <vector>

#ifdef _MSC_VER                  // Inhibit dll-interface warnings concerning
  #pragma warning(disable: 4251) // export problem on STL members
  #	include <windows.h>
#else
  #	define CALLBACK
  #	define APIENTRY
#endif

#ifdef __APPLE__
  #include <OpenGL/glu.h>
#else

#endif

#include <maths/Vectors.h>
// Win32 caveat emptor: must always be _preceded_ (as opposed to
// succeeded) by the inclusion of windows.h
#include <gl/GLU.h>

// GLU based polygon tesselator
class Tesselator 
{		
public:
	Tesselator(); 
	~Tesselator();

	void init( size_t verticesCount, const TVec3d& normal, GLenum winding_rule = GLU_TESS_WINDING_ODD );

	// Add a new contour - add the exterior ring first, then interiors 
	void addContour( const std::vector<TVec3d>&, const std::vector<TVec2f>& );

	// Let's tesselate!
	void compute();

	// Tesselation result access
	inline const std::vector<TVec3d>& getVertices() const { return _vertices; }
	inline const std::vector<TVec2f>& getTexCoords() const { return _texCoords; }
	inline const std::vector<unsigned int>& getIndices() const { return _indices; }

private:
	typedef void (APIENTRY *GLU_TESS_CALLBACK)();
	static void CALLBACK beginCallback( GLenum, void* );
	static void CALLBACK vertexCallback( GLvoid*, void* );
	static void CALLBACK combineCallback( GLdouble[3], void* [4], GLfloat [4], void** , void* );
	static void CALLBACK endCallback( void* );
	static void CALLBACK errorCallback( GLenum, void* );	

private:
	GLUtesselator *_tobj;
	GLenum  _curMode;

	std::vector<TVec3d> _vertices;		
	std::vector<TVec2f> _texCoords;
	std::vector<unsigned int> _indices;

	std::vector<unsigned int> _curIndices;
};