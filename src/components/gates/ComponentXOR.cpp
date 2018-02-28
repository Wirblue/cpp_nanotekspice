//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// ComponentXOR.cpp
//

#include "ComponentXOR.hpp"

nts::ComponentXOR::ComponentXOR(std::string name):
	AComponent(name, 3)
{
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentOut(this));
}

nts::ComponentXOR::~ComponentXOR()
{

}

void nts::ComponentXOR::execute()
{
	nts::Tristate a = _pin[0]->getStatus();
	nts::Tristate b = _pin[1]->getStatus();

	_pin[2]->setStatus(a ^ b);
}