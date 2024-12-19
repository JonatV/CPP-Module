/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:51:20 by jveirman          #+#    #+#             */
/*   Updated: 2024/12/19 16:51:21 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"
#include <fstream>
#include <iostream>

Sed::Sed(const std::string to_replace, const std::string new_edit, const std::string file_name)
	: to_replace(to_replace), new_edit(new_edit), file_name(file_name) {
	std::cout << "\e[2mConstruct SED\e[0m\n";
}

Sed::~Sed() {
	std::cout << "\e[2mDestroy SED\e[0m\n";
}

bool Sed::startReplacement() {
	if (!checkStrings() || !checkFile())
		return (false);
	std::string output_text = processInfile();
	std::string new_file_name = createFileName();
	if (!writeOutfile(output_text, new_file_name))
		return (false);
	return true;
}

bool Sed::checkStrings() {
	if (to_replace.empty() || new_edit.empty())
		return (std::cerr << "Error: empty strings\n", false);
	return (true);
}

bool Sed::checkFile() {
	if (file_name.empty())
		return (std::cerr << "Error: empty file name\n", false);
	if (file_name.find(".replace") != std::string::npos)
		return (std::cerr << "Error: file name already contains .replace\n", false);
	return (true);
}

std::string Sed::processInfile() {
	std::ifstream infile(file_name.c_str());
	if (!infile.is_open())
		return (std::cerr << "Error: file not found\n", "");
	std::string line, output_text;
	while(getline(infile, line)) {
		line = findAndReplace(line);
		output_text.append(line);
		output_text.append("\n");
	}
	infile.close();
	return (output_text);
}

std::string Sed::findAndReplace(const std::string &line) {
	std::string new_line = line;
	std::string::size_type pos;

	pos = new_line.find(to_replace);
	while(pos != std::string::npos)
	{	
		new_line.erase(pos, to_replace.length());
		new_line.insert(pos, new_edit);
		pos = new_line.find(to_replace, pos + new_edit.length());
	}
	return (new_line);
}

std::string Sed::createFileName() {
	std::string file_name = this->file_name;
	
	file_name += ".replace";
	return (file_name);
}

bool Sed::writeOutfile(const std::string &output_text, const std::string &new_file_name) {
	std::ofstream outfile(new_file_name.c_str());
	if (!outfile.is_open())
		return (std::cerr << "Error: can't create the outfile\n", false);
	outfile << output_text;
	outfile.close();
	return (true);
}
