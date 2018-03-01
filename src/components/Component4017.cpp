//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// Component4017.cpp
//

#include <iostream>
#include "Component4017.hpp"

const std::vector<int> pinOrder = {3, 2, 4, 7, 10, 1, 5, 6, 9, 11};

nts::Component4017::Component4017(std::string name):
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
	_pin.push_back(new PinComponentOut(this));
	_pin.push_back(new PinComponentOut(this));
	_pin.push_back(new PinComponentOut(this));
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentOut(this));
}

nts::Component4017::~Component4017()
{
}

nts::IComponent *nts::Component4017::clone(std::string name) const
{
	return new Component4017(name);
}

void nts::Component4017::openOnlyOne(size_t open)
{
	for (size_t i = 0; i < pinOrder.size(); i++) {
		if (i == open)
			_pin[pinOrder[i] - 1]->setStatus(nts::TRUE);
		else
			_pin[pinOrder[i] - 1]->setStatus(nts::FALSE);
	}
}

void nts::Component4017::execute()
{
	if (_alreayDone)
		return;
	//std::cout << std::endl << "14: " << _pin[14]->getStatus() << std::endl;
	//std::cout << "13: " << _pin[13]->getStatus() << _lastState << std::endl;
	//std::cout << "12: " << _pin[12]->getStatus() << std::endl << std::endl;
	if (_pin[14]->getStatus() == nts::TRUE)
		_av = 0;
	else if (_pin[13]->getStatus() == nts::TRUE && _lastState != nts::TRUE
		&& _pin[12]->getStatus() != nts::TRUE)
		_av++;
	_av = _av % pinOrder.size();
	_lastState = _pin[13]->getStatus();
	openOnlyOne(_av);
	_pin[11]->setStatus(_av >= pinOrder.size() / 2 ? nts::FALSE : nts::TRUE);
	AComponent::execute();
}