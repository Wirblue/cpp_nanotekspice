//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// IGate.hpp
//

#ifndef CPP_NANOTEKSPICE_IGATE_HPP
#define CPP_NANOTEKSPICE_IGATE_HPP

#include <vector>
#include "IComponent.hpp"
#include "IPin.hpp"

namespace nts {
	class IGate {
	public:
		virtual ~IGate() = default;

		virtual Tristate compute() = 0;
		virtual std::vector<IPin> &getInput() = 0;
		virtual std::vector<IPin> &getOutput() = 0;
	};
}

#endif /* CPP_NANOTEKSPICE_IGATE_HPP */