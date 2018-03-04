/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** ClockManager.hpp
*/

#ifndef CPP_NANOTEKSPICE_CLOCKMANAGER_HPP
#define CPP_NANOTEKSPICE_CLOCKMANAGER_HPP

#include "../components/IComponent.hpp"

namespace nts {
	class ClockManager {
	public:
		ClockManager();
		~ClockManager() = default;

		enum Status {
			MOVE_UP,
			MOVE_DOWN,
			STATIC_UP,
			STATIC_DOWN,
			UNDEFINED
		};

		Status getStatus() const;
		Status move(nts::Tristate currentCall);
	private:
		Status _lastStatus;
		nts::Tristate _lastCall;
	};
}

#endif /* CPP_NANOTEKSPICE_CLOCKMANAGER_HPP */