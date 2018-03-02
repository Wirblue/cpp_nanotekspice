//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// AComponent.hpp
//

#ifndef CPP_NANOTEKSPICE_ACOMPONENT_HPP
#define CPP_NANOTEKSPICE_ACOMPONENT_HPP

#include <vector>
#include <string>
#include "../pin/IPin.hpp"
#include "../pin/APinComponent.hpp"
#include "../pin/PinComponentIn.hpp"
#include "../pin/PinComponentOut.hpp"

namespace nts {
	class AComponent : public IComponent {
	public:
		AComponent(std::string name, size_t size);
		~AComponent();

		virtual void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) override;
		virtual void dump() const override;
		virtual Tristate compute(size_t pin) override;
		virtual IPin *getPin(size_t pos) const override;
		virtual void reset() override;
		virtual void execute() override;

		virtual bool alreadyCalc() override;

	protected:
		std::string _name;
		std::vector<IPin *> _pin;
		size_t _nbPin;
		bool _alreayDone = false;
	};
}

#endif /* CPP_NANOTEKSPICE_ACOMPONENT_HPP */