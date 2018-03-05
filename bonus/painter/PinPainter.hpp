//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// PinPainter.hpp
//

#ifndef CPP_NANOTEKSPICE_PINPAINTER_HPP
#define CPP_NANOTEKSPICE_PINPAINTER_HPP

#include "src/pin/IPin.hpp"
#include <QWidget>
#include <QtWidgets/QPushButton>

namespace ntsDraw {
	class PinPainter : public QPushButton {
		Q_OBJECT
	public:
		PinPainter(QWidget *parent, nts::IPin *Pin);
		nts::IPin *getPin() const;
		const QPoint &getPos() const;
		void setPos(const QPoint &pos);
		Qt::GlobalColor getColor();

	protected:
		void paintEvent(QPaintEvent *event) override;
		nts::IPin *_pin;
		QPoint _pos;
	};
}

#endif /* CPP_NANOTEKSPICE_PINPAINTER_HPP */