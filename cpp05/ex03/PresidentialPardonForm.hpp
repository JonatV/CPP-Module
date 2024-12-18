#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public Form
{
	private:
		static const int	_executionGrade = 5;
		static const int	_signedGrade = 25;
		const std::string	_target;
	protected:
		void				executeAction() const;
	public:
	// Constructor
		PresidentialPardonForm();

	// Parameterized constructor
		PresidentialPardonForm(std::string);

	// Copy constructor
		PresidentialPardonForm(const PresidentialPardonForm &);
		
	// Destructor
		~PresidentialPardonForm();
		
	// Overloads
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &);
		
	// Member functions
	// Getters
		std::string	getTarget() const;
	// Setters
		
};

#endif