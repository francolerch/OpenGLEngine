#pragma once
#include "Math.h"
#include "Vec3.h"

template<typename T>
struct _Vec4 : public _Vec3<T>
{
	T w;

	_Vec4() = delete;
	_Vec4(T x, T y, T z, T w) : _Vec3(x, y, z), w(w) {};
	_Vec4(const _Vec3& v3, float w = 1.0f) : _Vec3(v3), w(w) {};
	virtual ~_Vec4() {};
	template <typename T2>
	explicit operator _Vec4<T2>() const
	{
		return{ (T2)x,(T2)y };
	}
	T LengthSq() const
	{
		return Sq(*this);
	}
	T Length() const
	{
		return sqrt(LengthSq());
	}
	_Vec4& Normalize()
	{
		const T length = Length();
		x /= length;
		y /= length;
		z /= length;
		w /= length;
		return *this;
	}
	_Vec4 GetNormalized() const
	{
		_Vec4 norm = *this;
		norm.Normalize();
		return norm;
	}
	_Vec4 operator-() const
	{
		return _Vec4(-x, -y, -z, -w);
	}
	_Vec4& operator=(const _Vec4& v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
		w = v.w;
		return *this;
	}
	_Vec4& operator+=(const _Vec4& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
		w += v.w;
		return *this;
	}
	_Vec4& operator-=(const _Vec4& v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		w -= v.w;
		return *this;
	}
	T operator*(const _Vec4& v) const
	{
		return x * v.x + y * v.y + z * v.z + w * v.w;
	}
	_Vec4 operator+(const _Vec4& v) const
	{
		return _Vec4(*this) += v;
	}
	_Vec4 operator-(const _Vec4& v) const
	{
		return _Vec4(*this) -= v;
	}
	_Vec4& operator*=(const T& v)
	{
		x *= v;
		y *= v;
		z *= v;
		w *= v;
		return *this;
	}
	_Vec4 operator*(const T& v) const
	{
		return _Vec4(*this) *= v;
	}
	_Vec4& operator/=(const T& v)
	{
		x /= v;
		y /= v;
		z /= v;
		w /= v;
		return *this;
	}
	_Vec4 operator/(const T& v) const
	{
		return _Vec4(*this) /= v;
	}
	bool operator==(const _Vec4& v) const
	{
		return x == v.x && y == v.y && z == v.z && w == v.w;
	}
	bool operator!=(const _Vec4& v) const
	{
		return !(*this == v);
	}
};

typedef _Vec4<float> Vec4;
typedef _Vec4<double> Vec4d;
typedef _Vec4<int> Vec4i;