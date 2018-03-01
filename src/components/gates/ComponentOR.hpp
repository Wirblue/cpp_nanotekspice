//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// ComponentOR.hpp
//

#ifndef CPP_NANOTEKSPICE_COMPONENTOR_HPP
#define CPP_NANOTEKSPICE_COMPONENTOR_HPP

#include "AGate.hpp"

namespace nts {
	class ComponentOR : public AGate {
	public:
		ComponentOR(std::string name = "");
		virtual ~ComponentOR();

		virtual void execute() override;

		virtual IComponent *clone(std::string name) const override;
	};
}

#endif /* CPP_NANOTEKSPICE_COMPONENTOR_HPP */