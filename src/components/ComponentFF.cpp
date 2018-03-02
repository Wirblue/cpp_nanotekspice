//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// ComponentFF.cpp
//

#include <iostream>
#include "ComponentFF.hpp"

nts::ComponentFF::ComponentFF(std::string name):
	AGate(name, 6)
{
	_pin.push_back(new PinComponentOut(this));
	_pin.push_back(new PinComponentOut(this));
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentIn(this));
}

nts::ComponentFF::~ComponentFF()
{
}

nts::IComponent *nts::ComponentFF::clone(std::string name) const
{
	return new ComponentFF(name);
}

void nts::ComponentFF::execute()
{
	nts::Tristate a = _pin[5]->getStatus();
	nts::Tristate b = _pin[3]->getStatus();

	_pin[0]->setStatus(a);
	_pin[1]->setStatus(b);
	AComponent::execute();
}
