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

void nts::ComponentNAND::execute()
{
	nts::Tristate a = _pin[0]->getStatus();
	nts::Tristate b = _pin[1]->getStatus();

	_pin[2]->setStatus(!(a & b));
}
