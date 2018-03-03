//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// ComponentFF.cpp
//

#include <iostream>
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

nts::IComponent *nts::ComponentFF::clone(std::string name) const
{
	return new ComponentFF(name);
}

void nts::ComponentFF::setOutput(nts::Tristate a, nts::Tristate b)
{
	_pin[0]->setStatus(a);
	_pin[1]->setStatus(b);
}

nts::Tristate nts::ComponentFF::haveChange()
{
	if (_pin[2]->getStatus() == _lastState)
		return UNDEFINED;
	return _pin[2]->getStatus();
}

void nts::ComponentFF::execute()
{
	if (!tryExecution())
		return;
	nts::Tristate set = _pin[3]->compute();
	nts::Tristate data = _pin[4]->compute();
	nts::Tristate reset = _pin[5]->compute();

	if (!reset && !set) {
		if (haveChange() == TRUE)
			data ? setOutput(FALSE, TRUE) : setOutput(TRUE, FALSE);
		else if (haveChange() == FALSE)
			data ? setOutput(_memory, !_memory) : setOutput(!_memory, _memory);
		else
			setOutput(UNDEFINED, UNDEFINED);
	} else if (!reset && set == TRUE) {
		setOutput(FALSE, TRUE);
		_memory = TRUE;
	} else if (reset == TRUE && !set) {
		setOutput(TRUE, FALSE);
		_memory = FALSE;
	} else if (reset == TRUE && set == TRUE)
		setOutput(TRUE, TRUE);
	else
		setOutput(UNDEFINED, UNDEFINED);

}
