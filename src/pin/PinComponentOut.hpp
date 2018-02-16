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
		PinComponentOut(IComponent *gate);
		~PinComponentOut();

		virtual Tristate compute() override;
		virtual PinType getType() override;

	private:
		Tristate _lastCall;
	};
}

#endif /* CPP_NANOTEKSPICE_PINCOMPOUT_HPP */