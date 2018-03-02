//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// PinOutput.hpp
//

#ifndef CPP_NANOTEKSPICE_PINOUTPUT_HPP
#define CPP_NANOTEKSPICE_PINOUTPUT_HPP

#include "APinExt.hpp"

namespace nts {
	class PinOutput : public APinExt {
	public:
		PinOutput(std::string name);
		~PinOutput();

		virtual PinType getType() const override;

		virtual Tristate compute() override;
	};
}

#endif /* CPP_NANOTEKSPICE_PINOUTPUT_HPP */