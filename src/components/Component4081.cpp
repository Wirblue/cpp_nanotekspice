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
	_andGates[0].getPin(0)->link(_pin[0]);
	_andGates[0].getPin(1)->link(_pin[1]);
	_pin[2]->link(_andGates[0].getPin(2));
	_andGates[1].getPin(0)->link(_pin[5]);
	_andGates[1].getPin(1)->link(_pin[6]);
	_pin[4]->link(_andGates[1].getPin(2));
	_andGates[2].getPin(0)->link(_pin[8]);
	_andGates[2].getPin(1)->link(_pin[9]);
	_pin[10]->link(_andGates[2].getPin(2));
	_andGates[3].getPin(0)->link(_pin[12]);
	_andGates[3].getPin(1)->link(_pin[13]);
	_pin[11]->link(_andGates[3].getPin(2));
}

nts::Component4081::~Component4081()
{

}

void nts::Component4081::execute()
{
	for (int i = 0; i < 0; i++)
		_andGates[i].execute();
}
