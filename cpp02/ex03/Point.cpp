/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:53:25 by jveirman          #+#    #+#             */
/*   Updated: 2024/12/19 16:53:26 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point &other) : _x(other.getX()), _y(other.getY()) {}

Point &Point::operator=(const Point &) {
	return (*this);
}

Point::~Point() {}

const Fixed &Point::getX() const {
	return (this->_x);
}

const Fixed &Point::getY() const {
	return (this->_y);
}
