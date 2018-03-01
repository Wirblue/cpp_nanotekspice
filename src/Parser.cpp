//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// Parser.cpp
//

#include <fstream>
#include <iostream>
#include "Parser.hpp"

nts::Parser::Parser()
{
}

nts::Parser::~Parser()
{
}

bool nts::Parser::parseChipsets(std::string a, std::string b)
{
	bool status;

	if (b == "input")
		status = _circuit.addInput(a);
	else if (b == "output")
		status = _circuit.addOutput(a);
	else if (b == "clock")
		status = _circuit.addClock(a);
	else
		status = _circuit.addComponent(a, b);
	return status;
}

bool nts::Parser::parseLinks(std::string a, std::string b)
{
	size_t apos = a.find(':');
	size_t bpos = b.find(':');
	std::string name1, name2;
	size_t pin1, pin2;

	if (apos >= a.length() || bpos >= b.length())
		return false;
	name1 = a.substr(0, apos);
	name2 = b.substr(0, bpos);
	pin1 = (size_t)std::stol(a.substr(apos + 1));
	pin2 = (size_t)std::stol(b.substr(bpos + 1));
	return _circuit.linkComponent(name1, pin1, name2, pin2);
}


bool nts::Parser::readDefault(std::ifstream &file, nts::Parser::readType &status)
{
	std::string line;

	if (!getline(file, line))
		return false;
	if (line == ".chipsets:")
		status = CHIPSETS;
	return true;
}

bool nts::Parser::readChiptsets(std::ifstream &file, nts::Parser::readType &status)
{
	std::string a, b;

	file >> a;
	if (a == ".links:") {
		status = LINKS;
		return true;
	}
	else if (a.c_str()[0] != '#' && !a.empty()) {
		file >> b;
		return parseChipsets(b, a);
	} else
		getline(file, a);
	return true;
}

bool nts::Parser::readLinks(std::ifstream &file, nts::Parser::readType &status)
{
	std::string a, b;

	file >> a;
	if (a.c_str()[0] != '#' && !a.empty()) {
		file >> b;
		return parseLinks(a, b);
	} else
		getline(file, a);
	return true;
}

bool nts::Parser::createCircuitFromFile(std::string fname)
{
	std::ifstream file;
	bool error;
	readType status = NONE;

	file.open(fname);
	if (!file)
		std::cerr << "Invalid File !" << std::endl;
	while (!file.eof()) {
		switch (status) {
		case LINKS:
			error = readLinks(file, status);
			break;
		case CHIPSETS:
			error = readChiptsets(file, status);
			break;
		default:
			error = readDefault(file, status);
			break;
		}
		if (!error) {
			file.close();
			return false;
		}
	}
	file.close();
	return true;
}

nts::Circuit &nts::Parser::getCircuit()
{
	return _circuit;
}
