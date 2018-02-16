//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// IPin.hpp
//

#ifndef CPP_NANOTEKSPICE_IPIN_HPP
#define CPP_NANOTEKSPICE_IPIN_HPP

#include "IComponent.hpp"

namespace nts {
	enum PinType {
		IN,
		OUT,
		NONE
	};

	class IPin {
	public:
		virtual ~IPin() = default;
		virtual Tristate compute() = 0;
		virtual bool link(IPin *pin) = 0;
		virtual void dump() = 0;
		virtual PinType getType() = 0;
		virtual PinType getLoc() = 0;
	};
}

#endif /* CPP_NANOTEKSPICE_IPIN_HPP */