//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// PinCompOut.cpp
//

#include "PinComponentOut.hpp"

nts::PinComponentOut::PinComponentOut(nts::IComponent *component):
	APinComponent(component)
{
}

nts::PinComponentOut::~PinComponentOut()
{
}

nts::Tristate nts::PinComponentOut::getStatus() const
{
	if (_component)
		_component->execute();
	if (_link)
		return _link->getStatus();
	return _status;
}

nts::PinType nts::PinComponentOut::getType() const
{
	return OUT;
}