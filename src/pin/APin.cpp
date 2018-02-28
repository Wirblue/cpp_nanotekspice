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

void nts::APin::dump() const
{
	std::cout << getStatus() << std::endl;
}

bool nts::APin::link(IPin *pin)
{
	_link = pin;
	return true;
}

void nts::APin::setStatus(Tristate status)
{
	_status = status;
}

nts::IPin *nts::APin::getLink() const
{
	return _link;
}
