//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// AGate.cpp
//

#include "AGate.hpp"

nts::AGate::AGate(std::string name, size_t size):
	AComponent(name, size)
{
}

void nts::AGate::linkPin(std::vector<IPin *> pins)
{
	size_t i = 0;

	for (auto pin : pins) {
		if (i > _nbPin)
			return;
		if (pin && pin->getType() == IN)
			_pin[i]->link(pin, true);
		else if (pin)
			pin->link(_pin[i], true);
		i++;
	}
}
