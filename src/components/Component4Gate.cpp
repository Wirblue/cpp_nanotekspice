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
	_andGates[0].linkPin({_pin[0], _pin[1], _pin[2]});
	_andGates[1].linkPin({_pin[5], _pin[4], _pin[3]});
	_andGates[2].linkPin({_pin[7], _pin[8], _pin[9]});
	_andGates[3].linkPin({_pin[12], _pin[11], _pin[10]});
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
	if (!tryExecution())
		return;
	for (auto gate : _andGates)
		gate.execute();
}

template<typename T>
void nts::Component4Gate<T>::reset()
{
	for (auto gate : _andGates)
		gate.reset();
	_alreayDone = false;
}

template class nts::Component4Gate<nts::ComponentNOR>;
template class nts::Component4Gate<nts::ComponentNAND>;
template class nts::Component4Gate<nts::ComponentXOR>;
template class nts::Component4Gate<nts::ComponentOR>;
template class nts::Component4Gate<nts::ComponentAND>;