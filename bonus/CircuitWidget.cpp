//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// CircuitPainter.cpp
//

#include <src/Circuit.hpp>
#include <QtWidgets/QPushButton>
#include <QPainter>
#include <QPaintEvent>
#include <iostream>
#include "CircuitWidget.hpp"
#include "PinPainter.hpp"
#include "InputPainter.hpp"
#include "ExtPainter.hpp"

ntsDraw::CircuitWidget::CircuitWidget(QWidget *parent, nts::Circuit &circuit) :
	QWidget(parent), _circuit(circuit)
{
	setGeometry(25, 25, 1250, 600);
	//QPushButton *simulate = new QPushButton("Simulate", this);
	//QObject::connect(simulate, SIGNAL(released()), this, SLOT(simulate()));
}

void ntsDraw::CircuitWidget::init()
{
	size_t i = 0;
	printInputs(i);
	printComponents(i);
	printOuputs(i);
	simulate();
}

void ntsDraw::CircuitWidget::paintEvent(QPaintEvent *event)
{
	QPainter paint(this);

	Q_UNUSED(event);
	paint.setRenderHint(QPainter::Antialiasing);
	paint.drawRect(rect());
	paint.end();
}

void ntsDraw::CircuitWidget::printPin(QPoint pos, PinPainter *pinPainter)
{
	QRect start(pos.x() * _pinSize.x(), pos.y() * _pinSize.y(), _pinSize.x(), _pinSize.y());

	pinPainter->setGeometry(start);
}

void ntsDraw::CircuitWidget::printInputs(size_t &start)
{
	auto pin = _circuit.getClock();
	size_t i = 0;

	for (auto p : pin) {
		printPin(QPoint(start, i * 2), new ExtPainter(this, p.second));
		i++;
	}
	pin = _circuit.getInput();
	for (auto p : pin) {
		printPin(QPoint(start, i * 2), new InputPainter(this, p.second));
		i++;
	}
	start += 2;
}

void ntsDraw::CircuitWidget::printOuputs(size_t &start)
{
	auto pin = _circuit.getOutput();
	size_t i = 0;

	for (auto p : pin) {
		printPin(QPoint(start, i * 2), new ExtPainter(this, p.second));
		i++;
	}
	start += 2;
}

void ntsDraw::CircuitWidget::printComponent(size_t &start, nts::IComponent *component)
{
	size_t size = component->getNbPin();
	QPoint pos(start, 0);

	for (size_t i = 0; i < size; i++) {
		printPin(pos, new PinPainter(this, component->getPin(i)));
		if (i < size / 2 - 1)
			pos.ry()++;
		else if (i == size / 2 - 1)
			pos.rx()++;
		else
			pos.ry()--;

	}
	start += 3;
}

void ntsDraw::CircuitWidget::printComponents(size_t &start)
{
	auto pin = _circuit.getComponent();

	for (auto p : pin) {
		printComponent(start, p.second);
	}
}

void ntsDraw::CircuitWidget::simulate()
{
	_circuit.simulate();
	repaint();
}
