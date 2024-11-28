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
		std::string processInfile();
		std::string findAndReplace(const std::string &line);
		std::string createFileName();
		bool writeOutfile(const std::string &output_text, const std::string &new_file_name);
		
	public:
		Sed(const std::string to_replace, const std::string new_edit, const std::string file_name);
		~Sed();
		bool startReplacement();
};

#endif
