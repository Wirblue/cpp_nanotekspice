//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// NtsWindow.cpp
//

#include "NtsWindow.hpp"
#include <QPainter>
#include <QTimer>
#include <QEvent>
#include <QKeyEvent>
#include <QListWidget>

ntsDraw::NtsWindow::NtsWindow(nts::Circuit &circuit):
	QMainWindow()
{
	QPushButton *simulate = new QPushButton("Simulate", this);
	QPushButton *loop = new QPushButton("Loop", this);
	QPushButton *exit = new QPushButton("Quit", this);
	_timer = new QTimer(this);

	connect(_timer, SIGNAL(timeout()), this, SLOT(simulate()));
	simulate->setGeometry(100, 650, 300, 25);
	loop->setGeometry(500, 650, 300, 25);
	exit->setGeometry(900, 650, 300, 25);
	_circuitWidget = new CircuitWidget(this, circuit);
	_circuitWidget->init();
	setFixedSize(1300, 700);
	QObject::connect(exit, SIGNAL(clicked()), this, SLOT(close()));
	QObject::connect(simulate, SIGNAL(clicked()), this, SLOT(simulate()));
	QObject::connect(loop, SIGNAL(clicked()), this, SLOT(loop()));
}

void ntsDraw::NtsWindow::keyPressEvent(QKeyEvent * event)
{
	switch (event->key()) {
	case (Qt::Key_PageDown):
		_circuitWidget->zoom(0.9);
		break;
	case (Qt::Key_PageUp):
		_circuitWidget->zoom(1.1);
		break;
	case (Qt::Key_Q):
		_circuitWidget->move(QPoint(-1, 0));
		break;
	case (Qt::Key_D):
		_circuitWidget->move(QPoint(1, 0));
		break;
	case (Qt::Key_Z):
		_circuitWidget->move(QPoint(0, -1));
		break;
	case (Qt::Key_S):
		_circuitWidget->move(QPoint(0, 1));
		break;
	}
}

void ntsDraw::NtsWindow::simulate()
{
	_circuitWidget->simulate();
	_circuitWidget->repaint();
}

void ntsDraw::NtsWindow::loop()
{
	if (_timer->isActive())
		_timer->stop();
	else
		_timer->start(100);
}
