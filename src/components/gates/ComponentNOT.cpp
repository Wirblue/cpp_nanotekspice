//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// ComponentNOT.cpp
//

#include "ComponentNOT.hpp"

nts::ComponentNOT::ComponentNOT(std::string name):
	AComponent(name, 2)
{
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentOut(this));
}

nts::ComponentNOT::~ComponentNOT()
{
}

void nts::ComponentNOT::execute()
{
	nts::Tristate intput = _pin[0]->getStatus();

	_pin[1]->setStatus(!intput);
}
