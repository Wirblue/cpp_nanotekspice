//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// PinOutput.cpp
//

#include "../components/IComponent.hpp"
#include "PinOutput.hpp"

nts::PinOutput::PinOutput(std::string name):
	APinExt(name)
{
}

nts::PinOutput::~PinOutput()
{
}

nts::PinType nts::PinOutput::getType() const
{
	return OUT;
}

nts::Tristate nts::PinOutput::compute()
{
	if (!_link)
		_status = nts::UNDEFINED;
	else {
		_link->compute();
		_status = _link->getStatus();
	}
	return _status;
}
