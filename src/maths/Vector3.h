// Copyright University of Lyon, 2012 - 2017
// Distributed under the GNU Lesser General Public License Version 2.1 (LGPLv2)
// (Refer to accompanying file LICENSE.md or copy at
//  https://www.gnu.org/licenses/old-licenses/lgpl-2.1.html )

#pragma once

#include <iostream>
#include <math.h>

// 3D vector class.
template< class T > class TVec3
{
public:
	union
	{
		T xyz[3];
		T rgb[3];
		struct { T x, y, z; };
		struct { T r, g, b; };
	};

public:
	TVec3(const T x = (T)0, const T y = (T)0, const T z = (T)0);
	TVec3(const T vec[]);

	inline T length() const;
	inline T sqrLength() const;

   // Wrap x, y, z to expose these value in swig because swig doesn't support nested union
   T getX() const { return x; }
   T getY() const { return y; }
   T getZ() const { return z; }

	T dot(const TVec3<T>& vec) const;
	TVec3 cross(const TVec3<T>& vec) const;

	TVec3  normalize() const;
	TVec3& normalEq();
	TVec3& normalEq(const T length);

	TVec3 operator+(const TVec3<T>& rhs) const;
	TVec3 operator+(const T& _v) const;
	TVec3 operator-(const TVec3<T>& rhs) const;
	TVec3 operator-(const T& _v) const;
	TVec3 operator-() const;
	TVec3 operator*(const T& rhs) const;
	TVec3 operator*(const TVec3<T>& rhs) const;
	TVec3 operator/(const T& rhs) const;
	TVec3 operator/(const TVec3<T>& rhs) const;

	inline bool operator==(const TVec3<T>& rhs) const;
	inline bool operator!=(const TVec3<T>& rhs) const;

	inline operator T* () { return xyz; }
	inline operator const T* () const { return xyz; }
};

template< class T > inline TVec3<T>::TVec3(const T x, const T y, const T z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

template< class T >	inline TVec3<T>::TVec3(const T vec[])
{
	memcpy(xyz, vec, 3 * sizeof(T));
}

template< class T > inline T TVec3<T>::length() const
{
	return (T)sqrt(x * x + y * y + z * z);
}

template< class T > inline T TVec3<T>::sqrLength() const
{
	return x * x + y * y + z * z;
}

template< class T > inline T TVec3<T>::dot(const TVec3<T>& vec) const
{
	return x * vec.x + y * vec.y + z * vec.z;
}

template< class T > inline TVec3<T> TVec3<T>::cross(const TVec3<T>& vec) const
{
	return TVec3<T>(y * vec.z - z * vec.y, z * vec.x - x * vec.z, x * vec.y - y * vec.x);
}

template< class T > inline TVec3<T> TVec3<T>::normalize() const
{
	const T len = length();
	const T tmp = (len != (T)0) ? ((T)1 / len) : (T)0;
	return TVec3<T>(x * tmp, y * tmp, z * tmp);
}

template< class T > inline TVec3<T>& TVec3<T>::normalEq()
{
	const T len = length();
	const T tmp = (len != (T)0) ? ((T)1 / len) : (T)0;
	x *= tmp;
	y *= tmp;
	z *= tmp;
	return *this;
}

template< class T > inline TVec3<T>& TVec3<T>::normalEq(const T length)
{
	const T len = TVec3<T>::length();
	const T tmp = (len != (T)0) ? length / len : (T)0;
	x *= tmp;
	y *= tmp;
	z *= tmp;
	return *this;
}

template< class T > inline TVec3<T> TVec3<T>::operator+(const TVec3<T>& rhs) const
{
	return TVec3<T>(x + rhs.x, y + rhs.y, z + rhs.z);
}

template< class T >	inline TVec3<T> TVec3<T>::operator+(const T& _v) const
{
	return TVec3<T>(x + _v, y + _v, z + _v);
}

template< class T > inline TVec3<T> TVec3<T>::operator-(const TVec3<T>& rhs) const
{
	return TVec3<T>(x - rhs.x, y - rhs.y, z - rhs.z);
}

template< class T > inline TVec3<T> TVec3<T>::operator-(const T& _v) const
{
	return TVec3<T>(x - _v, y - _v, z - _v);
}

template< class T >	inline TVec3<T> TVec3<T>::operator-() const
{
	return TVec3<T>(-x, -y, -z);
}

template< class T > inline TVec3<T> TVec3<T>::operator*(const T& rhs) const
{
	return TVec3<T>(x * rhs, y * rhs, z * rhs);
}

template< class T >	inline TVec3<T> TVec3<T>::operator*(const TVec3<T>& rhs) const
{
	return TVec3<T>(x * rhs.x, y * rhs.y, z * rhs.z);
}

template< class T > inline TVec3<T> TVec3<T>::operator/(const T& rhs) const
{
	return TVec3<T>(x / rhs, y / rhs, z / rhs);
}

template< class T > inline TVec3<T> TVec3<T>::operator/(const TVec3<T>& rhs) const
{
	return TVec3<T>(x / rhs.x, y / rhs.y, z / rhs.z);
}

template< class T > inline bool TVec3<T>::operator==(const TVec3<T>& rhs) const
{
	return x == rhs.x && y == rhs.y && z == rhs.z;
}

template< class T > inline bool TVec3<T>::operator!=(const TVec3<T>& rhs) const
{
	return x != rhs.x || y != rhs.y || z != rhs.z;
}

template< class T >	inline TVec3<T> operator*(const T& val, const TVec3<T>& vec)
{
	return TVec3<T>(vec.x * val, vec.y * val, vec.z * val);
}

template<class T> inline std::ostream& operator<<(std::ostream& os, TVec3<T> const& v)
{
	return os << "(" << std::fixed << v.x << "," << std::fixed << v.y << "," << std::fixed << v.z << ")";
}

template<class T> inline std::istream& operator>>(std::istream& is, TVec3<T>& v)
{
	return is >> v.x >> v.y >> v.z;
}

typedef TVec3< float >			TVec3f;
typedef TVec3< double >			TVec3d;
