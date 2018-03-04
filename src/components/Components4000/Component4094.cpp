//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// Component4094.cpp
//

#include <iostream>
#include "Component4094.hpp"

const std::vector<int> pinOrder = {4, 5, 6, 7, 14, 13, 12, 11};

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

void nts::Component4094::setAllQPin()
{
	size_t k = 0;
	_nbTrue++;
	for (size_t i = 0; i < pinOrder.size(); i++) {
		if (i < _nbTrue) {
			_pin[pinOrder[i] - 1]->setStatus(TRUE);
			k++;
		}
		else
			_pin[pinOrder[i] - 1]->setStatus(FALSE);
	}
}

void nts::Component4094::setDefQPin(nts::Tristate a)
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
			setDefQPin(UNDEFINED);
		else if (_pin[0]->compute() == nts::TRUE)
			setAllQPin();
		_pin[8]->setStatus(_nbTrue > 7 ? TRUE : FALSE);
	} else if (_clock.getStatus() == nts::ClockManager::MOVE_DOWN) {
		if (!_pin[0]->compute() || (_pin[1]->compute() && _pin[0]->compute()))
			_pin[9]->setStatus(_nbTrue > 7 ? TRUE : FALSE);
	} else if (_clock.getStatus() == nts::ClockManager::UNDEFINED) {
		setDefQPin(nts::FALSE);
		_pin[8]->setStatus(nts::FALSE);
		_pin[9]->setStatus(nts::FALSE);
	}
}
