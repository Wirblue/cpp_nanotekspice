//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// ComponentNOR.cpp
//

#include "ComponentNOR.hpp"

nts::ComponentNOR::ComponentNOR(std::string name):
	ComponentOR(name)
{
}

nts::ComponentNOR::~ComponentNOR()
{

}

nts::IComponent *nts::ComponentNOR::clone(std::string name) const
{
	return new ComponentNOR(name);
}

void nts::ComponentNOR::execute()
{
	if (!tryExecution())
		return;
	_pin[2]->setStatus(!(_pin[0]->compute() | _pin[1]->compute()));
}
