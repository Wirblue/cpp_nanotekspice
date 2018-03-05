//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// ExtPainter.cpp
//

#include <QPainter>
#include <iostream>
#include "../src/pin/APinExt.hpp"
#include "ExtPainter.hpp"

ntsDraw::ExtPainter::ExtPainter(QWidget *parent, nts::APinExt *pin):
	PinPainter(parent, pin), _pinExt(pin)
{
}

void ntsDraw::ExtPainter::paintEvent(QPaintEvent *event)
{
	PinPainter::paintEvent(event);
	QPainter painter;

	painter.begin(this);
	painter.drawText(rect(), Qt::AlignCenter, QString::fromStdString(_pinExt->getName()));
	painter.end();
}
