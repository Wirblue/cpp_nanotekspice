/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** main.cpp
*/

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QPainter>
#include <src/Parser.hpp>
#include <src/exception/NtsException.hpp>
#include <iostream>
#include "NtsWindow.hpp"

int test()
{
	std::cout << "NTM LA GROOSSE PUTE" << std::endl;
	return (2);
}

int main(int ac, char **av)
{
	nts::Parser parser;

	if (ac <= 1)
		throw nts::NtsException("No Such File", "nanotekspice");
	if (!parser.createCircuitFromFile(av[1], av + 2))
		return 84;
	QApplication app(ac, av);
	ntsDraw::NtsWindow win(parser.getCircuit());

	win.show();

	return app.exec();
}