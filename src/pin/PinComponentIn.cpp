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

nts::PinType nts::PinComponentIn::getType() const
{
	return IN;
}

nts::Tristate nts::PinComponentIn::compute()
{
	if (!_link)
		_status = nts::UNDEFINED;
	else {
		_link->compute();
		_status = _link->getStatus();
	}
	return _status;
}
