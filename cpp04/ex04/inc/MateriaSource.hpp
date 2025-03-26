/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:04:54 by jveirman          #+#    #+#             */
/*   Updated: 2025/03/26 13:10:05 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

#define MAX_MATERIA 4

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_inventory[MAX_MATERIA];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &other);
		~MateriaSource();
		MateriaSource	&operator=(const MateriaSource &other);

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif
