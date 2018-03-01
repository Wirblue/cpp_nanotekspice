//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// AComponent.cpp
//

#include <iostream>
#include "AComponent.hpp"

nts::AComponent::AComponent(std::string name, size_t size)
{
	_name = name;
	_nbPin = size;
}

nts::AComponent::~AComponent()
{
}

nts::Tristate nts::AComponent::compute(size_t pin)
{
	if (pin >= _nbPin || _pin[pin]->getType() == IN)
		return UNDEFINED;
	execute();
	return _pin[pin]->getStatus();
}

void nts::AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
	if (pin >= _nbPin || otherPin >= _nbPin)
		return;
	_pin[pin]->link(other.getPin(otherPin), false);
}

void nts::AComponent::dump() const
{
	std::cout << _name << ":" << std::endl;
	for (size_t i = 0; i < _nbPin; i++) {
		std::cout << i + 1 << ": ";
		_pin[i]->dump();
	}
}

nts::IPin *nts::AComponent::getPin(size_t pos) const
{
	if (pos >= _nbPin)
		return nullptr;
	return _pin[pos];
}

void nts::AComponent::reset()
{
	_alreayDone = false;
}

void nts::AComponent::execute()
{
	_alreayDone = true;
}
