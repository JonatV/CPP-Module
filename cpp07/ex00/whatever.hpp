/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:42:16 by jveirman          #+#    #+#             */
/*   Updated: 2025/03/09 18:55:38 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename Type>
void	swap(Type &a, Type &b)
{
	Type	temp;
	
	std::cout << "Swap " << a << " with " << b << std::endl;
	temp = a;
	a = b;
	b = temp;
}

template <typename Type>
Type	min(Type a, Type b)
{
	if (a == b)
	{
		std::cout << "Both are equal, returning first value : ";
		return (a);
	}
	return (a < b ? a : b);
}

template <typename Type>
Type	max(Type a, Type b)
{	
	if (a == b)
	{
		std::cout << "Both are equal, returning first value : ";
		return (a);
	}
	return (a > b ? a : b);
}

#endif
