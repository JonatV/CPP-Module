#ifndef SED_HPP
#define SED_HPP
#include <iostream>

class Sed{
	private:
		const std::string to_replace;
		const std::string new_edit;
		std::string file_name;

		bool checkStrings();
		bool checkFile();
	public:
		Sed(const std::string to_replace, const std::string new_edit, const std::string file_name);
		~Sed();
		bool startReplacement();
};

#endif
