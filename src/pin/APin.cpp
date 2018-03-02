//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// APin.cpp
//

#include <iostream>
#include "APin.hpp"

nts::APin::APin():
	_link(nullptr), _status(nts::UNDEFINED)
{
}


void nts::APin::dump() const
{
	std::cout << getStatus() << std::endl;
}


nts::Tristate nts::APin::getStatus() const
{
	return _status;
}

void nts::APin::setStatus(Tristate status)
{
	_status = status;
}


nts::IPin *nts::APin::getLink() const
{
	return _link;
}

bool nts::APin::link(IPin *pin, bool inComponent)
{
	if (inComponent) {
		_link = pin;
		return true;
	}
	if (!pin) {
		std::cerr << "Can't link to null !" << std::endl;
		return false;
	}

	if (!_link && getLoc() == nts::OUT && getType() == nts::IN) {
		if (pin->isLinkable(this)) {
			_link = pin;
			pin->link(this, false);
			return true;
		} else
			return false;

	}
	if (isLinkable(pin) && !_link)
		_link = pin;
	else if (pin->isLinkable(this))
		return pin->link(this, false);
	else {
		std::cout << "Invalid Connection" << std::endl;
		return false;
	}
	return true;
}

bool nts::APin::isLinkable(IPin *link) const
{
	if (!link)
		return false;

	if (getLoc() == nts::OUT && getType() == nts::IN) {
		return false;
	}
	bool a2 = getType() == link->getType();
	bool a1 = getLoc() == link->getLoc();
	return (a1 ^ a2);
}
