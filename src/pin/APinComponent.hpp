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
		virtual ~APinComponent() = default;

		virtual PinType getLoc() const override;

	protected:
		IComponent *_component;
	};
}

#endif /* CPP_NANOTEKSPICE_APINCOMPONENT_HPP */