/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:42:16 by jveirman          #+#    #+#             */
/*   Updated: 2025/03/09 18:46:40 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename Type>
void	swap(Type &a, Type &b)
{
	Type	temp;

	temp = a;
	a = b;
	b = temp;
}

template <typename Type>
Type	min(Type a, Type b)
{
	return (a < b ? a : b);
}

template <typename Type>
Type	max(Type a, Type b)
{
	return (a > b ? a : b);
}

#endif
