//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// PinPainter.hpp
//

#ifndef CPP_NANOTEKSPICE_PINPAINTER_HPP
#define CPP_NANOTEKSPICE_PINPAINTER_HPP

#include "../src/pin/IPin.hpp"
#include <QWidget>

namespace ntsDraw {
	class PinPainter : public QWidget {
	public:
		PinPainter(QWidget *parent, nts::IPin *Pin = nullptr);
		void draw();

	private:
		nts::IPin *_pin;
	};
}

#endif /* CPP_NANOTEKSPICE_PINPAINTER_HPP */