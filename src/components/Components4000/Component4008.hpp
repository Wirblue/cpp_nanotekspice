//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// Component4008.hpp
//

#ifndef CPP_NANOTEKSPICE_COMPONENT4008_HPP
#define CPP_NANOTEKSPICE_COMPONENT4008_HPP

#include "../AComponent.hpp"

namespace nts {
	class Component4008 : public AComponent {
	public:
		Component4008(std::string name = "");
		~Component4008() = default;

		virtual IComponent *clone(std::string name) const override;
		virtual void execute() override;

	private:
		nts::Tristate sum(Tristate a, Tristate b,
			Tristate c, size_t output) const;
	};
}

#endif /* CPP_NANOTEKSPICE_COMPONENT4008_HPP */