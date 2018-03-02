//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// Component4069.cpp
//

#include "Component4069.hpp"

nts::Component4069::Component4069(std::string name):
	AComponent(name, 14)
{
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentOut(this));
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentOut(this));
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentOut(this));
	_pin.push_back(new PinComponentOut(this));
	_pin.push_back(new PinComponentOut(this));
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentOut(this));
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentOut(this));
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentOut(this));
	_notGate[0].linkPin({_pin[0], _pin[1]});
	_notGate[1].linkPin({_pin[2], _pin[3]});
	_notGate[2].linkPin({_pin[4], _pin[5]});
	_notGate[3].linkPin({_pin[8], _pin[7]});
	_notGate[4].linkPin({_pin[10], _pin[9]});
	_notGate[5].linkPin({_pin[12], _pin[11]});
}

nts::IComponent *nts::Component4069::clone(std::string name) const
{
	return new Component4069(name);
}

void nts::Component4069::execute()
{
	for (auto gate : _notGate)
		gate.execute();
}

void nts::Component4069::reset()
{
	for (int i = 0; i < 6; i++)
		_notGate[i].reset();
	_alreayDone = false;
}
