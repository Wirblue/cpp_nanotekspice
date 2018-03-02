//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// PinCompOut.hpp
//

#ifndef CPP_NANOTEKSPICE_PINCOMPOUT_HPP
#define CPP_NANOTEKSPICE_PINCOMPOUT_HPP

#include "APinComponent.hpp"

namespace nts {
	class PinComponentOut : public APinComponent {
	public:
		explicit PinComponentOut(IComponent *component = nullptr);
		~PinComponentOut() = default;

		virtual PinType getType() const override;

		virtual Tristate compute() override;
	};
}

#endif /* CPP_NANOTEKSPICE_PINCOMPOUT_HPP */