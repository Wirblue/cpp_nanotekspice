//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// IComponent.hpp
//

#ifndef CPP_NANOTEKSPICE_ICOMPONENT_HPP
#define CPP_NANOTEKSPICE_ICOMPONENT_HPP

#include <string>

namespace nts {
	enum Tristate {
		UNDEFINED = (-true),
		TRUE = true,
		FALSE = false
	};

	class IPin;

	class IComponent
	{
	public:
		virtual ~IComponent() = default;

		virtual IComponent *clone(std::string name) const = 0;
		virtual Tristate compute(std::size_t pin = 1) = 0;
		virtual void setLink(std::size_t pin,
			IComponent &other,
			std::size_t otherPin) = 0;
		virtual void dump() const = 0;
		virtual void execute() = 0;
		virtual IPin *getPin(size_t pos) const = 0;
	};
}

nts::Tristate operator!(nts::Tristate const &a);
nts::Tristate operator|(nts::Tristate const &a, nts::Tristate const &b);
nts::Tristate operator&(nts::Tristate const &a, nts::Tristate const &b);
nts::Tristate operator^(nts::Tristate const &a, nts::Tristate const &b);
std::ostream &operator<<(std::ostream &os, nts::Tristate const &a);

#endif /* CPP_NANOTEKSPICE_ICOMPONENT_HPP */