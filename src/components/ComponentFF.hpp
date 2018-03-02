//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// ComponentFF.hpp
//

#ifndef CPP_NANOTEKSPICE_COMPONENTFF_HPP
#define CPP_NANOTEKSPICE_COMPONENTFF_HPP

#include "gates/AGate.hpp"
#include "gates/ComponentNOR.hpp"

namespace nts {
	class ComponentFF : public AGate {
	public:
		ComponentFF(std::string name = "");
		~ComponentFF() = default;

		virtual IComponent *clone(std::string name) const override;
		virtual void execute() override;

	private:
		Tristate _memory = FALSE;
		Tristate _reset = UNDEFINED;
		Tristate _lastState = UNDEFINED;
	};
}

#endif /* CPP_NANOTEKSPICE_COMPONENTFF_HPP */