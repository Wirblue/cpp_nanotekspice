//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// Component4040.hpp
//

#ifndef CPP_NANOTEKSPICE_COMPONENT4040_HPP
#define CPP_NANOTEKSPICE_COMPONENT4040_HPP

#include "AComponent.hpp"

namespace nts {
	class Component4040 : public AComponent {
	public:
		Component4040(std::string name = "");
		~Component4040();

		virtual IComponent *clone(std::string name) const override;
		virtual void execute() override;

	private:
		void printPinBinary();

		nts::Tristate _lastState = nts::UNDEFINED;
		size_t _av = 0;
	};
}

#endif /* CPP_NANOTEKSPICE_COMPONENT4040_HPP */