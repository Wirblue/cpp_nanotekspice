//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// IComponent.hpp
//

#ifndef CPP_NANOTEKSPICE_ICOMPONENT_HPP
#define CPP_NANOTEKSPICE_ICOMPONENT_HPP

#include <cstdio>

namespace nts
{
	enum Tristate {
		UNDEFINED = (-true),
		TRUE = true,
		FALSE = false
	};

	class IComponent {
	public:
		virtual ~IComponent() = default;
	public:
		virtual nts::Tristate compute(std::size_t bbpin = 1) = 0;
		virtual void setLink(std::size_t pin,
		                     nts::IComponent &other,
		                     std::size_t otherPin) = 0;
		virtual void dump() const = 0;
	};
}

#endif /* CPP_NANOTEKSPICE_ICOMPONENT_HPP */