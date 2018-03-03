//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// Component4514.cpp
//

#include "Component4514.hpp"

const std::vector<int> pinOrder = {11, 9, 10, 8, 7, 6, 5, 4, 18, 17, 20, 19, 14, 13, 16, 15};

nts::Component4514::Component4514(std::string name):
	AComponent(name, 24)
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

nts::IComponent *nts::Component4514::clone(std::string name) const
{
	return new Component4514(name);
}

void nts::Component4514::output(int val)
{
	for (int i = 0; i < (int)pinOrder.size(); i++)
		_pin[pinOrder[i] - 1]->setStatus((i == val) ? nts::TRUE : nts::FALSE);
}

void nts::Component4514::execute()
{
	if (_pin[0]->compute() == nts::TRUE)
		_value = (_pin[1]->compute() == nts::TRUE ? 1 : 0)
			+ (_pin[2]->compute() == nts::TRUE ? 1 : 0) * 2
			+ (_pin[20]->compute() == nts::TRUE ? 1 : 0) * 4
			+ (_pin[21]->compute() == nts::TRUE ? 1 : 0) * 8;
	if (_pin[22]->compute() == nts::TRUE)
		output(-1);
	else
		output(_value);
}
