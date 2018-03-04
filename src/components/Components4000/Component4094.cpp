//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// Component4094.cpp
//

#include <iostream>
#include "Component4094.hpp"

const std::vector<int> pinOrder = {4, 5, 6, 7, 9, 14, 13, 12, 11};

nts::Component4094::Component4094(std::string name):
	AComponent(name, 16)
{
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentOut(this));
	_pin.push_back(new PinComponentOut(this));
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
	_pin.push_back(new PinComponentOut(this));
}

nts::IComponent *nts::Component4094::clone(std::string name) const
{
	return new Component4094(name);
}

void nts::Component4094::setAllQPin(nts::Tristate a)
{
	for (size_t i = 0; i < pinOrder.size(); i++)
		_pin[pinOrder[i] - 1]->setStatus(a);
}

void nts::Component4094::execute()
{
	if (!tryExecution())
		return;
	_clock.move(_pin[2]->compute());
	if (_clock.getStatus() == nts::ClockManager::MOVE_UP) {
		if (!_pin[14]->compute())
			setAllQPin(UNDEFINED);
		else if (_pin[0]->compute() == nts::TRUE)
			setAllQPin(_pin[1]->compute());
		_pin[8]->setStatus(_pin[11]->getStatus());
	} else if (_clock.getStatus() == nts::ClockManager::MOVE_DOWN) {
		if (!_pin[0]->compute()
			|| (_pin[1]->compute() && _pin[0]->compute()))
			_pin[9]->setStatus(_pin[11]->getStatus());
	} else
		std::cout << "NTM LA SALE GARCE" << std::endl;
}
