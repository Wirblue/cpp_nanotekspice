//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// CircuitPainter.hpp
//

#ifndef CPP_NANOTEKSPICE_CIRCUITPAINTER_HPP
#define CPP_NANOTEKSPICE_CIRCUITPAINTER_HPP

#include <QtWidgets/QWidget>
#include <src/Circuit.hpp>
#include <QtCore/QVector>
#include "PinPainter.hpp"

namespace ntsDraw {
	class CircuitWidget : public QWidget {
		Q_OBJECT
	public:
		CircuitWidget(QWidget *parent, nts::Circuit &circuit);

		void init();
		void simulate();

	private:
		void paintEvent(QPaintEvent *event) override;

		void printPin(QPoint pos, PinPainter *);
		void printInputs(size_t &start);
		void printOuputs(size_t &start);
		void printComponent(size_t &start, nts::IComponent *component);
		void printComponents(size_t &start);

		QPoint _pos;
		QPoint _pinSize = QPoint(30, 30);
		nts::Circuit &_circuit;
	};
}

#endif /* CPP_NANOTEKSPICE_CIRCUITPAINTER_HPP */