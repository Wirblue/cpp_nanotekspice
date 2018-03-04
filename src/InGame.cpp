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
		{"display", &InGame::circuitDisplayOutput},
		{"output", &InGame::circuitDisplayOutput},
		{"input", &InGame::circuitDisplayInput},
		{"simulate", &InGame::circuitSimulate},
		{"loop", &InGame::circuitLoop},
		{"dump", &InGame::circuitDump},
		{"clocks", &InGame::circuitClocks},
		{"reset", &InGame::circuitReset},
	};
}

nts::InGame::InGame(Circuit &circuit):
	_circuit(circuit)
{
	_lastLine = "";
}

void nts::InGame::start()
{
	_circuit.simulate();
	_circuit.displayOutput();
	signal(SIGINT, &(baseSigint));
	std::cout << "> ";
	mainLoop();
}

void nts::InGame::mainLoop()
{
	while (getline(std::cin, _lastLine) && _lastLine != "exit") {
		try {
			if (!_lastLine.empty())
				parseCommand();
		} catch (const nts::NtsException &e) {
			std::cerr << "Shell: " <<  e.what() << std::endl;
		}
		std::cout << "> ";
	}
}

void nts::InGame::parseCommand()
{
	if (nts::commandList.find(_lastLine.c_str()) != nts::commandList.end())
		(*this.*(nts::commandList[_lastLine]))();
	else if (isInput())
		circuitSetInput();
	else
		throw nts::NtsException("Command not found", _lastLine);
}

bool nts::InGame::isInput()
{
	return _lastLine.find('=') < _lastLine.length();
}

void nts::InGame::circuitDisplayOutput()
{
	_circuit.displayOutput();
}

void nts::InGame::circuitDisplayInput()
{
	_circuit.displayInput();
}

void nts::InGame::circuitSetInput()
{
	_circuit.setInputFromText(_lastLine, false);
}

void nts::InGame::circuitSimulate()
{
	_circuit.simulate();
}

void nts::InGame::circuitLoop()
{
	int i = 0;
	signal(SIGINT, &(loopSiging));
	aled = true;
	for (i = 0; aled; i++)
		_circuit.simulate();
	std::cout << "Simulations played : " << i << std::endl;
	signal(SIGINT, &(baseSigint));
}

void nts::InGame::circuitDump()
{
	_circuit.dump();
}

void nts::InGame::circuitClocks()
{
	_circuit.clocks();
}

void nts::InGame::circuitReset()
{
	_circuit.reset();
}
