//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// Circuit.cpp
//

#include <fstream>
#include <iostream>
#include "exception/NtsException.hpp"
#include "Circuit.hpp"
#include "components/Components4000/Component4Gate.hpp"

bool nts::Circuit::alreadyExist(std::string name)
{

	return (_output.find(name.c_str()) != _output.end()
		|| _input.find(name.c_str()) != _input.end()
		|| _component.find(name.c_str()) != _component.end()
		|| _clock.find(name.c_str()) != _clock.end());
}

bool nts::Circuit::addOutput(std::string name)
{
	PinOutput *newOutput = new PinOutput(name);

	if (alreadyExist(name))
		throw nts::NtsException("Name already used for a component",
			name);
	_output.insert(std::make_pair(name, newOutput));
	return true;
}

bool nts::Circuit::addInput(std::string name)
{
	PinInput *newInput = new PinInput(name);

	if (alreadyExist(name))
		throw nts::NtsException("Name already used for a component",
			name);
	_input.insert(std::make_pair(name, newInput));
	return true;
}

bool nts::Circuit::addClock(std::string name)
{
	PinInput *newClock = new PinInput(name, nts::TRUE);

	if (alreadyExist(name))
		throw nts::NtsException("Name already used for a component",
			name);
	_clock.insert(std::make_pair(name, newClock));
	return true;
}

bool nts::Circuit::addComponent(std::string name, std::string type)
{
	IComponent *newComponent;

	if (componentList.find(type.c_str()) == componentList.end())
		throw nts::NtsException("Invalid Component Type", type);
	newComponent = componentList[type]->clone(name);
	if (!newComponent)
		throw nts::NtsException("Error at creation", type);
	if (alreadyExist(name))
		throw nts::NtsException("Name already used for a component",
			name);
	_component.insert(std::make_pair(name, newComponent));
	return true;
}

nts::IPin *nts::Circuit::findPin(std::string name, size_t pos)
{
	if (_input.find(name.c_str()) != _input.end()) {
		return _input[name];
	} else if (_clock.find(name.c_str()) != _clock.end()) {
		return _clock[name];
	} else if (_output.find(name.c_str()) != _output.end()) {
		return _output[name];
	} else if (_component.find(name.c_str()) != _component.end()) {
		return _component[name]->getPin(pos);
	}
	throw nts::NtsException("isn't a component !", name);
}

bool nts::Circuit::linkComponent(std::string name1, size_t pin1,
	std::string name2, size_t pin2)
{
	nts::IPin *a = findPin(name1, pin1 - 1);
	nts::IPin *b = findPin(name2, pin2 - 1);

	if (a == nullptr)
		throw nts::NtsException("Pin not found", name1);
	if (b == nullptr)
		throw nts::NtsException("Pin not found", name2);
	if (!(a->link(b, false)))
		throw nts::NtsException("Invalid Link", name1 + " " + name2);
	return true;
}

void nts::Circuit::dump()
{
	for (auto const& p : _component) {
		p.second->dump();
	}
}

void nts::Circuit::reset()
{
	for (auto gate : _component)
		gate.second->reset();
}

void nts::Circuit::simulate()
{
	reset();
	clocks();
	for (auto const& p : _output) {
		p.second->compute();
	}
}

void nts::Circuit::displayOutput()
{
	for (auto const& p : _output) {
		std::cout << p.first << "=";
		p.second->dump();
	}
}

void nts::Circuit::displayInput()
{
	for (auto const& p : _input) {
		std::cout << p.first << "=";
		p.second->dump();
	}
}

bool nts::Circuit::setInput(std::string name, nts::Tristate status,
	bool allowClocks)
{
	if (_input.find(name.c_str()) != _input.end())
		_input[name]->setStatus(status);
	else if (allowClocks && _clock.find(name.c_str()) != _clock.end())
		_clock[name]->setStatus(!status);
	else
		throw nts::NtsException("Invalid Input", name);
	return true;
}

bool nts::Circuit::setInputFromText(std::string text, bool allowClocks)
{
	size_t apos = text.find('=');
	std::string name1;
	nts::Tristate value = nts::UNDEFINED;

	name1 = text.substr(0, apos);
	if (text.substr(apos + 1) == "1")
		value = nts::TRUE;
	else if (text.substr(apos + 1) == "0")
		value = nts::FALSE;
	else if (text.substr(apos + 1) == "U")
		value = nts::UNDEFINED;
	else
		return false;
	setInput(name1, value, allowClocks);
	return true;
}

bool nts::Circuit::checkOutput()
{
	bool status = true;

	for (auto a : _output) {
		if (a.second->getLink() == nullptr)
			status = false;
	}
	return status;
}

bool nts::Circuit::checkInput()
{
	bool status = true;

	for (auto a : _input) {
		if (!a.second
			|| a.second->getLink() == nullptr
			|| a.second->getStatus() == nts::UNDEFINED)
			status = false;
	}
	return status;
}

void nts::Circuit::clocks()
{
	for (auto const& p : _clock) {
		p.second->setStatus(!p.second->getStatus());
	}
}
