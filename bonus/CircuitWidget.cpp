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

ntsDraw::CircuitWidget::CircuitWidget(QWidget *parent, nts::Circuit &circuit) :
	QWidget(parent), _circuit(circuit)
{
	setGeometry(25, 25, 1250, 600);
	QPushButton *simulate = new QPushButton("Simulate", this);
	QObject::connect(simulate, SIGNAL(released()), this, SLOT(simulate()));
}

void ntsDraw::CircuitWidget::paintEvent(QPaintEvent *event)
{
	Q_UNUSED(event);
	QPainter paint;
	size_t i = 0;

	paint.begin(this);
	paint.setRenderHint(QPainter::Antialiasing);
	printInputs(paint, i);
	printComponents(paint, i);
	printOuputs(paint, i);
	paint.end();
}

void ntsDraw::CircuitWidget::printPin(QPainter &painter, QPoint pos, nts::IPin *pin)
{
	QRect start(pos.x() * _pinSize.x() - _pos.x(), pos.y() * _pinSize.y() - _pos.y(), _pinSize.x(), _pinSize.y());
	QBrush color;

	switch (pin->getStatus()) {
	case nts::UNDEFINED:
		color = Qt::blue;
		break;
	case nts::FALSE:
		color = Qt::red;
		break;
	case nts::TRUE:
		color = Qt::green;
		break;
	}
	painter.fillRect(start, color);
}

void ntsDraw::CircuitWidget::printInputs(QPainter &painter, size_t &start)
{
	auto pin = _circuit.getClock();
	size_t i = 0;

	for (auto p : pin) {
		printPin(painter, QPoint(start, i * 2), p.second);
		i++;
	}
	pin = _circuit.getInput();
	for (auto p : pin) {
		printPin(painter, QPoint(start, i * 2), p.second);
		i++;
	}
	start += 2;
}

void ntsDraw::CircuitWidget::printOuputs(QPainter &painter, size_t &start)
{
	auto pin = _circuit.getOutput();
	size_t i = 0;

	for (auto p : pin) {
		printPin(painter, QPoint(start, i * 2), p.second);
		i++;
	}
	start += 2;
}

void ntsDraw::CircuitWidget::printComponent(QPainter &painter, size_t &start,
	nts::IComponent *component)
{
	size_t size = component->getNbPin();
	QPoint pos(start, 0);

	for (size_t i = 0; i < size; i++) {
		printPin(painter, pos, component->getPin(i));
		if (i < size / 2 - 1)
			pos.ry()++;
		else if (i == size / 2 - 1)
			pos.rx()++;
		else
			pos.ry()--;

	}
	start += 3;
}

void ntsDraw::CircuitWidget::printComponents(QPainter &painter, size_t &start)
{
	auto pin = _circuit.getComponent();

	for (auto p : pin) {
		printComponent(painter, start, p.second);
	}
}

void ntsDraw::CircuitWidget::simulate()
{
	std::cout << "JE SUIS OSKOUR" << std::endl;
	_circuit.simulate();
}
