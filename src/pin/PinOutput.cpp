//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// PinOutput.cpp
//

#include <IComponent.hpp>
#include "PinOutput.hpp"

nts::PinOutput::PinOutput(std::string name):
	APinExt(name)
{
}

nts::PinOutput::~PinOutput()
{
}

nts::Tristate nts::PinOutput::getStatus() const
{
	if (!this->_link)
		return UNDEFINED;
	return this->_link->getStatus();
}

nts::PinType nts::PinOutput::getType() const
{
	return OUT;
}
