/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:55:22 by jveirman          #+#    #+#             */
/*   Updated: 2025/03/26 09:35:28 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
#include <string>

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat &);
		~Cat();
		Cat &operator=(const Cat &);
		void makeSound() const;
};


#endif
