//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// Component4503.cpp
//

#include "Component4503.hpp"

const std::vector<int> inOrder = {2, 4, 6, 10, 12, 14};
const std::vector<int> outOrder = {3, 5, 7, 9, 11, 13};

nts::Component4503::Component4503(std::string name):
	AComponent(name, 16)
{
	_pin.push_back(new PinComponentIn(this));
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
	_pin.push_back(new PinComponentIn(this));
}

nts::IComponent *nts::Component4503::clone(std::string name) const
{
	return new Component4503(name);
}

void nts::Component4503::execute()
{
	if (!tryExecution())
		return;
	for (size_t i = 0; i < inOrder.size(); i++)
		_pin[outOrder[i] - 1]->setStatus(_pin[inOrder[i] - 1]->compute());
	if (_pin[0]->compute() == nts::TRUE)
		for (size_t i = 0; i < 4; i++)
			_pin[outOrder[i] - 1]->setStatus(UNDEFINED);
	if (_pin[15]->compute() == nts::TRUE)
		for (size_t i = 4; i < 6; i++)
			_pin[outOrder[i] - 1]->setStatus(UNDEFINED);
}
