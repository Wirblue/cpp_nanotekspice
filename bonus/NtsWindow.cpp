//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// NtsWindow.cpp
//

#include "NtsWindow.hpp"
#include <QPainter>
#include <QtWidgets/QPushButton>
#include <iostream>

ntsDraw::NtsWindow::NtsWindow(nts::Circuit &circuit):
	QMainWindow()
{
	_circuitWidget = new CircuitWidget(this, circuit);
	setFixedSize(1300, 700);

	QPushButton *simulate = new QPushButton("Simulate", this);
	QObject::connect(simulate, SIGNAL(released()), this, SLOT(simulate()));
}

void ntsDraw::NtsWindow::simulate()
{
	std::cout << "ALED" << std::endl;
	_circuitWidget->simulate();
}