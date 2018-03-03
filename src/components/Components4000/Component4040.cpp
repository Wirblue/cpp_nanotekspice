//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// Component4040.cpp
//

#include <iostream>
#include "Component4040.hpp"

const std::vector<size_t> pinOrder = {9, 7, 6, 5, 3, 2, 4, 13, 12, 14, 15, 1};

nts::Component4040::Component4040(std::string name):
	AComponent(name, 16)
{
	_pin.push_back(new PinComponentOut(this));
	_pin.push_back(new PinComponentOut(this));
	_pin.push_back(new PinComponentOut(this));
	_pin.push_back(new PinComponentOut(this));
	_pin.push_back(new PinComponentOut(this));
	_pin.push_back(new PinComponentOut(this));
	_pin.push_back(new PinComponentOut(this));
	_pin.push_back(new PinComponentOut(this));
	_pin.push_back(new PinComponentOut(this));
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentOut(this));
	_pin.push_back(new PinComponentOut(this));
	_pin.push_back(new PinComponentOut(this));
	_pin.push_back(new PinComponentOut(this));
	_pin.push_back(new PinComponentOut(this));
}

nts::IComponent *nts::Component4040::clone(std::string name) const
{
	return new Component4040(name);
}

void nts::Component4040::printPinBinary()
{
	for (size_t i = 0; i < pinOrder.size(); i++) {
		if ((_av & (1 << i)))
			_pin[pinOrder[i] - 1]->setStatus(nts::TRUE);
		else
			_pin[pinOrder[i] - 1]->setStatus(nts::FALSE);
	}
}

void nts::Component4040::execute()
{
	if (!tryExecution())
		return;
	if (_pin[10]->getStatus() == nts::TRUE)
		_av = 0;
	else if (_pin[9]->compute() == nts::FALSE && _lastState == nts::TRUE)
		_av++;
	_av %= 4096;
	printPinBinary();
	_lastState = _pin[9]->getStatus();
}
