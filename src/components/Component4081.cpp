//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// Component4081.cpp
//

#include "Component4081.hpp"

nts::Component4081::Component4081(std::string name):
	AComponent(name, 14)
{
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentOut(this));
	_pin.push_back(new PinComponentOut(this));
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentOut(this));
	_pin.push_back(new PinComponentOut(this));
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentOut(this));

	_andGates[0].getPin(0)->link(_pin[0], true);
	_andGates[0].getPin(1)->link(_pin[1], true);
	_pin[2]->link(_andGates[0].getPin(2), true);
	_andGates[1].getPin(0)->link(_pin[4], true);
	_andGates[1].getPin(1)->link(_pin[5], true);
	_pin[3]->link(_andGates[1].getPin(2), true);
	_andGates[2].getPin(0)->link(_pin[7], true);
	_andGates[2].getPin(1)->link(_pin[8], true);
	_pin[9]->link(_andGates[2].getPin(2), true);
	_andGates[3].getPin(0)->link(_pin[11], true);
	_andGates[3].getPin(1)->link(_pin[12], true);
	_pin[10]->link(_andGates[3].getPin(2), true);
}

nts::Component4081::~Component4081()
{

}

void nts::Component4081::execute()
{
	for (int i = 0; i < 0; i++)
		_andGates[i].execute();
}
