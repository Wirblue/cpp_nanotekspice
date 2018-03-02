//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// Component4503.hpp
//

#ifndef CPP_NANOTEKSPICE_COMPONENT4503_HPP
#define CPP_NANOTEKSPICE_COMPONENT4503_HPP

#include "../AComponent.hpp"

namespace nts {
	class Component4503 : public AComponent {
	public:
		Component4503(std::string name = "");
		~Component4503() = default;

		virtual IComponent *clone(std::string name) const override;
		virtual void execute() override;
	};
}

#endif /* CPP_NANOTEKSPICE_COMPONENT4503_HPP */