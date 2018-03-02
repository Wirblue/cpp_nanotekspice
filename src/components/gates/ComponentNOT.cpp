//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// ComponentNOT.cpp
//

#include "ComponentNOT.hpp"

nts::ComponentNOT::ComponentNOT(std::string name):
	AGate(name, 2)
{
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentOut(this));
}

nts::IComponent *nts::ComponentNOT::clone(std::string name) const
{
	return new ComponentNOT(name);
}

void nts::ComponentNOT::execute()
{
	if (!tryExecution())
		return;
	_pin[1]->setStatus(!_pin[0]->compute());
}
