/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:55:48 by jveirman          #+#    #+#             */
/*   Updated: 2024/12/19 16:55:49 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#include "WrongAnimal.hpp"
#include <string>

class WrongCat : public WrongAnimal
{
	private:
		// std::string type;
	public:
		WrongCat();
		WrongCat(const WrongCat &);
		~WrongCat();

		WrongCat &operator=(const WrongCat &);

		void makeSound() const;
};


#endif
