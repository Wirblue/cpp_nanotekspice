//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// PinComponentIn.hpp
//

#ifndef CPP_NANOTEKSPICE_PINCOMPONENTIN_HPP
#define CPP_NANOTEKSPICE_PINCOMPONENTIN_HPP

#include "APinComponent.hpp"

namespace nts {
	class PinComponentIn : public APinComponent {
	public:
		PinComponentIn(IComponent *component = nullptr);
		~PinComponentIn() = default;

		virtual PinType getType() const override;

		virtual Tristate compute() override;
	};
}

#endif /* CPP_NANOTEKSPICE_PINCOMPONENTIN_HPP */