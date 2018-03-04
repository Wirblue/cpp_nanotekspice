//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// clockManager.cpp
//

#include "ClockManager.hpp"

nts::ClockManager::ClockManager():
	_lastStatus(nts::ClockManager::UNDEFINED), _lastCall(nts::UNDEFINED)
{
}

nts::ClockManager::Status nts::ClockManager::getStatus() const
{
	return _lastStatus;
}

nts::ClockManager::Status nts::ClockManager::move(nts::Tristate currentCall)
{
	if (currentCall == _lastCall)
		_lastStatus = currentCall ? STATIC_UP : STATIC_DOWN;
	else
		_lastStatus = currentCall ? MOVE_UP : MOVE_DOWN;
	_lastCall = currentCall;
	return _lastStatus;
}
