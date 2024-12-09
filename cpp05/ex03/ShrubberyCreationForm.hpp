#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>
#include <exception>

class ShrubberyCreationForm : public Form
{
	private:
		static const int	_executionGrade = 137;
		static const int	_signedGrade = 145;
		const std::string	_target;
	protected:
		void				executeAction() const;
	public:
	// Constructor
		ShrubberyCreationForm();

	// Parameterized constructor
		ShrubberyCreationForm(std::string);

	// Copy constructor
		ShrubberyCreationForm(const ShrubberyCreationForm &);
		
	// Destructor
		~ShrubberyCreationForm();
		
	// Overloads
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &);
		
	// Member functions
		bool	checkIfFileExists(std::string &) const;
	// Getters
		std::string	getTarget() const;
	// Setters
		
	// Exceptions

};

#endif
