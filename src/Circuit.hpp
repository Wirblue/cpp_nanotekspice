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
#include "IPin.hpp"
#include "IComponent.hpp"
#include "pin/PinInput.hpp"
#include "pin/PinOutput.hpp"

namespace nts {
	class Circuit {
	public:
		Circuit();
		~Circuit();

		bool createCircuitFromFile(std::string file);

		bool addInput(std::string name);
		bool addComponent(std::string name, std::string type);
		bool addOutput(std::string name);

		bool linkComponent(std::string name1, size_t pin1,
			std::string name2, size_t pin2);

		void dumpComponent();

	private:

		enum readType {
			NONE,
			CHIPSETS,
			LINKS
		};

		bool parseChipsets(std::string a, std::string b);
		bool parseLinks(std::string a, std::string b);

		bool readDefault(std::ifstream &file, readType &status);
		bool readChiptsets(std::ifstream &file, readType &status);
		bool readLinks(std::ifstream &file, readType &status);

		IPin *findPin(std::string name, size_t pos);

		std::map<std::string, PinInput *> _input;
		std::map<std::string, IComponent *> _component;
		std::map<std::string, PinOutput *> _output;
	};
}

#endif /* CPP_NANOTEKSPICE_CIRCUIT_HPP */