#include "Processing.h"
#include "Car.h"
#include <string>
#include <regex>
#include <map>
#include <iostream>
#include <string>

using namespace std;

vector<int> MIN_SPEED = { 0, INTPTR_MIN , 0, 20, 30, 40, 50 };
vector<int> MAX_SPEED = { 20, INTPTR_MAX , 30, 50, 60, 90, 150 };
vector<int> GEARS = { -1, 0, 1, 2, 3, 4, 5 };

string const ERROR_COMMAND = "This command doesnt exist\n";


string DelSpaces(string st)
{
	for (int j = st.size() - 1; j >= 0; j--)
	{
		if (st[j] == ' ')
		{
			st.resize(j);
		}
		else
		{
			return st;
		}
	}
	return st;
}

bool ErrorCommand()
{
	cout << ERROR_COMMAND;
	return true;
}

bool CheckSpeed(int speed, int gear)
{
	if ((speed <= MAX_SPEED[gear+1]) && (speed >= MIN_SPEED[gear+1]))
	{
		return true;
	}
	return false;
}

bool CheckGearOnExsit(int gear)
{
	if (find(GEARS.begin(), GEARS.end(), gear) != GEARS.end())
	{
		return true;
	}
	return false;
}