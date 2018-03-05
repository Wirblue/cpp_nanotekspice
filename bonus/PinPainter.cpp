//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// PinPainter.cpp
//

#include <QPainter>
#include <iostream>
#include "PinPainter.hpp"

ntsDraw::PinPainter::PinPainter(QWidget *parent, nts::IPin *Pin):
	QPushButton(parent), _pin(Pin)
{
}


void ntsDraw::PinPainter::paintEvent(QPaintEvent *event)
{
	QPainter paint;
	QBrush color;

	paint.begin(this);
	paint.setRenderHint(QPainter::Antialiasing);
	if (_pin)
		switch (_pin->getStatus()) {
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
	else
		color = Qt::blue;
	paint.fillRect(rect(), color);
	paint.end();
}
