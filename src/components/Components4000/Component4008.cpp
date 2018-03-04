//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// Component4008.cpp
//

#include "Component4008.hpp"

nts::Component4008::Component4008(std::string name):
	AComponent(name, 16)
{
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentOut(this));
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentOut(this));
	_pin.push_back(new PinComponentOut(this));
	_pin.push_back(new PinComponentOut(this));
	_pin.push_back(new PinComponentOut(this));
	_pin.push_back(new PinComponentOut(this));
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentOut(this));
}

nts::IComponent *nts::Component4008::clone(std::string name) const
{
	return new Component4008(name);
}

nts::Tristate nts::Component4008::sum(Tristate a, Tristate b,
	Tristate c, size_t output) const
{
	int tmp = (a ? 1 : 0) + (b ? 1 : 0) + (c ? 1 : 0);
	nts::Tristate sum = (tmp == 1 || tmp == 3) ? TRUE : FALSE;
	nts::Tristate cx = (tmp > 1) ? TRUE : FALSE;

	_pin[output]->setStatus(sum);
	return cx;
}

void nts::Component4008::execute()
{
	nts::Tristate c;

	if (!tryExecution())
		return;
	c = _pin[8]->compute();
	c = sum(_pin[6]->compute(), _pin[5]->compute(), c, 9);
	c = sum(_pin[4]->compute(), _pin[3]->compute(), c, 10);
	c = sum(_pin[2]->compute(), _pin[1]->compute(), c, 11);
	c = sum(_pin[0]->compute(), _pin[14]->compute(), c, 12);
	_pin[13]->setStatus(c);
}
