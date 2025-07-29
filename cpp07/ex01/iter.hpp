/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:35:23 by jveirman          #+#    #+#             */
/*   Updated: 2025/03/13 15:18:10 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

// pointer to function passed in a function parameter looks like this : void test (*f)(type)
template <typename Addr, typename Func>
void iter(Addr *addr, int len, void (*f)(Func)) 
{
	for (int i = 0; i < len; i++)
		f(addr[i]);
}

#endif
