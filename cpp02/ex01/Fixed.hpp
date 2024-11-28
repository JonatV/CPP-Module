#ifndef FIXED_HPP
#define FIXED_HPP

#include "Fixed.hpp"
#include <iostream>

class Fixed {
	private:
		int value;
		static const int bits = 8;
	public:
		Fixed();
		Fixed(const int);
		Fixed(const Fixed &);
		Fixed(const float);
		~Fixed();
		Fixed &operator=(const Fixed &);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};
std::ostream &operator<<(std::ostream &COUT, const Fixed &fixed);

#endif
