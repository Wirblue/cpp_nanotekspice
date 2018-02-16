//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// APin.cpp
//

#include <iostream>
#include "APin.hpp"

nts::APin::APin()
{
	_link = nullptr;
}

nts::APin::~APin()
{
	if (_link)
		_link->link(nullptr);
}

void nts::APin::dump()
{
	std::cout << compute() << std::endl;
}

bool nts::APin::link(IPin *pin)
{
	if (_link != nullptr || this->getType() == pin->getType())
		return false;
	_link = pin;
	return true;
}
