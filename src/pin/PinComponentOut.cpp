//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// PinCompOut.cpp
//

#include "PinComponentOut.hpp"

nts::PinComponentOut::PinComponentOut(nts::IComponent *gate):
	APinComponent(gate)
{

}

nts::PinComponentOut::~PinComponentOut()
{
}

nts::Tristate nts::PinComponentOut::compute()
{
	if (_lastCall == UNDEFINED)
		_lastCall = _gate->compute();
	return _lastCall;
}

nts::PinType nts::PinComponentOut::getType()
{
	return OUT;
}
