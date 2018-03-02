//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// Component4013.cpp
//

#include <iostream>
#include "Component4013.hpp"

nts::Component4013::Component4013(std::string name):
	AComponent(name, 14)
{
	_pin.push_back(new PinComponentOut(this));
	_pin.push_back(new PinComponentOut(this));
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentOut(this));
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentOut(this));
	_pin.push_back(new PinComponentOut(this));
	_pin.push_back(new PinComponentOut(this));
	_ffGate[0].linkPin({_pin[0], _pin[1], _pin[2], _pin[3], _pin[4], _pin[5]});
	_ffGate[1].linkPin({_pin[12], _pin[11], _pin[10], _pin[9], _pin[8], _pin[7]});
}

nts::Component4013::~Component4013()
{
}

nts::IComponent *nts::Component4013::clone(std::string name) const
{
	return new Component4013(name);
}

void nts::Component4013::execute()
{
	//if (_alreayDone)
	//	return;
	//for (auto gate : _ffGate)
	_ffGate->execute();
	AComponent::execute();
}

void nts::Component4013::reset()
{
	for (auto gate : _ffGate)
		gate.reset();
	AComponent::reset();
}
