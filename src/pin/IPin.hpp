//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// IPin.hpp
//

#ifndef CPP_NANOTEKSPICE_IPIN_HPP
#define CPP_NANOTEKSPICE_IPIN_HPP

#include "../components/IComponent.hpp"

namespace nts {
	enum PinType {
		IN,
		OUT,
		NONE
	};

	class IPin {
	public:
		virtual ~IPin() = default;

		virtual void dump() const = 0;

		virtual nts::Tristate getStatus() const = 0;
		virtual void setStatus(nts::Tristate status) = 0;

		virtual IPin *getLink() const = 0;
		virtual bool link(IPin *pin, bool inComponent) = 0;
		virtual bool isLinkable(IPin *link) const = 0;

		virtual PinType getType() const = 0;
		virtual PinType getLoc() const = 0;

		virtual Tristate compute() = 0;
	};
}

#endif /* CPP_NANOTEKSPICE_IPIN_HPP */