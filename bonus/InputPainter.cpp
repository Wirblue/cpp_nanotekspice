//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// InputPainter.cpp
//

#include "InputPainter.hpp"

ntsDraw::InputPainter::InputPainter(QWidget *parent, nts::APinExt *pin):
	ExtPainter(parent, pin)
{
	QObject::connect(this, SIGNAL(clicked()), this, SLOT(changeStatus()));
}


void ntsDraw::InputPainter::changeStatus()
{
	if (_pin)
		_pin->setStatus(!_pin->getStatus());
	repaint();
}