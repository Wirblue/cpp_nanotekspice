//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// TristateOperator.cpp
//

#include "IComponent.hpp"

nts::Tristate operator!(nts::Tristate const &a)
{
	if (a == nts::TRUE)
		return nts::FALSE;
	else if (a == nts::FALSE)
		return nts::TRUE;
	return nts::UNDEFINED;
}

nts::Tristate operator|(nts::Tristate const &a, nts::Tristate const &b)
{
	if (a == nts::UNDEFINED || b == nts::UNDEFINED)
		return nts::UNDEFINED;
	if (a == nts::TRUE || b == nts::TRUE)
		return nts::TRUE;
	else
		return nts::FALSE;
}

nts::Tristate operator&(nts::Tristate const &a, nts::Tristate const &b)
{
	if (a == nts::UNDEFINED || b == nts::UNDEFINED)
		return nts::UNDEFINED;
	if (a == nts::TRUE && b == nts::TRUE)
		return nts::TRUE;
	else
		return nts::FALSE;
}

nts::Tristate operator^(nts::Tristate const &a, nts::Tristate const &b)
{
	if (a == nts::UNDEFINED || b == nts::UNDEFINED)
		return nts::UNDEFINED;
	if (a != b)
		return nts::TRUE;
	else
		return nts::FALSE;
}
