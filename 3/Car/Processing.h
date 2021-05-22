#pragma once
#include <string>
#include <regex>
#include "Car.h"

using namespace std;

string DelSpaces(string st);

bool ErrorCommand();

bool CheckSpeed(int speed, int gear);

bool CheckGearOnExsit(int gear);