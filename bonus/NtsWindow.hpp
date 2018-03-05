//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// NtsWindow.hpp
//

#ifndef CPP_NANOTEKSPICE_NTSWINDOW_HPP
#define CPP_NANOTEKSPICE_NTSWINDOW_HPP

#include <QMainWindow>
#include "src/Circuit.hpp"
#include "CircuitWidget.hpp"

namespace ntsDraw {
	class NtsWindow : public QMainWindow {
		Q_OBJECT
	public:
		NtsWindow(nts::Circuit &circuit);
		~NtsWindow() = default;

	private slots:
		void simulate();

	private:
		CircuitWidget *_circuitWidget;
	};
}

#endif /* CPP_NANOTEKSPICE_NTSWINDOW_HPP */