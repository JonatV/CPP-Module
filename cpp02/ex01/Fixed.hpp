/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:53:02 by jveirman          #+#    #+#             */
/*   Updated: 2025/03/17 19:53:13 by jveirman         ###   ########.fr       */
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
		Fixed(const float);
		Fixed(const Fixed &);
		~Fixed();
		Fixed	&operator=(const Fixed &);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};
std::ostream &operator<<(std::ostream &cout, const Fixed &fixed);

#endif
