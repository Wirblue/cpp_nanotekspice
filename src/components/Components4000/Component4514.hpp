//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// Component4514.hpp
//

#ifndef CPP_NANOTEKSPICE_COMPONENT4514_HPP
#define CPP_NANOTEKSPICE_COMPONENT4514_HPP

#include "../AComponent.hpp"

namespace nts {
	class Component4514 : public AComponent {
	public:
		Component4514(std::string name = "");
		~Component4514() = default;

		virtual IComponent *clone(std::string name) const override;
		virtual void execute() override;

	private:
		void output(int val);
		int _value;
	};
}

#endif /* CPP_NANOTEKSPICE_COMPONENT4514_HPP */