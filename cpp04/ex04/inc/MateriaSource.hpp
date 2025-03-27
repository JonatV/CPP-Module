/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:04:54 by jveirman          #+#    #+#             */
/*   Updated: 2025/03/27 04:30:53 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

#define MAX_SPELL 4

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_bookOfSpells[MAX_SPELL];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &other);
		~MateriaSource();
		MateriaSource	&operator=(const MateriaSource &other);

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);

		void showBook() const;
};

#endif
