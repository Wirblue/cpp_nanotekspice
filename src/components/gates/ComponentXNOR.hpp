//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// ComponentXNOR.hpp
//

#ifndef CPP_NANOTEKSPICE_COMPONENTXNOR_HPP
#define CPP_NANOTEKSPICE_COMPONENTXNOR_HPP

#include "ComponentXOR.hpp"

namespace nts {
	class ComponentXNOR : public ComponentXOR {
	public:
		ComponentXNOR(std::string name = "");
		virtual ~ComponentXNOR();

		virtual void execute() override;
	};
}

#endif /* CPP_NANOTEKSPICE_COMPONENTXNOR_HPP */