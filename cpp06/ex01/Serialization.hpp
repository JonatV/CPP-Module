/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:33:47 by jveirman          #+#    #+#             */
/*   Updated: 2025/03/07 12:44:35 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <iostream>
#include <stdint.h>


typedef struct s_Data
{
	int		num01;
	int		num02;
	char	c;
	bool	b;
}	Data;

// info:	This function is use to transform a Data obj with its info
//			into a int value pointer. We call it serialize.
//			Then we can convert this value back to the obj it was.
//			It save spaces and time.
//			We don't lose the information - it's called Deserialize.
// Why:		We can use it to send the object over a network and then
//			recreate it on the other side.
//			Or to save the object to a database, like a backup. And restore it later.

class Serialization
{
	private:
		Serialization();
		~Serialization();
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif
