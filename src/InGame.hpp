//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// InGame.hpp
//

#ifndef CPP_NANOTEKSPICE_INGAME_HPP
#define CPP_NANOTEKSPICE_INGAME_HPP

#include "Circuit.hpp"

namespace nts {
	class InGame {
	public:
		InGame(Circuit &circuit);

		void start();

		void display();
		void input();
		void simulate();
		void loop();
		void dump();

	private:
		std::string _lastLine;
		Circuit &_circuit;
	};

	typedef void (InGame::*command_t)();
}

#endif /* CPP_NANOTEKSPICE_INGAME_HPP */