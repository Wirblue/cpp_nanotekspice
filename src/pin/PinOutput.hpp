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

		virtual Tristate compute() override;


		virtual PinType getType() override;
	};
}

#endif /* CPP_NANOTEKSPICE_PINOUTPUT_HPP */