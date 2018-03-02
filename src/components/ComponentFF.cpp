//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// ComponentFF.cpp
//

#include <iostream>
#include "ComponentFF.hpp"

nts::ComponentFF::ComponentFF(std::string name):
	AGate(name, 6)
{
	_pin.push_back(new PinComponentOut(this));
	_pin.push_back(new PinComponentOut(this));
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentIn(this));
}

nts::IComponent *nts::ComponentFF::clone(std::string name) const
{
	return new ComponentFF(name);
}

void nts::ComponentFF::execute()
{
	if (!tryExecution())
		return;
	nts::Tristate a = _pin[5]->compute();
	nts::Tristate b = _pin[3]->compute();

	if (_pin[2]->compute() == nts::TRUE && _lastState != nts::TRUE)
		_reset = _pin[4]->compute();
	if (a == nts::TRUE && b != nts::TRUE)
		_memory = nts::TRUE;
	else if (a != nts::TRUE && b == nts::TRUE)
		_memory = nts::FALSE;
	if (a || _memory ^ _reset)
		_pin[0]->setStatus(nts::TRUE);
	else
		_pin[0]->setStatus(nts::FALSE);
	if (b || !(_memory ^ _reset))
		_pin[1]->setStatus(nts::TRUE);
	else
		_pin[1]->setStatus(nts::FALSE);
}
