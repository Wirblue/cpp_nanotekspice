//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// ILink.hpp
//

#ifndef CPP_NANOTEKSPICE_ILINK_HPP
#define CPP_NANOTEKSPICE_ILINK_HPP

#include "IPin.hpp"

namespace nts {
	class ILink;
	class IComponent;
	class IPin;
	enum Tristate;

	class ILink {
	public:
		virtual nts::IPin &getLink(nts::IPin in) = 0;
		virtual void setLink(nts::IPin in, nts::IPin out) = 0;
	};
}

#endif /* CPP_NANOTEKSPICE_ILINK_HPP */