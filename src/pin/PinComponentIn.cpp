//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// PinComponentIn.cpp
//

#include "PinComponentIn.hpp"

nts::PinComponentIn::PinComponentIn(nts::IComponent *gate):
	APinComponent(gate)
{

}

nts::PinComponentIn::~PinComponentIn()
{
}

nts::Tristate nts::PinComponentIn::compute()
{
	if (!_link)
		return UNDEFINED;
	return _link->compute();
}

nts::PinType nts::PinComponentIn::getType()
{
	return IN;
}
