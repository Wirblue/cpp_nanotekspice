//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// Component4Gate.hpp
//

#ifndef CPP_NANOTEKSPICE_COMPONENT4081_HPP
#define CPP_NANOTEKSPICE_COMPONENT4081_HPP

#include "AComponent.hpp"
#include "gates/ComponentAND.hpp"
#include "gates/ComponentXOR.hpp"
#include "gates/ComponentNAND.hpp"
#include "gates/ComponentNOR.hpp"

namespace nts {
	template <typename T>
	class Component4Gate : public AComponent {
	public:
		Component4Gate<T>(std::string name = "");
		virtual ~Component4Gate<T>();

		virtual void execute() override;

		virtual IComponent *clone(std::string name) const override;

		virtual void reset() override;

	private:
		T _andGates[4];
	};

	typedef nts::Component4Gate<nts::ComponentNOR> Component4001;
	typedef nts::Component4Gate<nts::ComponentNAND> Component4011;
	typedef nts::Component4Gate<nts::ComponentXOR> Component4030;
	typedef nts::Component4Gate<nts::ComponentOR> Component4071;
	typedef nts::Component4Gate<nts::ComponentAND> Component4081;
}

#endif /* CPP_NANOTEKSPICE_COMPONENT4081_HPP */