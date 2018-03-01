//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// ComponentFalse.cpp
//

#include "ComponentFalse.hpp"
#include "../../pin/PinInput.hpp"

nts::ComponentFalse::ComponentFalse(std::string name):
	AComponent(name, 1)
{
	_pin.push_back(new PinInput("", FALSE));
}

nts::ComponentFalse::~ComponentFalse()
{
}

void nts::ComponentFalse::execute()
{
}

nts::IComponent *nts::ComponentFalse::clone(std::string name) const
{
	return new ComponentFalse(name);
}
