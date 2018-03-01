//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// Component4013.hpp
//

#ifndef CPP_NANOTEKSPICE_COMPONENT4013_HPP
#define CPP_NANOTEKSPICE_COMPONENT4013_HPP

#include "AComponent.hpp"
#include "gates/ComponentFF.hpp"

namespace nts {
	class Component4013 : public AComponent {
	public:
		Component4013(std::string name = "");
		~Component4013();

		virtual IComponent *clone(std::string name) const override;
		virtual void execute() override;

		virtual void reset() override;

	private:
		ComponentFF _ffGate[2];
	};
}

#endif /* CPP_NANOTEKSPICE_COMPONENT4013_HPP */