//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// ComponentXOR.hpp
//

#ifndef CPP_NANOTEKSPICE_COMPONENTXOR_HPP
#define CPP_NANOTEKSPICE_COMPONENTXOR_HPP

#include "AGate.hpp"

namespace nts {
	class ComponentXOR : public AGate {
	public:
		ComponentXOR(std::string name = "");
		virtual ~ComponentXOR();

		virtual void execute() override;

		virtual IComponent *clone(std::string name) const override;
	};
}

#endif /* CPP_NANOTEKSPICE_COMPONENTXOR_HPP */