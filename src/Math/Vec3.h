#pragma once
#include "Math.h"
#include "Vec2.h"

template<typename T>
struct _Vec3 : public _Vec2<T>
{
	T z;

	_Vec3() = delete;
	_Vec3(T x, T y, T z) : _Vec2(x, y), z(z) {};
	_Vec3(_Vec2<T> v2, T z) : _Vec2(v2), z(z) {};
	virtual ~_Vec3() {};
	template <typename T2>
	explicit operator _Vec3<T2>() const
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
	_Vec3& Normalize()
	{
		const T length = Length();
		x /= length;
		y /= length;
		z /= length;
		return *this;
	}
	_Vec3 GetNormalized() const
	{
		_Vec3 norm = *this;
		norm.Normalize();
		return norm;
	}
	_Vec3 operator-() const
	{
		return _Vec3(-x, -y, -z);
	}
	_Vec3& operator=(const _Vec3& v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
		return *this;
	}
	_Vec3& operator+=(const _Vec3& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}
	_Vec3& operator-=(const _Vec3& v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return *this;
	}
	T operator*(const _Vec3& v) const
	{
		return x * v.x + y * v.y + z * v.z;
	}
	_Vec3 operator+(const _Vec3& v) const
	{
		return _Vec3(*this) += v;
	}
	_Vec3 operator-(const _Vec3& v) const
	{
		return _Vec3(*this) -= v;
	}
	_Vec3& operator*=(const T& v)
	{
		x *= v;
		y *= v;
		z *= v;
		return *this;
	}
	_Vec3 operator*(const T& v) const
	{
		return _Vec3(*this) *= v;
	}
	_Vec3& operator/=(const T& v)
	{
		x /= v;
		y /= v;
		z /= v;
		return *this;
	}
	_Vec3 operator/(const T& v) const
	{
		return _Vec3(*this) /= v;
	}
	bool operator==(const _Vec3& v) const
	{
		return x == v.x && y == v.y && z == v.z;
	}
	bool operator!=(const _Vec3& v) const
	{
		return !(*this == v);
	}
};

typedef _Vec3<float> Vec3;
typedef _Vec3<double> Vec3d;
typedef _Vec3<int> Vec3i;