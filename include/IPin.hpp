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
		virtual bool link(IPin *pin) = 0;
		virtual void dump() const = 0;

		virtual nts::Tristate getStatus() const = 0;
		virtual PinType getType() const = 0;
		virtual PinType getLoc() const = 0;
		virtual IPin *getLink() const = 0;

		virtual void setStatus(nts::Tristate status) = 0;
	};
}

#endif /* CPP_NANOTEKSPICE_IPIN_HPP */