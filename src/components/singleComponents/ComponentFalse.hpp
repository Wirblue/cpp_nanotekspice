//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// ComponentFalse.hpp
//

#ifndef CPP_NANOTEKSPICE_COMPONENTFALSE_HPP
#define CPP_NANOTEKSPICE_COMPONENTFALSE_HPP

#include "../AComponent.hpp"

namespace nts {
	class ComponentFalse : public AComponent {
	public:
		ComponentFalse(std::string name = "");
		virtual ~ComponentFalse();

		virtual void execute() override;
		virtual nts::IComponent *clone(std::string name) const override;
	};
}

#endif /* CPP_NANOTEKSPICE_COMPONENTFALSE_HPP */