#pragma once
#include "Math.h"

template<typename T>
struct _Vec2
{
	T x;
	T y;

	_Vec2() = delete;
	_Vec2(T x, T y) : x(x), y(y) {};
	virtual ~_Vec2() {};
	template <typename T2>
	explicit operator _Vec2<T2>() const
	{
		return { (T2)x,(T2)y };
	}
	T LengthSq() const
	{
		return Sq(*this);
	}
	T Length() const
	{
		return sqrt(LengthSq());
	}
	_Vec2& Normalize()
	{
		const T length = Length();
		x /= length;
		y /= length;
		return *this;
	}
	_Vec2 GetNormalized() const
	{
		_Vec2 norm = *this;
		norm.Normalize();
		return norm;
	}
	_Vec2 operator-() const
	{
		return _Vec2(-x, -y);
	}
	_Vec2& operator=(const _Vec2 & v)
	{
		x = v.x;
		y = v.y;
		return *this;
	}
	_Vec2& operator+=(const _Vec2 & v)
	{
		x += v.x;
		y += v.y;
		return *this;
	}
	_Vec2& operator-=(const _Vec2 & v)
	{
		x -= v.x;
		y -= v.y;
		return *this;
	}
	T operator*(const _Vec2 & v) const
	{
		return x * v.x + y * v.y;
	}
	_Vec2 operator+(const _Vec2 & v) const
	{
		return _Vec2(*this) += v;
	}
	_Vec2 operator-(const _Vec2 & v) const
	{
		return _Vec2(*this) -= v;
	}
	_Vec2& operator*=(const T & v)
	{
		x *= v;
		y *= v;
		return *this;
	}
	_Vec2 operator*(const T & v) const
	{
		return _Vec2(*this) *= v;
	}
	_Vec2& operator/=(const T & v)
	{
		x /= v;
		y /= v;
		return *this;
	}
	_Vec2 operator/(const T & v) const
	{
		return _Vec2(*this) /= v;
	}
	bool operator==(const _Vec2 & v) const
	{
		return x == v.x && y == v.y;
	}
	bool operator!=(const _Vec2 & v) const
	{
		return !(*this == v);
	}
};

typedef _Vec2<float> Vec2;
typedef _Vec2<double> Vec2d;
typedef _Vec2<int> Vec2i;