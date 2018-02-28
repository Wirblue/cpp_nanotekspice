//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// APin.hpp
//

#ifndef CPP_NANOTEKSPICE_APIN_HPP
#define CPP_NANOTEKSPICE_APIN_HPP

#include "IPin.hpp"

namespace nts {
	class APin : public IPin {
	public:
		APin();
		~APin() override;

		virtual bool link(IPin *pin) override;
		virtual void dump() const override;
		virtual void setStatus(Tristate status) override;
		virtual Tristate getStatus() const override = 0;
		virtual PinType getType() const override = 0;
		virtual PinType getLoc() const override = 0;

		virtual IPin *getLink() const override;

	protected:
		IPin *_link;
		Tristate _status;
	};
}

#endif /* CPP_NANOTEKSPICE_APIN_HPP */