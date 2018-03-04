/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Component4094.hpp
*/

#ifndef CPP_NANOTEKSPICE_COMPONENT4094_HPP
#define CPP_NANOTEKSPICE_COMPONENT4094_HPP

#include "../AComponent.hpp"
#include "../../other/ClockManager.hpp"

namespace nts {
	class Component4094 : public AComponent {
	public:
		Component4094(std::string name = "");
		~Component4094() = default;

		virtual IComponent *clone(std::string name) const override;
		virtual void execute() override;

	private:
		void setAllQPin(nts::Tristate a);
		ClockManager _clock;
	};
}

#endif /* CPP_NANOTEKSPICE_COMPONENT4094_HPP */