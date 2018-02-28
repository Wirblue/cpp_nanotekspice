//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// Component4081.hpp
//

#ifndef CPP_NANOTEKSPICE_COMPONENT4081_HPP
#define CPP_NANOTEKSPICE_COMPONENT4081_HPP

#include "AComponent.hpp"
#include "gates/ComponentAND.hpp"

namespace nts {
	class Component4081 : public AComponent {
	public:
		Component4081(std::string name);
		virtual ~Component4081();

		virtual void execute() override;

	private:
		ComponentAND _andGates[4];
	};
}

#endif /* CPP_NANOTEKSPICE_COMPONENT4081_HPP */