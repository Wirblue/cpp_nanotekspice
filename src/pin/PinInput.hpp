//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// PinInput.hpp
//

#ifndef CPP_NANOTEKSPICE_PININPUT_HPP
#define CPP_NANOTEKSPICE_PININPUT_HPP

#include <IComponent.hpp>
#include "APinExt.hpp"

namespace nts {
	class PinInput : public APinExt {
	public:
		PinInput(std::string name, Tristate status = UNDEFINED);

		virtual Tristate compute() override;
		void setStatus(Tristate);

		virtual PinType getType() override;

	private:
		Tristate _status;
	};
}

#endif /* CPP_NANOTEKSPICE_PININPUT_HPP */