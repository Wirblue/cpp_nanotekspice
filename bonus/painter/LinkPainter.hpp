//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// LinkPainter.hpp
//

#ifndef CPP_NANOTEKSPICE_LINKPAINTER_HPP
#define CPP_NANOTEKSPICE_LINKPAINTER_HPP

#include <QtWidgets/QWidget>
#include <QLine>
#include "PinPainter.hpp"

namespace ntsDraw {
	class LinkPainter {
	public:
		LinkPainter(PinPainter *from, PinPainter *to);
		~LinkPainter() = default;

		QLine getLink();
		void drawLine(QWidget *parent, QPaintEvent *painter);
	private:

		PinPainter *_from;
		PinPainter *_to;
	};
}

#endif /* CPP_NANOTEKSPICE_LINKPAINTER_HPP */