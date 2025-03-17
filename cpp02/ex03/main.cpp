/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:53:27 by jveirman          #+#    #+#             */
/*   Updated: 2025/03/17 20:52:43 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) {
	bool ret;
	
	std::cout << "\e[1;33mTest 1:\e[0m" << std::endl;
	const Point a;
	const Point b(5.0f, 0.0f);
	const Point c(0.0f, 5.0f);
	const Point point(1.0f, 1.0f);
	ret = bsp(a, b, c, point);
	std::cout << "The point is " << (ret ? "\e[1;32minside.\e[0m\n" : "\e[1;31moutside.\e[0m\n") << std::endl;

	std::cout << "\e[1;33mTest 2:\e[0m" << std::endl;
	const Point a2;
	const Point b2(10.0f, 0.0f);
	const Point c2(0.0f, 10.0f);
	const Point point2(5.0f, 4.9123f);
	ret = bsp(a2, b2, c2, point2);
	std::cout << "The point is " << (ret ? "\e[1;32minside.\e[0m\n" : "\e[1;31moutside.\e[0m\n") << std::endl;
	
	
	std::cout << "\e[1;33mTest 2.1 (copy of 2 with point on an edge):\e[0m" << std::endl;
	const Point point3(5.0f, 5.0f);
	ret = bsp(a2, b2, c2, point3);
	std::cout << "The point is " << (ret ? "\e[1;32minside.\e[0m" : "\e[1;31moutside.\e[0m\n") << std::endl;
	
	std::cout << "\e[1;33mTest 2.2 (out of the triangle):\e[0m" << std::endl;
	const Point point4(11.0f, 0.0f);
	ret = bsp(a2, b2, c2, point4);
	std::cout << "The point is " << (ret ? "\e[1;32minside.\e[0m\n" : "\e[1;31moutside.\e[0m\n") << std::endl;
	return (0);
}
