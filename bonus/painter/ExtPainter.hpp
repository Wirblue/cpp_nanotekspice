//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// ExtPainter.hpp
//

#ifndef CPP_NANOTEKSPICE_EXTPAINTER_HPP
#define CPP_NANOTEKSPICE_EXTPAINTER_HPP

#include "bonus/painter/PinPainter.hpp"

namespace ntsDraw {
	class ExtPainter : public PinPainter {
	public:
		ExtPainter(QWidget *parent, nts::APinExt *pin);

	protected:
		void paintEvent(QPaintEvent *event) override;
		nts::APinExt *_pinExt;
	};
}

#endif /* CPP_NANOTEKSPICE_EXTPAINTER_HPP */