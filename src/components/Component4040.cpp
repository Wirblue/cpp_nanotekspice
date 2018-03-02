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

nts::Component4040::~Component4040()
{
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
	if (_alreayDone)
		return;
	AComponent::execute();
	if (_pin[10]->compute() == nts::TRUE)
		_av = 0;
	else if (_pin[9]->compute() == nts::TRUE && _lastState != nts::TRUE)
		_av++;
	_lastState = _pin[9]->getStatus();
	printPinBinary();
}
