#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed _x;
		const Fixed _y;

	public:
		Point();
		Point(const float, const float);
		Point(const Point &);
		~Point();

		Point &operator=(const Point &);

		const Fixed &getX() const;
		const Fixed &getY() const;
};

#endif
