/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** componentList.cpp
*/

#include "components/Component4Gate.hpp"
#include "components/singleComponents/ComponentFalse.hpp"
#include "components/singleComponents/ComponentTrue.hpp"
#include "components/Component4069.hpp"
#include "components/gates/ComponentFF.hpp"
#include "components/Component4013.hpp"
#include "components/Component4017.hpp"
#include <map>

namespace nts {
	std::map<std::string, nts::IComponent *> componentList = {
		{"true", new ComponentTrue()},
		{"false", new ComponentFalse()},
		{"4001", new Component4001()},
		{"4011", new Component4011()},
		{"4013", new Component4013()},
		{"4017", new Component4017()},
		{"4030", new Component4030()},
		{"4069", new Component4069()},
		{"4071", new Component4071()},
		{"4081", new Component4081()}
	};
}