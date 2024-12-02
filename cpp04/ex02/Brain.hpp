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
