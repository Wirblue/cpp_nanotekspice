/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** main.cpp
*/

#include <iostream>
#include "components/gates/ComponentAND.hpp"
#include "pin/PinInput.hpp"
#include "pin/PinOutput.hpp"
#include "components/gates/ComponentOR.hpp"
#include "components/Component4Gate.hpp"
#include "components/gates/ComponentNOT.hpp"
#include "components/gates/ComponentNAND.hpp"
#include "components/gates/ComponentNOR.hpp"
#include "components/gates/ComponentXOR.hpp"
#include "components/gates/ComponentXNOR.hpp"
#include "Circuit.hpp"
#include "Parser.hpp"

int main(int ac[[maybe_unused]], char **av)
{
	nts::Parser parser;

	if (!parser.createCircuitFromFile(av[1]))
		return false;
	nts::Circuit &circuit = parser.getCircuit();
	circuit.display();
	return 0;
}