//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// APinExt.hpp
//

#ifndef CPP_NANOTEKSPICE_APINEXT_HPP
#define CPP_NANOTEKSPICE_APINEXT_HPP

#include <string>
#include "APin.hpp"

namespace nts {
	class APinExt : public APin {
	public:
		APinExt(std::string name = "");
		virtual ~APinExt() = default;

		void setName(std::string name);
		std::string getName();

		virtual PinType getLoc() const override;

	protected:
		std::string _name;
	};
}

#endif /* CPP_NANOTEKSPICE_APINEXT_HPP */