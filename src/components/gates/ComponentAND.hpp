//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// ComponentAND.hpp
//

#ifndef CPP_NANOTEKSPICE_COMPONENTAND_HPP
#define CPP_NANOTEKSPICE_COMPONENTAND_HPP

#include "../AComponent.hpp"

namespace nts {
	class ComponentAND : public AComponent {
	public:
		ComponentAND(std::string name = "");
		virtual ~ComponentAND();

		virtual void execute() override;
	};
}

#endif /* CPP_NANOTEKSPICE_COMPONENTAND_HPP */