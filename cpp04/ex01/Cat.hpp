/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:56:02 by jveirman          #+#    #+#             */
/*   Updated: 2024/12/19 16:56:03 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Cat : public Animal
{
	private:
		Brain *brain;
	public:
		Cat();
		Cat(const Cat &);
		~Cat();

		Cat &operator=(const Cat &);

		void makeSound() const;
		//set idea in brain
		void setIdeaInBrain(const std::string &idea, int index);
		std::string getIdeaInBrain(int index) const;
};


#endif
