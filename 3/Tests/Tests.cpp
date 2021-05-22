#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"
#include "../Car/Car.h"
#include "../Car/Handler.h"
#include "../Car/Processing.h"
using namespace std;

SCENARIO("check not main function")
{
	Car car;
	REQUIRE(CheckSpeed(10, 1));
	REQUIRE(!CheckSpeed(100, 1));

	REQUIRE(DelSpaces("A    ") == "A");
	REQUIRE(DelSpaces("   A    ") == "   A");

	REQUIRE(CheckGearOnExsit(1));
	REQUIRE(!CheckGearOnExsit(100));
}

SCENARIO("Car start info")
{
	Car car;
	Handler handler(car, cout);
	REQUIRE(car.IsTurnedOn() == false);
	REQUIRE(car.GetGear() == 0);
	REQUIRE(car.GetDirection() == 0);
	REQUIRE(car.GetSpeed() == 0);
	cout << "Car start info is done\n\n";
}

SCENARIO("Car only engine on")
{
	Car car;
	Handler handler(car, cout);
	handler.ExecutingCommand("EngineOn");
	REQUIRE(car.IsTurnedOn() == true);
	REQUIRE(car.GetGear() == 0);
	REQUIRE(car.GetDirection() == 0);
	REQUIRE(car.GetSpeed() == 0);
	cout << "Car engine on is done\n\n";
}

SCENARIO("Car cant change gear with engine off")
{
	Car car;
	Handler handler(car, cout);
	handler.ExecutingCommand("SetGear 1");
	REQUIRE(car.GetGear() != 1);
	cout << "Car cant change gear with engine off is done\n\n";
}

SCENARIO("Car engine on then engine off")
{
	Car car;
	Handler handler(car, cout);
	handler.ExecutingCommand("EngineOn");
	handler.ExecutingCommand("EngineOff");
	REQUIRE(car.IsTurnedOn() == false);
	REQUIRE(car.GetGear() == 0);
	REQUIRE(car.GetDirection() == 0);
	REQUIRE(car.GetSpeed() == 0);
	cout << "Car engine on then engine off is done\n\n";
}

SCENARIO("Change gear without speed")
{
	Car car;
	Handler handler(car, cout);
	handler.ExecutingCommand("EngineOn");
	handler.ExecutingCommand("SetGear 1");
	REQUIRE(car.GetGear() == 1);
	handler.ExecutingCommand("SetGear 2");
	REQUIRE(car.GetGear() != 2);
	REQUIRE(car.IsTurnedOn() == true);
	REQUIRE(car.GetGear() == 1);
	REQUIRE(car.GetDirection() == 0);
	REQUIRE(car.GetSpeed() == 0);
	cout << "Change gear without speed is done\n\n";
}

SCENARIO("Start and change speed")
{
	Car car;
	Handler handler(car, cout);
	handler.ExecutingCommand("EngineOn");
	handler.ExecutingCommand("SetGear 1");
	handler.ExecutingCommand("SetSpeed 10");
	REQUIRE(car.GetGear() == 1);
	REQUIRE(car.GetDirection() == 1);
	REQUIRE(car.GetSpeed() == 10);
	cout << "Start and change speed is done\n\n";
}

SCENARIO("Start, change speed, change gear to neutral")
{
	Car car;
	Handler handler(car, cout);
	handler.ExecutingCommand("EngineOn");
	handler.ExecutingCommand("SetGear 1");
	handler.ExecutingCommand("SetSpeed 10");
	handler.ExecutingCommand("SetGear 0");
	REQUIRE(car.GetGear() == 0);
	REQUIRE(car.GetDirection() == 1);
	REQUIRE(car.GetSpeed() == 10);
	cout << "Start, change speed, change gear to neutral is done\n\n";
}
 
SCENARIO("Start, change speed, change gear to impossible gear")
{
	Car car;
	Handler handler(car, cout);
	handler.ExecutingCommand("EngineOn");
	handler.ExecutingCommand("SetGear 1");
	handler.ExecutingCommand("SetSpeed 10");
	handler.ExecutingCommand("SetGear 3");
	REQUIRE(car.GetGear() != 3);
	REQUIRE(car.GetGear() == 1);
	cout << "Start, change speed, change gear to impossible gear is done\n\n";
}
 
SCENARIO("Start, change speed and gear, then stop")
{
	Car car;
	Handler handler(car, cout);
	handler.ExecutingCommand("EngineOn");
	handler.ExecutingCommand("SetGear 1");
	handler.ExecutingCommand("SetSpeed 10");
	handler.ExecutingCommand("SetSpeed 0");
	handler.ExecutingCommand("SetGear 0");
	REQUIRE(car.GetGear() == 0);
	REQUIRE(car.GetDirection() == 0);
	REQUIRE(car.GetSpeed() == 0);
	cout << "Start, change speed and gear, then stop is done\n\n";
}

SCENARIO("Start and go back")
{
	Car car;
	Handler handler(car, cout);
	handler.ExecutingCommand("EngineOn");
	handler.ExecutingCommand("SetGear -1");
	handler.ExecutingCommand("SetSpeed 10");
	REQUIRE(car.GetGear() == -1);
	REQUIRE(car.GetDirection() == -1);
	REQUIRE(car.GetSpeed() == 10);
	cout << "Start and go back is done\n\n";
}

SCENARIO("Cant change from -1 gear without stop")
{
	Car car;
	Handler handler(car, cout);
	handler.ExecutingCommand("EngineOn");
	handler.ExecutingCommand("SetGear -1");
	handler.ExecutingCommand("SetSpeed 10");
	handler.ExecutingCommand("SetGear 1");
	REQUIRE(car.GetGear() != 1);
	REQUIRE(car.GetGear() == -1);
	REQUIRE(car.GetDirection() == -1);
	REQUIRE(car.GetSpeed() == 10);
	cout << "Cant change from -1 gear without stop is done\n\n";
}

SCENARIO("Go to -1 gear then to neutral with save direction")
{
	Car car;
	Handler handler(car, cout);
	handler.ExecutingCommand("EngineOn");
	handler.ExecutingCommand("SetGear -1");
	handler.ExecutingCommand("SetSpeed 10");
	handler.ExecutingCommand("SetGear 0");
	REQUIRE(car.GetGear() == 0);
	REQUIRE(car.GetDirection() == -1);
	REQUIRE(car.GetSpeed() == 10);
	cout << "Go to -1 gear then to neutral with save direction is done\n\n";
}

SCENARIO("Cant change to -1 gear with forward direction")
{
	Car car;
	Handler handler(car, cout);
	handler.ExecutingCommand("EngineOn");
	handler.ExecutingCommand("SetGear 1");
	handler.ExecutingCommand("SetSpeed 10");
	handler.ExecutingCommand("SetGear 0");
	REQUIRE(car.GetDirection() == 1);
	handler.ExecutingCommand("SetGear -1");
	REQUIRE(car.GetGear() != -1);
	cout << "Cant change to -1 gear with forward direction is done\n\n";
}

SCENARIO("Cant change to -1 gear with back direction")
{
	Car car;
	Handler handler(car, cout);
	handler.ExecutingCommand("EngineOn");
	handler.ExecutingCommand("SetGear -1");
	handler.ExecutingCommand("SetSpeed 10");
	handler.ExecutingCommand("SetGear 0");
	REQUIRE(car.GetDirection() == -1);
	handler.ExecutingCommand("SetGear -1");
	REQUIRE(car.GetGear() != -1);
	cout << "Cant change to -1 gear with back direction is done\n\n";
}

SCENARIO("Switch from -1 gear to 1 gear with 0 speed")
{
	Car car;
	Handler handler(car, cout);
	handler.ExecutingCommand("EngineOn");
	handler.ExecutingCommand("SetGear -1");
	handler.ExecutingCommand("SetGear 1");
	REQUIRE(car.GetDirection() == 0);
	REQUIRE(car.GetGear() == 1);
	cout << "Switch from -1 gear to 1 gear with 0 speed is done\n\n";
}