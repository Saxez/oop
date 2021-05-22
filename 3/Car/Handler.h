#pragma once
#include "Car.h"
#include <iostream>

using namespace std;

class Handler
{
public:
	Handler(Car& car, ostream& output);

	bool ExecutingCommand(string command);

private:

	bool ChangeGear(int gear);
	bool ChangeSpeed(int speed);
	bool EngineOff();
	bool EngineOn();

	bool FullInfo();

	bool SplitCommand(const string& line, int& param, string& command);
	bool UseCommand(const std::string command, const int value);
	bool UseCommand(const string command);

	Car& m_car;
	ostream& m_output;
};

