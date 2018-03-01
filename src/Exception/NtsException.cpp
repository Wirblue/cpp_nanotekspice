//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// NtsException.cpp
//

#include <iostream>
#include "NtsException.hpp"

nts::NtsException::NtsException(std::string const &message, std::string detail) :
	_message(detail.empty() ? "" : ("'" + detail + "' ") + message)
{
}

const char *nts::NtsException::what() const throw()
{
	return _message.c_str();
}
