/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** componentList.cpp
*/

#include "components/Components4000/Component4Gate.hpp"
#include "components/singleComponents/ComponentFalse.hpp"
#include "components/singleComponents/ComponentTrue.hpp"
#include "components/Components4000/Component4069.hpp"
#include "components/ComponentFF.hpp"
#include "components/Components4000/Component4013.hpp"
#include "components/Components4000/Component4017.hpp"
#include "components/Components4000/Component4040.hpp"
#include "components/Components4000/Component4503.hpp"
#include "components/Components4000/Component4514.hpp"
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
		{"4040", new Component4040()},
		{"4069", new Component4069()},
		{"4071", new Component4071()},
		{"4081", new Component4081()},
		{"4503", new Component4503()},
		{"4514", new Component4514()}
	};
}