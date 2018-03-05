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
	QPushButton *simulate = new QPushButton("Simulate", this);
	QPushButton *loop = new QPushButton("Loop", this);
	QPushButton *exit = new QPushButton("Quit", this);

	simulate->setGeometry(100, 650, 300, 25);
	loop->setGeometry(500, 650, 300, 25);
	exit->setGeometry(900, 650, 300, 25);
	_circuitWidget = new CircuitWidget(this, circuit);
	_circuitWidget->init();
	setFixedSize(1300, 700);
	QObject::connect(exit, SIGNAL(clicked()), this, SLOT(close()));
	QObject::connect(simulate, SIGNAL(clicked()), this, SLOT(simulate()));
}

void ntsDraw::NtsWindow::simulate()
{
	_circuitWidget->simulate();
	_circuitWidget->repaint();
}