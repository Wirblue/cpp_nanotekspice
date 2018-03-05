//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// LinkPainter.cpp
//

#include <QLine>
#include <QPainter>
#include "LinkPainter.hpp"
#include "PinPainter.hpp"

ntsDraw::LinkPainter::LinkPainter(PinPainter *from, PinPainter *to):
	_from(from), _to(to)
{
}

QLine ntsDraw::LinkPainter::getLink()
{
	QPoint from(_from->pos());
	QPoint to(_to->pos());

	from += QPoint(_from->size().width() / 2, _from->size().height() / 2);
	to += QPoint(_to->size().width() / 2, _to->size().height() / 2);
	return QLine(from, to);
}

void ntsDraw::LinkPainter::drawLine(QWidget *parent, QPaintEvent *painter)
{
	Q_UNUSED(painter);
	QPainter paint(parent);

	paint.setPen(_from->getColor());
	paint.drawLine(getLink());
}
