//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// ComponentTrue.hpp
//

#ifndef CPP_NANOTEKSPICE_COMPONENTTRUE_HPP
#define CPP_NANOTEKSPICE_COMPONENTTRUE_HPP

#include "../AComponent.hpp"

namespace nts {
	class ComponentTrue : public AComponent {
	public:
		ComponentTrue(std::string name = "");
		virtual ~ComponentTrue();

		virtual void execute() override;
		virtual nts::IComponent *clone(std::string name) const override;
	};
}

#endif /* CPP_NANOTEKSPICE_COMPONENTTRUE_HPP */