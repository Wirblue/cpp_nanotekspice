//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// ComponentXNOR.cpp
//

#include "ComponentXNOR.hpp"

nts::ComponentXNOR::ComponentXNOR(std::string name) : ComponentXOR(name)
{

}

nts::ComponentXNOR::~ComponentXNOR()
{

}

void nts::ComponentXNOR::execute()
{
	nts::Tristate a = _pin[0]->getStatus();
	nts::Tristate b = _pin[1]->getStatus();

	_pin[2]->setStatus(!(a ^ b));
}