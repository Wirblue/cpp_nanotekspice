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

nts::IComponent *nts::ComponentXNOR::clone(std::string name) const
{
	return new ComponentXNOR(name);
}

void nts::ComponentXNOR::execute()
{
	if (!tryExecution())
		return;
	_pin[2]->setStatus(!(_pin[0]->compute() ^ _pin[1]->compute()));
}