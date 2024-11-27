#include "Sed.hpp"
#include <fstream>
#include <iostream>

Sed::Sed(const std::string to_replace, const std::string new_edit, const std::string file_name) : to_replace(to_replace), new_edit(new_edit), file_name(file_name) {
	std::cout << "Construct SED\n";
}

Sed::~Sed() {
	std::cout << "Destroy SED\n";
}

bool Sed::startReplacement() {
	std::cout << "Start replacement\n";
	if (!checkStrings() || !checkFile())
		return (false);
	std::cout << "Open the file\n";
	std::ifstream file(file_name.c_str());
	if (!file.is_open())
		return (std::cerr << "Error: file not found\n", false);
	std::cout << "Replace the strings\n";
	std::cout << "Write the new file\n";
	return true;
}

bool Sed::checkStrings() {
	std::cout << "Check the strings\n";
	if (to_replace.empty() || new_edit.empty())
		return (std::cerr << "Error: empty strings\n", false);
	return (true);
}

bool Sed::checkFile() {
	std::cout << "Check the file\n";
	if (file_name.empty())
		return (std::cerr << "Error: empty file name\n", false);
	if (file_name.find(".replace") != std::string::npos)
		return (std::cerr << "Error: file name already contains .replace\n", false);
	return (true);
}

