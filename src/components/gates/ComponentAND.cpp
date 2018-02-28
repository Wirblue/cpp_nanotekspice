//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// ComponentAND.cpp
//

#include <iostream>
#include "ComponentAND.hpp"

nts::ComponentAND::ComponentAND(std::string name) :
	AComponent(name, 3)
{
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentOut(this));
}

nts::ComponentAND::~ComponentAND()
{
}

void nts::ComponentAND::execute()
{
	nts::Tristate a = _pin[0]->getStatus();
	nts::Tristate b = _pin[1]->getStatus();

	_pin[2]->setStatus(a & b);
}