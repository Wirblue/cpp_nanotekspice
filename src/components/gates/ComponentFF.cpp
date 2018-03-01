//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// ComponentFF.cpp
//

#include "ComponentFF.hpp"

nts::ComponentFF::ComponentFF(std::string name):
	AGate(name, 6)
{
	_pin.push_back(new PinComponentOut(this));
	_pin.push_back(new PinComponentOut(this));
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentIn(this));
	_pin.push_back(new PinComponentIn(this));
}

nts::ComponentFF::~ComponentFF()
{

}

nts::IComponent *nts::ComponentFF::clone(std::string name) const
{
	return new ComponentFF(name);
}

void nts::ComponentFF::execute()
{
	if (_alreayDone)
		return;
	nts::Tristate a = _pin[5]->getStatus();
	nts::Tristate b = _pin[3]->getStatus();

	if (a == nts::TRUE && b != nts::TRUE)
		memory = FALSE;
	else if (a != nts::TRUE && b == nts::TRUE)
		memory = nts::TRUE;

	if (a == nts::TRUE || memory == nts::FALSE)
		_pin[0]->setStatus(nts::TRUE);
	else
		_pin[0]->setStatus(a);
	if (b == nts::TRUE || memory == nts::TRUE)
		_pin[1]->setStatus(nts::TRUE);
	else
		_pin[1]->setStatus(b);
}
