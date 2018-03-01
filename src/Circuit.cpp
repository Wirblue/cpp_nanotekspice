//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// Circuit.cpp
//

#include <fstream>
#include <iostream>
#include "Circuit.hpp"
#include "components/Component4Gate.hpp"

nts::Circuit::Circuit()
{
}

nts::Circuit::~Circuit()
{
}

bool nts::Circuit::alreadyExist(std::string name)
{

	return (_output.find(name.c_str()) != _output.end()
		|| _input.find(name.c_str()) != _input.end()
		|| _component.find(name.c_str()) != _component.end());
}

bool nts::Circuit::addOutput(std::string name)
{
	PinOutput *newOutput = new PinOutput(name);

	//printf("ADD OUTPUT %10s %p\n", name.c_str(), newOutput);
	if (alreadyExist(name)) {
		std::cerr << "output '" << name << "' already exist" << std::endl;
		return false;
	}
	_output.insert(std::make_pair(name, newOutput));
	return true;
}

bool nts::Circuit::addInput(std::string name)
{
	PinInput *newInput = new PinInput(name);

	//printf("ADD INPUT  %10s %p\n", name.c_str(), newInput);
	if (alreadyExist(name)) {
		std::cerr << "input '" << name << "' already exist" << std::endl;
		return false;
	}
	_input.insert(std::make_pair(name, newInput));
	return true;
}

bool nts::Circuit::addComponent(std::string name, std::string type)
{
	IComponent *newComponent;

	if (componentList.find(type.c_str()) == componentList.end()) {
		std::cerr << "'" << type << "' isn't a component" << std::endl;
		return false;
	}
	newComponent = componentList[type]->clone(name);
	if (alreadyExist(name)) {
		std::cerr << "component '" << name << "' already exist" << std::endl;
		return false;
	}
	_component.insert(std::make_pair(name, newComponent));
	return true;
}

bool nts::Circuit::parseChipsets(std::string a, std::string b)
{
	bool status;

	if (b == "input")
		status = addInput(a);
	else if (b == "output")
		status = addOutput(a);
	else
		status = addComponent(a, b);
	return status;
}


nts::IPin *nts::Circuit::findPin(std::string name, size_t pos)
{
	if (_input.find(name.c_str()) != _input.end()) {
		return _input[name];
	} else if (_output.find(name.c_str()) != _output.end()) {
		return _output[name];
	} else if (_component.find(name.c_str()) != _component.end()) {
		return _component[name]->getPin(pos);
	}
	return (nullptr);
}

bool nts::Circuit::linkComponent(std::string name1, size_t pin1,
	std::string name2, size_t pin2)
{
	nts::IPin *a = findPin(name1, pin1 - 1);
	nts::IPin *b = findPin(name2, pin2 - 1);

	if (a == nullptr || b == nullptr)
		return false;
	return a->link(b, false);
}

bool nts::Circuit::parseLinks(std::string a, std::string b)
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
	return linkComponent(name1, pin1, name2, pin2);
}


bool nts::Circuit::readDefault(std::ifstream &file, nts::Circuit::readType &status)
{
	std::string line;

	if (!getline(file, line))
		return false;
	if (line == ".chipsets:")
		status = CHIPSETS;
	return true;
}

bool nts::Circuit::readChiptsets(std::ifstream &file, nts::Circuit::readType &status)
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

bool nts::Circuit::readLinks(std::ifstream &file, nts::Circuit::readType &status)
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

bool nts::Circuit::createCircuitFromFile(std::string fname)
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

void nts::Circuit::dumpComponent()
{
	for (auto const& p : _input) {
		p.second->setStatus(FALSE);
	}
	for (auto const& p : _output) {
		p.second->dump();
	}
	for (auto const& p : _component)
	{
		p.second->dump();
	}
}
