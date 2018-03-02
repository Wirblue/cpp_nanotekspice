//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// ComponentAND.cpp
//

#include <iostream>
#include "ComponentAND.hpp"

nts::ComponentAND::ComponentAND(std::string name) :
	AGate(name, 3)
{
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentOut(this));
}

nts::ComponentAND::~ComponentAND()
{
}

nts::IComponent *nts::ComponentAND::clone(std::string name) const
{
	return new ComponentAND(name);
}

void nts::ComponentAND::execute()
{
	if (_alreayDone)
		return;
	_pin[2]->setStatus(_pin[0]->compute() & _pin[1]->compute());
}
