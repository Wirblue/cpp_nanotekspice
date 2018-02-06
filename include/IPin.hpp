//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// IPin.hpp
//

#ifndef CPP_NANOTEKSPICE_IPIN_HPP
#define CPP_NANOTEKSPICE_IPIN_HPP

namespace nts {
	class IComponent;
	class IPin;
	enum Tristate;

	class IPin {
	public:
		virtual ~IPin() = default;
		virtual nts::Tristate compute() = 0;
		virtual void dump() const = 0;
		virtual void setLink(IPin &other) = 0;
		virtual nts::IPin &getLink() const = 0;
		virtual std::string &getName() const = 0;
	};
}

#endif /* CPP_NANOTEKSPICE_IPIN_HPP */