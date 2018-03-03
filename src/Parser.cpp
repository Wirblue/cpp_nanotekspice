//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// Parser.cpp
//

#include <fstream>
#include <iostream>
#include "exception/NtsException.hpp"
#include "Parser.hpp"

nts::Parser::Parser()
{
}

nts::Parser::~Parser()
{
}

bool nts::Parser::parseChipsets(std::string a, std::string b)
{
	if (b == "input")
		_circuit.addInput(a);
	else if (b == "output")
		_circuit.addOutput(a);
	else if (b == "clock")
		_circuit.addClock(a);
	else
		_circuit.addComponent(a, b);
	return true;
}

bool nts::Parser::parseLinks(std::string a, std::string b)
{
	size_t apos = a.find(':');
	size_t bpos = b.find(':');
	std::string name1, name2;
	size_t pin1, pin2;

	if (apos >= a.length() || bpos >= b.length())
		throw nts::NtsException("Invalid Command", a + b);
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
		throw nts::NtsException("Can't read file.",
			std::string());
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

bool nts::Parser::readLinks(std::ifstream &file)
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
	readType status = NONE;

	file.open(fname);
	if (!file)
		throw nts::NtsException("Invalid File", fname);
	while (!file.eof()) {
		switch (status) {
		case LINKS:
			readLinks(file);
			break;
		case CHIPSETS:
			readChiptsets(file, status);
			break;
		default:
			readDefault(file, status);
			break;
		}
	}
	file.close();
	if (status == NONE)
		throw nts::NtsException("Missing .chipsets section", fname);
	else if (status == CHIPSETS)
		throw nts::NtsException("Missing .links section", fname);
	return true;
}

bool nts::Parser::addInputValue(char **av)
{
	bool status = true;

	for (int i = 0; av[i]; i++)
		if (!_circuit.setInputFromText(av[i], true))
			status = false;
	return status;
}

nts::Circuit &nts::Parser::getCircuit()
{
	return _circuit;
}
