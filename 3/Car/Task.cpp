#include <iostream>
#include <istream>
#include <string>
#include <map>
#include "Car.h"
#include "Handler.h"

using namespace std;

int main()
{
	Car newCar;
	Handler handler(newCar, cout);
	string inp;
	string command;
	int value;
	while (getline(cin, inp))
	{
		handler.ExecutingCommand(inp);
	}

	return 0;
}