#ifndef FIXED_HPP
#define FIXED_HPP

#include "Fixed.hpp"

class Fixed {
	private:
		int value;
		static const int bits = 8;
	public:
		Fixed();
		Fixed(const Fixed &);
		~Fixed();
		Fixed &operator=(const Fixed &);
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
