//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// Component4017.hpp
//

#ifndef CPP_NANOTEKSPICE_COMPONENT4017_HPP
#define CPP_NANOTEKSPICE_COMPONENT4017_HPP

#include "../AComponent.hpp"
#include "../../other/ClockManager.hpp"

namespace nts {
	class Component4017 : public AComponent {
	public:
		Component4017(std::string name = "");
		~Component4017();

		virtual IComponent *clone(std::string name) const override;
		virtual void execute() override;
	private:
		void openOnlyOne(size_t i);
		size_t _av = 0;
		nts::ClockManager _clock;
	};
}

#endif /* CPP_NANOTEKSPICE_COMPONENT4017_HPP */