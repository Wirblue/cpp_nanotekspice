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
#include "bonus/painter/PinPainter.hpp"
#include "bonus/painter/InputPainter.hpp"
#include "bonus/painter/ExtPainter.hpp"

ntsDraw::CircuitWidget::CircuitWidget(QWidget *parent, nts::Circuit &circuit) :
	QWidget(parent), _circuit(circuit)
{
	setGeometry(25, 25, 1250, 600);
}

void ntsDraw::CircuitWidget::init()
{
	size_t i = 0;

	printInputs(i);
	printComponents(i);
	printOuputs(i);
	printLines();
	simulate();
}

void ntsDraw::CircuitWidget::paintEvent(QPaintEvent *event)
{
	QPainter paint(this);

	Q_UNUSED(event);
	paint.setRenderHint(QPainter::Antialiasing);
	paint.drawRect(rect());
	for (LinkPainter &line : _link) {
		paint.setPen(Qt::blue);
		line.drawLine(this, event);
	}
	paint.end();
}

void ntsDraw::CircuitWidget::printLines()
{
	for (PinPainter *a : _pin) {
		if (a && a->getPin() && a->getPin()->getLink())
			for (PinPainter *b : _pin) {
				if (b && b->getPin()
					&& b->getPin()== a->getPin()->getLink())
					_link.push_back(LinkPainter(a, b));
			}
	}
}

void ntsDraw::CircuitWidget::printPin(QPoint pos, PinPainter *pinPainter)
{
	QRect start(pos.x() * _pinSize.x(), pos.y() * _pinSize.y(), _pinSize.x(), _pinSize.y());

	pinPainter->setPos(pos);
	pinPainter->setGeometry(start);
	_pin.push_back(pinPainter);
}

void ntsDraw::CircuitWidget::printInputs(size_t &start)
{
	auto pin = _circuit.getClock();
	size_t i = 0;

	for (auto p : pin) {
		printPin(QPoint(start, i * 2),
			new ExtPainter(this, p.second));
		i++;
	}
	pin = _circuit.getInput();
	for (auto p : pin) {
		printPin(QPoint(start, i * 2),
			new InputPainter(this, p.second));
		i++;
	}
	start += 1 + OFFSET;
}

void ntsDraw::CircuitWidget::printOuputs(size_t &start)
{
	auto pin = _circuit.getOutput();
	size_t i = 0;

	for (auto p : pin) {
		printPin(QPoint(start, i * 2),
			new ExtPainter(this, p.second));
		i++;
	}
	start += 1 + OFFSET;
}

void ntsDraw::CircuitWidget::printComponent(size_t &start, nts::IComponent *component)
{
	size_t size = component->getNbPin();
	QPoint pos(start, 0);

	for (size_t i = 0; i < size; i++) {
		printPin(pos,
			new PinPainter(this, component->getPin(i)));
		//if (i < size / 2 - 1)
			pos.ry()++;
		/*else if (i == size / 2 - 1)
			pos.rx()++;
		else
			pos.ry()--;*/

	}
	start += 1 /*+ (size > 1 ? 1 : 0)*/ + OFFSET;
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

void ntsDraw::CircuitWidget::refreshPin()
{
	QRect start;
	QPoint pos;

	for (PinPainter *pin : _pin) {
		pos = pin->getPos();
		start = QRect(
			(pos.x() - _start.x()) * _pinSize.x(),
			(pos.y() - _start.y()) * _pinSize.y(),
			_pinSize.x(), _pinSize.y());
		pin->setGeometry(start);
		repaint();
	}
}

void ntsDraw::CircuitWidget::zoom(float coef)
{
	_pinSize *= coef;
	refreshPin();
}

void ntsDraw::CircuitWidget::move(QPoint mov)
{
	_start -= mov;
	refreshPin();
}
