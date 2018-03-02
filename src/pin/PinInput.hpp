//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// PinInput.hpp
//

#ifndef CPP_NANOTEKSPICE_PININPUT_HPP
#define CPP_NANOTEKSPICE_PININPUT_HPP

#include "../components/IComponent.hpp"
#include "APinExt.hpp"

namespace nts {
	class PinInput : public APinExt {
	public:
		PinInput(std::string name = "", Tristate status = UNDEFINED);
		~PinInput() = default;

		virtual PinType getType() const override;

		virtual Tristate compute() override;
	};
}

#endif /* CPP_NANOTEKSPICE_PININPUT_HPP */