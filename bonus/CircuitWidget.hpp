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

namespace ntsDraw {
	class CircuitWidget : public QWidget {
		Q_OBJECT
	public:
		CircuitWidget(QWidget *parent, nts::Circuit &circuit);

	public slots:
		void simulate();

	protected:
		void paintEvent(QPaintEvent *event) override;

	private:
		void printPin(QPainter &painter, QPoint pos, nts::IPin *pin);

		void printInputs(QPainter &painter, size_t &start);
		void printOuputs(QPainter &painter, size_t &start);
		void printComponent(QPainter &painter, size_t &start,
			nts::IComponent *component);

		void printComponents(QPainter &painter, size_t &start);

		QPoint _pos;
		QPoint _pinSize = QPoint(30, 30);
		nts::Circuit &_circuit;
	};
}

#endif /* CPP_NANOTEKSPICE_CIRCUITPAINTER_HPP */