//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// ComponentAND.hpp
//

#ifndef CPP_NANOTEKSPICE_COMPONENTAND_HPP
#define CPP_NANOTEKSPICE_COMPONENTAND_HPP

#include "AGate.hpp"

namespace nts {
	class ComponentAND : public AGate {
	public:
		ComponentAND(std::string name = "");
		virtual ~ComponentAND();

		virtual void execute() override;
		virtual nts::IComponent *clone(std::string name) const override;

	};
}

#endif /* CPP_NANOTEKSPICE_COMPONENTAND_HPP */