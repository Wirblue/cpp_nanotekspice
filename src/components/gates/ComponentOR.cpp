//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// ComponentOR.cpp
//

#include "ComponentOR.hpp"

nts::ComponentOR::ComponentOR(std::string name) :
	AComponent(name, 3)
{
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentOut(this));}

nts::ComponentOR::~ComponentOR()
{

}

nts::IComponent *nts::ComponentOR::clone(std::string name) const
{
	return new ComponentOR(name);
}

void nts::ComponentOR::execute()
{
	nts::Tristate a = _pin[0]->getStatus();
	nts::Tristate b = _pin[1]->getStatus();

	_pin[2]->setStatus(a | b);
}
