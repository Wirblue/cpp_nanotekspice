//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// ComponentTrue.cpp
//

#include "ComponentTrue.hpp"
#include "../../pin/PinInput.hpp"

nts::ComponentTrue::ComponentTrue(std::string name):
	AComponent(name, 1)
{
	_pin.push_back(new PinInput("", TRUE));
}

nts::ComponentTrue::~ComponentTrue()
{
}

void nts::ComponentTrue::execute()
{
}

nts::IComponent *nts::ComponentTrue::clone(std::string name) const
{
	return new ComponentTrue(name);
}
