//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// ComponentFF.hpp
//

#ifndef CPP_NANOTEKSPICE_COMPONENTFF_HPP
#define CPP_NANOTEKSPICE_COMPONENTFF_HPP

#include "AGate.hpp"
#include "ComponentNOR.hpp"

namespace nts {
	class ComponentFF : public AGate {
	public:
		ComponentFF(std::string name = "");
		~ComponentFF();

		virtual IComponent *clone(std::string name) const override;
		virtual void execute() override;

	private:
		Tristate memory = UNDEFINED;
	};
}

#endif /* CPP_NANOTEKSPICE_COMPONENTFF_HPP */