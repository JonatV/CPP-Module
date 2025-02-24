/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:53:23 by jveirman          #+#    #+#             */
/*   Updated: 2024/12/19 16:53:24 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <cmath>

static float calc_area(Point const a, Point const b, Point const c)
{
	float area = (a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) 
					+ b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()) 
					+ c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())) / 2;
	
	return (std::abs(area));
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float areaBaseTriangle, areaABP, areaACP, areaBCP, epsilon;

	std::cout << "\e[0;36ma: (" << a.getX() << ", " << a.getY() << ")\n";
	std::cout << "b: (" << b.getX() << ", " << b.getY() << ")\n";
	std::cout << "c: (" << c.getX() << ", " << c.getY() << ")\n";
	std::cout << "Test point: (" << point.getX() << ", " << point.getY() << ")\e[0m\n\n";

	areaBaseTriangle = calc_area(a, b, c);
	areaABP = calc_area(a, b, point);
	areaACP = calc_area(a, c, point);
	areaBCP = calc_area(b, c, point);
	epsilon = 0.001f;

	std::cout << "\e[35mBase Triangle Area: " << areaBaseTriangle << std::endl;
	std::cout << "Area ABP: " << areaABP << std::endl;
	std::cout << "Area ACP: " << areaACP << std::endl;
	std::cout << "Area BCP: " << areaBCP << "\e[0m\n" << std::endl;

	if (areaABP < epsilon || areaACP < epsilon || areaBCP < epsilon)
		return (false);
	if (std::abs(areaBaseTriangle - (areaABP + areaACP + areaBCP)) < epsilon)
		return (true);
	return (false);
}
