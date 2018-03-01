//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// NtsException.hpp
//

#ifndef CPP_NANOTEKSPICE_NTSEXCEPTION_HPP
#define CPP_NANOTEKSPICE_NTSEXCEPTION_HPP

#include <bits/exception.h>
#include <string>

namespace nts {
	class NtsException : public std::exception {
	public:
		NtsException(std::string const &message,
			std::string detail = "");

		const char *what() const throw() override;
	private:
		std::string _message;
		std::string _detail;
	};
}

#endif /* CPP_NANOTEKSPICE_NTSEXCEPTION_HPP */