//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// Circuit.hpp
//

#ifndef CPP_NANOTEKSPICE_CIRCUIT_HPP
#define CPP_NANOTEKSPICE_CIRCUIT_HPP

#include <string>
#include <vector>
#include <map>
#include "pin/IPin.hpp"
#include "components/IComponent.hpp"
#include "pin/PinInput.hpp"
#include "pin/PinOutput.hpp"

namespace nts {
	extern std::map<std::string, IComponent *> componentList;

	class Circuit {
	public:
		Circuit();
		~Circuit();

		bool addInput(std::string name);
		bool addClock(std::string name);
		bool addComponent(std::string name, std::string type);
		bool addOutput(std::string name);

		bool linkComponent(std::string name1, size_t pin1, std::string name2, size_t pin2);
		bool setInputFromText(std::string value);

		void dump();
		void simulate();
		void displayOutput();
		void displayInput();
		bool setInput(std::string name, nts::Tristate status);

		bool checkOutput();
		bool checkInput();

	private:
		bool alreadyExist(std::string name);
		IPin *findPin(std::string name, size_t pos);
		void moveClocks();

		std::map<std::string, PinInput *> _input;
		std::map<std::string, PinInput *> _clock;
		std::map<std::string, IComponent *> _component;
		std::map<std::string, PinOutput *> _output;
	};
}

#endif /* CPP_NANOTEKSPICE_CIRCUIT_HPP */