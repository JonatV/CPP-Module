/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:56:04 by jveirman          #+#    #+#             */
/*   Updated: 2024/12/19 16:56:05 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain{
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(const Brain &);
		~Brain();

		Brain &operator=(const Brain &);

		std::string getIdea(int index) const;

		void setIdea(const std::string &idea, int index);
		
};

#endif
