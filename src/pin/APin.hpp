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

		virtual Tristate compute() = 0;
		virtual bool link(IPin *pin) override;
		virtual void dump() override;

	protected:
		IPin *_link;
	};
}

#endif /* CPP_NANOTEKSPICE_APIN_HPP */