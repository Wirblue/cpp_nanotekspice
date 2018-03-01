//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// ComponentNOR.hpp
//

#ifndef CPP_NANOTEKSPICE_COMPONENTNOR_HPP
#define CPP_NANOTEKSPICE_COMPONENTNOR_HPP

#include "ComponentOR.hpp"

namespace nts {
	class ComponentNOR : public ComponentOR {
	public:
		ComponentNOR(std::string name = "");
		virtual ~ComponentNOR();

		virtual void execute() override;

		virtual IComponent *clone(std::string name) const override;
	};
}


#endif /* CPP_NANOTEKSPICE_COMPONENTNOR_HPP */