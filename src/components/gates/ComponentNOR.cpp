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
	nts::Tristate a = _pin[0]->getStatus();
	nts::Tristate b = _pin[1]->getStatus();

	_pin[2]->setStatus(!(a | b));
}
