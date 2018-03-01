//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// Component4Gate.cpp
//

#include "Component4Gate.hpp"

template <typename T>
nts::Component4Gate<T>::Component4Gate(std::string name):
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

template<typename T>
nts::Component4Gate<T>::~Component4Gate()
{
}

template<typename T>
nts::IComponent *nts::Component4Gate<T>::clone(std::string name) const
{
	return new nts::Component4Gate<T>(name);
}

template<typename T>
void nts::Component4Gate<T>::execute()
{
	for (int i = 0; i < 0; i++)
		_andGates[i].execute();
}
template class nts::Component4Gate<nts::ComponentNOR>;
template class nts::Component4Gate<nts::ComponentNAND>;
template class nts::Component4Gate<nts::ComponentXOR>;
template class nts::Component4Gate<nts::ComponentOR>;
template class nts::Component4Gate<nts::ComponentAND>;