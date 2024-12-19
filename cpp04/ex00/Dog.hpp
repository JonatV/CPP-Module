/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:55:20 by jveirman          #+#    #+#             */
/*   Updated: 2024/12/19 16:55:20 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include <string>

class Dog : public Animal
{
	private:
		// std::string type;
	public:
		Dog();
		Dog(const Dog &);
		~Dog();

		Dog &operator=(const Dog &);

		void makeSound() const;
};


#endif
