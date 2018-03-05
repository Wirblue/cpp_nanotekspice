//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// AComponent.cpp
//

#include <iostream>
#include "AComponent.hpp"

nts::AComponent::AComponent(std::string name, size_t size):
	_name(name), _nbPin(size)
{
}

void nts::AComponent::dump() const
{
	std::cout << _name << ":" << std::endl;
	for (size_t i = 0; i < _nbPin; i++) {
		std::cout << i + 1 << "=";
		_pin[i]->dump();
	}
}

nts::IPin *nts::AComponent::getPin(size_t pos) const
{
	if (pos >= _nbPin)
		return nullptr;
	return _pin[pos];
}

size_t nts::AComponent::getNbPin() const
{
	return _nbPin;
}

void nts::AComponent::reset()
{
	_alreayDone = false;
}

bool nts::AComponent::tryExecution()
{
	if (_alreayDone)
		return false;
	_alreayDone = true;
	return true;
}

nts::Tristate nts::AComponent::compute(size_t pin)
{
	if (pin >= _nbPin)
		return nts::UNDEFINED;
	return _pin[pin]->compute();
}

void nts::AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
	if (pin >= _nbPin || otherPin >= _nbPin)
		return;
	_pin[pin]->link(other.getPin(otherPin), false);
}