//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// Parser.hpp
//

#ifndef CPP_NANOTEKSPICE_PARSER_HPP
#define CPP_NANOTEKSPICE_PARSER_HPP

#include "Circuit.hpp"

namespace nts {
	class Parser {
	public:
		Parser();
		~Parser();

		bool createCircuitFromFile(std::string file, char **statement);
		bool addInputValue(char **av);
		bool checkInputOutput();
		Circuit &getCircuit();

	private:
		enum readType {
			NONE,
			CHIPSETS,
			LINKS
		};

		void parseFile(std::ifstream &stream);

		bool parseChipsets(std::string a, std::string b);
		bool parseLinks(std::string a, std::string b);
		bool readDefault(std::ifstream &file, readType &status);
		bool readChiptsets(std::ifstream &file, readType &status);
		bool readLinks(std::ifstream &file);

		Circuit _circuit;
	};
}

#endif /* CPP_NANOTEKSPICE_PARSER_HPP */