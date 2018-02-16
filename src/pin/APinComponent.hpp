//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// APinComponent.hpp
//

#ifndef CPP_NANOTEKSPICE_APINCOMPONENT_HPP
#define CPP_NANOTEKSPICE_APINCOMPONENT_HPP

#include "APin.hpp"

namespace nts {
	class APinComponent : public APin {
	public:
		APinComponent(IComponent *gate = nullptr);

	protected:
		IComponent *_gate;
	};
}

#endif /* CPP_NANOTEKSPICE_APINCOMPONENT_HPP */