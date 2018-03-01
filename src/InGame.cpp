//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// InGame.cpp
//

#include <iostream>
#include <map>
#include <csignal>
#include <zconf.h>
#include "Circuit.hpp"
#include "InGame.hpp"

namespace nts {
	std::map<std::string, nts::command_t> commandList {
		{"display", &InGame::display},
		{"simulate", &InGame::simulate},
		{"loop", &InGame::loop},
		{"dump", &InGame::dump},
	};
}


/* A changer ???? */
void baseSigint(int i[[maybe_unused]])
{
	write(1, "\n> ", 3);
}

bool aled = false;

void loopSiging(int i[[maybe_unused]])
{
	aled = false;
}

nts::InGame::InGame(Circuit &circuit):
	_circuit(circuit)
{
	_lastLine = "";
}

void nts::InGame::start()
{
	signal(SIGINT, &(baseSigint));
	std::cout << "> ";
	while (getline(std::cin, _lastLine) && _lastLine != "exit") {
		if (nts::commandList.find(_lastLine.c_str()) != nts::commandList.end())
			(*this.*(nts::commandList[_lastLine]))();
		else
			input();
		std::cout << "> ";
	}
}

void nts::InGame::display()
{
	_circuit.display();
}

void nts::InGame::input()
{
	size_t apos = _lastLine.find('=');
	std::string name1;
	nts::Tristate value = nts::UNDEFINED;

	name1 = _lastLine.substr(0, apos);
	if (_lastLine.substr(apos + 1) == "1")
		value = nts::TRUE;
	else if (_lastLine.substr(apos + 1) == "0")
		value = nts::FALSE;
	else if (_lastLine.substr(apos + 1) == "U")
		value = nts::UNDEFINED;
	else {
		std::cout << "Error: Command not found" << std::endl;
		return;
	}
	std::cout << "Input '" << name1 << "' set to " << value << std::endl;
	_circuit.setInput(name1, value);
}

void nts::InGame::simulate()
{
	_circuit.simulate();
}

void nts::InGame::loop()
{
	int i = 0;
	signal(SIGINT, &(loopSiging));
	aled = true;
	for (i = 0; aled; i++)
		_circuit.simulate();
	std::cout << "Simulations played : " << i << std::endl;
	signal(SIGINT, &(baseSigint));
}

void nts::InGame::dump()
{
	_circuit.dump();
}