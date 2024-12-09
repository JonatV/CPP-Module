#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
class Form;

class Intern
{
	private:
		
	public:
	// Constructor
		Intern();

	// Parameterized constructor
		
	// Copy constructor
		Intern(const Intern &);
		
	// Destructor
		~Intern();
		
	// Overloads
		Intern	&operator=(const Intern &);
		
	// Member functions
		Form *makeForm(std::string form_type, std::string target);
	// Getters
		
	// Setters
		
};

#endif
