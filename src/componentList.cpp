/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** componentList.cpp
*/

#include "components/Component4Gate.hpp"
#include <map>

namespace nts {
	std::map<std::string, nts::IComponent *> componentList = {
		{"4001", new Component4001()},
		{"4011", new Component4011()},
		{"4030", new Component4030()},
		{"4071", new Component4071()},
		{"4081", new Component4081()}
	};
}