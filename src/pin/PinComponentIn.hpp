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
		PinComponentIn(IComponent *gate = nullptr);
		~PinComponentIn();

		virtual Tristate compute() override;
		virtual PinType getType() override;
	};
}

#endif /* CPP_NANOTEKSPICE_PINCOMPONENTIN_HPP */