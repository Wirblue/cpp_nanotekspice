//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// ComponentNAND.cpp
//

#include "ComponentNAND.hpp"

nts::ComponentNAND::ComponentNAND(std::string name):
	ComponentAND(name)
{
}

nts::ComponentNAND::~ComponentNAND()
{
}

nts::IComponent *nts::ComponentNAND::clone(std::string name) const
{
	return new ComponentNAND(name);
}

void nts::ComponentNAND::execute()
{
	nts::Tristate a = _pin[0]->getStatus();
	nts::Tristate b = _pin[1]->getStatus();

	_pin[2]->setStatus(!(a & b));
}

