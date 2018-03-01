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
#include "exception/NtsException.hpp"
#include "exception/NtsException.hpp"


static void baseSigint(int i[[maybe_unused]])
{
	write(1, "\n> ", 3);
}

bool aled = false;

static void loopSiging(int i[[maybe_unused]])
{
	aled = false;
}

namespace nts {
	std::map<std::string, nts::command_t> commandList {
		{"display", &InGame::displayOutput},
		{"output", &InGame::displayOutput},
		{"input", &InGame::displayInput},
		{"simulate", &InGame::simulate},
		{"loop", &InGame::loop},
		{"dump", &InGame::dump},
	};
}

nts::InGame::InGame(Circuit &circuit):
	_circuit(circuit)
{
	_lastLine = "";
}

void nts::InGame::start()
{
	if (!_circuit.checkInput() || !_circuit.checkOutput())
		throw nts::NtsException("Invalid Input or Output", "Circuit");
	_circuit.simulate();
	signal(SIGINT, &(baseSigint));
	std::cout << "> ";
	mainLoop();
}

void nts::InGame::mainLoop()
{
	while (getline(std::cin, _lastLine) && _lastLine != "exit") {
		if (nts::commandList.find(_lastLine.c_str()) != nts::commandList.end())
			(*this.*(nts::commandList[_lastLine]))();
		else
			input();
		std::cout << "> ";
	}
}

void nts::InGame::displayOutput()
{
	_circuit.displayOutput();
}

void nts::InGame::displayInput()
{
	_circuit.displayInput();
}

void nts::InGame::input()
{
	if (!_circuit.setInputFromText(_lastLine))
		std::cout << "Error: Command not found" << std::endl;
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