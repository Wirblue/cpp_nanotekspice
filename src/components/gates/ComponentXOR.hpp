//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// ComponentXOR.hpp
//

#ifndef CPP_NANOTEKSPICE_COMPONENTXOR_HPP
#define CPP_NANOTEKSPICE_COMPONENTXOR_HPP

#include "../AComponent.hpp"

namespace nts {
	class ComponentXOR : public AComponent {
	public:
		ComponentXOR(std::string name = "");
		virtual ~ComponentXOR();

		virtual void execute() override;
	};
}

#endif /* CPP_NANOTEKSPICE_COMPONENTXOR_HPP */