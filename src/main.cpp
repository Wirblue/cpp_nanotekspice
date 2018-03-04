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
#include "components/Components4000/Component4Gate.hpp"
#include "components/gates/ComponentNOT.hpp"
#include "components/gates/ComponentXNOR.hpp"
#include "Circuit.hpp"
#include "Parser.hpp"
#include "InGame.hpp"
#include "exception/NtsException.hpp"
#include "components/ComponentFF.hpp"

int main(int ac[[maybe_unused]], char **av)
{
	nts::Parser parser;
	nts::InGame game(parser.getCircuit());

	if (ac <= 1)
		throw nts::NtsException("No Such File", "nanotekspice");
	if (!parser.createCircuitFromFile(av[1], av + 2))
		return 84;
	game.start();
	return 0;
}