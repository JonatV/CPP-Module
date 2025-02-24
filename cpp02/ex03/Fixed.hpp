/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:53:31 by jveirman          #+#    #+#             */
/*   Updated: 2024/12/19 16:53:31 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		bool operator>(const Fixed &) const;
		bool operator<(const Fixed &) const;
		bool operator>=(const Fixed &) const;
		bool operator<=(const Fixed &) const;
		bool operator==(const Fixed &) const;
		bool operator!=(const Fixed &) const;

		Fixed operator+(const Fixed &) const;
		Fixed operator-(const Fixed &) const;
		Fixed operator*(const Fixed &) const;
		Fixed operator/(const Fixed &) const;

		Fixed &operator++(void);
		Fixed operator++(int);
		Fixed &operator--(void);
		Fixed operator--(int);

		static Fixed &min(Fixed &, Fixed &);
		static const Fixed &min(const Fixed &, const Fixed &);
		static Fixed &max(Fixed &, Fixed &);
		static const Fixed &max(const Fixed &, const Fixed &);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};
std::ostream &operator<<(std::ostream &COUT, const Fixed &fixed);

#endif
