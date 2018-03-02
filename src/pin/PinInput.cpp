//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// PinInput.cpp
//

#include "PinInput.hpp"

nts::PinInput::PinInput(std::string name, nts::Tristate status):
	APinExt(name)
{
	_status = status;
}

nts::PinType nts::PinInput::getType() const
{
	return IN;
}

nts::Tristate nts::PinInput::compute()
{
	return _status;
}
