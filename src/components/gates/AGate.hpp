//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// AGate.hpp
//

#ifndef CPP_NANOTEKSPICE_AGATE_HPP
#define CPP_NANOTEKSPICE_AGATE_HPP

#include "../AComponent.hpp"

namespace nts {
	class AGate : public AComponent {
	public:
		AGate(std::string name, size_t size);
		~AGate();

		void linkPin(std::vector<IPin *> pin);
	};
}

#endif /* CPP_NANOTEKSPICE_AGATE_HPP */