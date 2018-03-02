//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// APinExt.cpp
//

#include "APinExt.hpp"

nts::APinExt::APinExt(std::string name):
	APin(), _name(name)
{
}


void nts::APinExt::setName(std::string name)
{
	_name = name;
}

std::string nts::APinExt::getName()
{
	return _name;
}


nts::PinType nts::APinExt::getLoc() const
{
	return OUT;
}
