//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// PinPainter.cpp
//

#include <QPainter>
#include <iostream>
#include "PinPainter.hpp"

ntsDraw::PinPainter::PinPainter(QWidget *parent, nts::IPin *Pin) :
	QPushButton(parent), _pin(Pin)
{
}

Qt::GlobalColor ntsDraw::PinPainter::getColor()
{
	switch (_pin->getStatus()) {
	case nts::UNDEFINED:
		return Qt::darkGray;
	case nts::FALSE:
		return Qt::darkRed;
	case nts::TRUE:
		return Qt::darkGreen;
	}
}

void ntsDraw::PinPainter::paintEvent(QPaintEvent *event)
{
	QPainter paint;
	QBrush color;

	paint.begin(this);
	paint.setRenderHint(QPainter::Antialiasing);
	if (_pin)
		color = getColor();
	paint.fillRect(rect(), color);
	paint.end();
}

nts::IPin *ntsDraw::PinPainter::getPin() const
{
	return _pin;
}

const QPoint &ntsDraw::PinPainter::getPos() const
{
	return _pos;
}

void ntsDraw::PinPainter::setPos(const QPoint &pos)
{
	_pos = pos;
}
