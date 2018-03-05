//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// InputPainter.hpp
//

#ifndef CPP_NANOTEKSPICE_INPUTPAINTER_HPP
#define CPP_NANOTEKSPICE_INPUTPAINTER_HPP

#include <QWidget>
#include <QtWidgets/QPushButton>
#include <src/pin/APinExt.hpp>
#include "bonus/painter/PinPainter.hpp"
#include "ExtPainter.hpp"

namespace ntsDraw {
	class InputPainter : public ExtPainter {
		Q_OBJECT
	public:
		InputPainter(QWidget *parent, nts::APinExt *pin);

	private slots:
		void changeStatus();
	};
}

#endif /* CPP_NANOTEKSPICE_INPUTPAINTER_HPP */