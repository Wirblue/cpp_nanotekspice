//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// Circuit.cpp
//

#include <iostream>
#include "Circuit.hpp"

nts::Circuit::Circuit()
{
}

nts::Circuit::~Circuit()
{
}

bool nts::Circuit::addOutput(std::string name)
{
	PinOutput newOutput(name);

	if(_output.find(name.c_str()) != _output.end()) {
		std::cerr << "output '" << name << "' already exist" << std::endl;
		return false;
	}
	_output.insert(std::make_pair(name, &newOutput));
	return true;
}

bool nts::Circuit::addInput(std::string name)
{
	PinInput newInput(name);

	if(_input.find(name.c_str()) != _input.end()) {
		std::cerr << "input '" << name << "' already exist" << std::endl;
		return false;
	}
	_input.insert(std::make_pair(name, &newInput));
	return true;
}

bool nts::Circuit::addComponent(std::string name, std::string type)
{
	if(_component.find(name.c_str()) != _component.end()) {
		std::cerr << "component '" << name << "' already exist" << std::endl;
		return false;
	}
	return false;
}

bool nts::Circuit::parseChipsets(std::string name, std::string type)
{
	return false;
}

bool nts::Circuit::createCircuitFromFile(std::string file)
{
	return false;
}
