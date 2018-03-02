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
		virtual ~APin() = default;

		virtual void dump() const override;

		virtual Tristate getStatus() const override;
		virtual void setStatus(Tristate status) override;

		virtual IPin *getLink() const override;
		virtual bool link(IPin *pin, bool inComponent) override;
		virtual bool isLinkable(IPin *link) const override;

	protected:
		IPin *_link;
		Tristate _status;
	};
}

#endif /* CPP_NANOTEKSPICE_APIN_HPP */