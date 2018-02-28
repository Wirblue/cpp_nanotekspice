//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// ComponentOR.hpp
//

#ifndef CPP_NANOTEKSPICE_COMPONENTOR_HPP
#define CPP_NANOTEKSPICE_COMPONENTOR_HPP

#include "ComponentAND.hpp"

namespace nts {
	class ComponentOR : public AComponent {
	public:
		ComponentOR(std::string name = "");
		virtual ~ComponentOR();

		virtual void execute() override;
	};
}

#endif /* CPP_NANOTEKSPICE_COMPONENTOR_HPP */