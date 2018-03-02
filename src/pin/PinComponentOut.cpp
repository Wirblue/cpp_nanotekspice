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

nts::PinType nts::PinComponentOut::getType() const
{
	return OUT;
}

nts::Tristate nts::PinComponentOut::compute()
{
	if (_link) {
		_link->compute();
		_status = _link->getStatus();
	} else if (_component)
		_component->execute();
	else
		_status = nts::UNDEFINED;
	return _status;
}
