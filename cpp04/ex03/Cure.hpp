#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
	private:

	public:
	// constructors
		Cure();
		Cure(const Cure &);
	
	// destructors
		~Cure();
	
	// overloaded operator
		Cure &operator=(const Cure &);

	// methods
		AMateria *clone() const override;
		void use(ICharacter &target) override;

	// getters

	// setters
};

#endif
