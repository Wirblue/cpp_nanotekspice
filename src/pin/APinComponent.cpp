//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// APinComponent.cpp
//

#include "APinComponent.hpp"

nts::APinComponent::APinComponent(IComponent *gate):
	_component(gate)
{
	_status = UNDEFINED;
}

nts::PinType nts::APinComponent::getLoc() const
{
	return IN;
}
