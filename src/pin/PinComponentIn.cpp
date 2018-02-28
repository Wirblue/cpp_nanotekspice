//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// PinComponentIn.cpp
//

#include "PinComponentIn.hpp"

nts::PinComponentIn::PinComponentIn(nts::IComponent *component):
	APinComponent(component)
{

}

nts::PinComponentIn::~PinComponentIn()
{
}

nts::Tristate nts::PinComponentIn::getStatus() const
{
	if (!_link)
		return UNDEFINED;
	return _link->getStatus();
}

nts::PinType nts::PinComponentIn::getType() const
{
	return IN;
}