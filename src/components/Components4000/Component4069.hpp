//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// Component4069.hpp
//

#ifndef CPP_NANOTEKSPICE_COMPONENT4069_HPP
#define CPP_NANOTEKSPICE_COMPONENT4069_HPP

#include "../AComponent.hpp"
#include "../gates/ComponentNOT.hpp"

namespace nts {
	class Component4069 : public AComponent {
	public:
		Component4069(std::string name = "");
		~Component4069() = default;

		virtual IComponent *clone(std::string name) const override;
		virtual void execute() override;

		virtual void reset() override;

	private:
		ComponentNOT _notGate[6];
	};
}

#endif /* CPP_NANOTEKSPICE_COMPONENT4069_HPP */