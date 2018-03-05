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
#include <bonus/painter/LinkPainter.hpp>
#include "bonus/painter/PinPainter.hpp"

#define OFFSET 2

namespace ntsDraw {
	class CircuitWidget : public QWidget {
		Q_OBJECT
	public:
		CircuitWidget(QWidget *parent, nts::Circuit &circuit);

		void init();
		void simulate();

		void zoom(float coef);
		void move(QPoint mov);

	private:
		void refreshPin();

		void paintEvent(QPaintEvent *event) override;
		void printPin(QPoint pos, PinPainter *);
		void printInputs(size_t &start);
		void printOuputs(size_t &start);
		void printComponent(size_t &start, nts::IComponent *component);
		void printComponents(size_t &start);
		void printLines();

		std::vector<LinkPainter> _link;
		std::vector<PinPainter *> _pin;
		QPoint _start = QPoint(0, 0);
		QPoint _pinSize = QPoint(10, 10);
		nts::Circuit &_circuit;
	};
}

#endif /* CPP_NANOTEKSPICE_CIRCUITPAINTER_HPP */