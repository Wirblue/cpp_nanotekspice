//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// ComponentXOR.cpp
//

#include "ComponentXOR.hpp"

nts::ComponentXOR::ComponentXOR(std::string name):
	AGate(name, 3)
{
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentOut(this));
}

nts::ComponentXOR::~ComponentXOR()
{
}

nts::IComponent *nts::ComponentXOR::clone(std::string name) const
{
	return new ComponentXOR(name);
}

void nts::ComponentXOR::execute()
{
	if (_alreayDone)
		return;
	_pin[2]->setStatus(_pin[0]->compute() ^ _pin[1]->compute());
}