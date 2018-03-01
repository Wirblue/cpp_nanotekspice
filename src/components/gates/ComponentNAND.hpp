//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// ComponentNNAND.hpp
//

#ifndef CPP_NANOTEKSPICE_COMPONENTNNAND_HPP
#define CPP_NANOTEKSPICE_COMPONENTNNAND_HPP

#include "ComponentAND.hpp"

namespace nts {
	class ComponentNAND : public ComponentAND {
	public:
		ComponentNAND(std::string name = "");
		virtual ~ComponentNAND();

		virtual void execute() override;

		virtual IComponent *clone(std::string name) const override;
	};
}

#endif /* CPP_NANOTEKSPICE_COMPONENTNNAND_HPP */