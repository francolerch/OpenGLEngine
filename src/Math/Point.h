#pragma once

template <typename T>
struct _Point
{
	T x;
	T y;

	_Point() = delete;
	explicit _Point<T>(const T& x, const T& y) : x(x), y(y) {};
	explicit _Point<T>(const _Point& p) : x(p.x), y(p.y) {};
	~_Point() = default;

	_Point<T>& operator=(const T& p)
	{
		if (*this == p)
			return *this;
		x = p.x;
		y = p.y;
		return *this;
	}
	_Point<T>& operator+=(const T& p)
	{
		x += p.x;
		y += p.y;
		return *this;
	}
	_Point<T>& operator-=(const T& p)
	{
		x -= p.x;
		y -= p.y;
		return *this;
	}
	_Point<T>& operator*=(const T& p)
	{
		x *= p.x;
		y *= p.y;
		return *this;
	}
	_Point<T>& operator/=(const T& p)
	{
		x /= p.x;
		y /= p.y;
		return *this;
	}
	_Point<T>& operator+(const T& p) const
	{
		return _Point(*this) += p;
	}
	_Point<T>& operator-(const T& p) const
	{
		return _Point(*this) -= p;
	}
	_Point<T>& operator*(const T& p) const
	{
		return _Point(*this) *= p;
	}
	_Point<T>& operator/(const T& p) const
	{
		return _Point(*this) /= p;
	}
	bool operator==(const Point<T>& p)
	{
		return x == p.x && y = p.y;
	}
	bool operator!=(const Point<T>& p)
	{
		return !(*this == p);
	}
};

typedef _Point<float> Point;
typedef _Point<double> Pointd;
typedef _Point<int> Pointi;