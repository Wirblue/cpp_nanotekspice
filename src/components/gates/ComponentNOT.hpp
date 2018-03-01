//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// ComponentNOT.hpp
//

#ifndef CPP_NANOTEKSPICE_COMPONENTNOT_HPP
#define CPP_NANOTEKSPICE_COMPONENTNOT_HPP

#include "AGate.hpp"

namespace nts {
	class ComponentNOT : public AGate {
	public:
		ComponentNOT(std::string name = "");
		virtual ~ComponentNOT();

		virtual void execute() override;

		virtual IComponent *clone(std::string name) const override;
	};
}

#endif /* CPP_NANOTEKSPICE_COMPONENTNOT_HPP */