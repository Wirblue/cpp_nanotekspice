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
#include "components/Component4081.hpp"
#include "components/gates/ComponentNOT.hpp"
#include "components/gates/ComponentNAND.hpp"
#include "components/gates/ComponentNOR.hpp"
#include "components/gates/ComponentXOR.hpp"
#include "components/gates/ComponentXNOR.hpp"
#include "Circuit.hpp"

int main()
{
	nts::Circuit circuit;

	circuit.addOutput("aled");
	circuit.addOutput("aled2");
	circuit.addOutput("aled");
}