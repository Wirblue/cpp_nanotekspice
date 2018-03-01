//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// ComponentNOT.hpp
//

#ifndef CPP_NANOTEKSPICE_COMPONENTNOT_HPP
#define CPP_NANOTEKSPICE_COMPONENTNOT_HPP

#include "../AComponent.hpp"

namespace nts {
	class ComponentNOT : public AComponent {
	public:
		ComponentNOT(std::string name = "");
		virtual ~ComponentNOT();

		virtual void execute() override;

		virtual IComponent *clone(std::string name) const override;
	};
}

#endif /* CPP_NANOTEKSPICE_COMPONENTNOT_HPP */