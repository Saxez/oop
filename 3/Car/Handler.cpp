#include "Handler.h"
#include "Car.h"
#include "Processing.h"
#include <string>
#include <regex>
#include <map>

using namespace std;

regex  const REGULAR("([a-zA-Z]+) ([-0-9]+)");
map<string, int> COMMAND_LIST_WITHOUT_VALUE = { {"Info",      1},
												{"EngineOn",  2},
												{"EngineOff", 3} };

map<string, int> COMMAND_LIST_WITH_VALUE = { {"SetSpeed", 1},
											 {"SetGear",  2} };

string const DIR_FRONT = "dirrection is front \n";
string const DIR_BACK = "dirrection is back \n";
string const STAY = "car staying \n";
string const CUR_SPEED = "\ncurrent speed: ";
string const CUR_GEAR = "current gear: ";

string const ENGINE_ON = "engine is on\n";
string const ENGINE_OFF = "engine is off\n";
string const ENGINE_OFF_ERROR = "you cant off engine\n";
string const GEAR_NOT_EXIST = "this gear doesn\'t exist\n";
string const SUC_CHANGE_GEAR = "succcesfull change gear\n";
string const NOT_SITUABLE_SPEED = "the speed is not suitable for this gear\n";
string const CHANGE_ZERO_GEAR = "can\'t change from 0 gear with speed > 0\n";
string const SUC_CHANGE_SPEED = "succcesfull change speed\n";
string const NOT_SUC_CHANGE_SPEED = " not succcesfull change speed\n";
string const ERROR_CHANGE_SPEED = "you can\'t change the speed to higher than it is now in neutral gear\n";
string const ERROR_BIG_SPEED = "because new speed too big for this gear\n";
string const ERROR_SMALL_SPEED = "because new speed too small for this gear\n";
string const ERROR_SPEED = "bad speed for it";

int    const ZERO_SPEED = 0;
int	   const PLUS_SPEED = 1;
int	   const MINUS_SPEED = -1;

int    const ZERO_GEAR = 0;
int	   const PLUS_GEAR = 1;
int	   const MINUS_GEAR = -1;

int    const ZERO_DIR = 0;
int	   const PLUS_DIR = 1;
int	   const MINUS_DIR = -1;


Handler::Handler(Car& car, ostream& output) : m_car(car), m_output(output)
{

}


bool Handler::SplitCommand(const string& line, int& param, string& command)
{
	cmatch result;

	if (regex_match(line.c_str(), result, REGULAR))
	{
		param = stoi(result[2]);
		command = result[1]; 
		return true;
	}
	return false;
}

bool Handler::ChangeSpeed(int speed)
{
	if (CheckSpeed(speed, m_car.GetGear()) || ((m_car.GetGear() == ZERO_GEAR) && (speed < m_car.GetSpeed())))
	{
		if (speed == ZERO_SPEED)
		{
			m_car.SetDirection(ZERO_DIR);
		}
		else
		{
			if (m_car.GetGear() == MINUS_GEAR)
			{
				m_car.SetDirection(MINUS_DIR);
			}
			else
			{
				m_car.SetDirection(PLUS_DIR);
			}
		}
		cout << SUC_CHANGE_SPEED;
		m_car.SetSpeed(speed);
		return true;
	}
	else if (m_car.GetGear() == ZERO_GEAR)
	{
		cout << ERROR_CHANGE_SPEED;
		return false;
	}
	else
	{
		cout << NOT_SUC_CHANGE_SPEED;
		cout << ERROR_SPEED;
		return false;
	}
}

bool Handler::ChangeGear(int gear)
{
	if (!CheckGearOnExsit(gear))
	{
		cout << GEAR_NOT_EXIST;
		return false;
	}
	if (!m_car.IsTurnedOn())
	{
		cout << ENGINE_OFF;
		return false;
	}

	if ((gear > ZERO_GEAR) && (m_car.GetGear() > ZERO_GEAR))
	{
		if (CheckSpeed(m_car.GetSpeed(), gear))
		{
			m_car.SetGear(gear);
			cout << SUC_CHANGE_GEAR;
			return true;
		}
		else
		{
			cout << NOT_SITUABLE_SPEED;
			return false;
		}
	}
	else if ((m_car.GetGear() == MINUS_GEAR) && (gear == PLUS_GEAR) && (m_car.GetSpeed() == ZERO_SPEED))
	{
		m_car.SetGear(gear);
		cout << SUC_CHANGE_GEAR;
		return true;
	}
	else if ((m_car.GetGear() == MINUS_GEAR || m_car.GetGear() == PLUS_GEAR) && (gear == ZERO_GEAR))
	{
		m_car.SetGear(gear);
		cout << SUC_CHANGE_GEAR;
		return true;
	}
	else if ((m_car.GetGear() > ZERO_GEAR) && (gear == ZERO_GEAR))
	{
		m_car.SetGear(gear);
		cout << SUC_CHANGE_GEAR;
		return true;
	}
	else if (((gear == PLUS_GEAR) || (gear == MINUS_GEAR)) && m_car.GetGear() == ZERO_GEAR)
	{
		if ((m_car.GetSpeed() != ZERO_SPEED) && (m_car.GetGear() == ZERO_GEAR))
		{
			cout << CHANGE_ZERO_GEAR;
			return false;
		}
		else
		{
			m_car.SetGear(gear);
			cout << SUC_CHANGE_GEAR;
			return true;
		}
	}
	cout << "can\'t change from " << m_car.GetGear() << " gear to " << gear << " gear with speed: " << m_car.GetSpeed() << endl;
	return false;
}

bool Handler::FullInfo()
{
	if (m_car.IsTurnedOn())
	{
		cout << ENGINE_ON;
	}
	else
	{
		cout << ENGINE_OFF;
	}

	switch (m_car.GetDirection())
	{
	case 1:
		cout << DIR_FRONT;
		break;
	case -1:
		cout << DIR_BACK;
		break;
	case 0:
		cout << STAY;
	}

	cout << CUR_GEAR << to_string(m_car.GetGear());
	cout << CUR_SPEED << to_string(m_car.GetSpeed()) << endl;
	return true;
}

bool Handler::EngineOff()
{
	if ((!m_car.IsTurnedOn()) || ((m_car.IsTurnedOn()) && (m_car.GetSpeed() == ZERO_SPEED) && (m_car.GetGear() == ZERO_GEAR)))
	{
		cout << ENGINE_OFF;
		m_car.TurnOffEngine();
		return true;
	}
	cout << ENGINE_OFF_ERROR;
	return false;
}

bool Handler::EngineOn()
{
	cout << ENGINE_ON;
	m_car.TurnOnEngine();
	return true;
}

bool Handler::UseCommand(const string command, const int value)
{
	switch (COMMAND_LIST_WITH_VALUE[command])
	{
	case 1:
		Handler::ChangeSpeed(value);
		break;
	case 2:
		Handler::ChangeGear(value);
		break;
	default:
		ErrorCommand();
	}

	return true;
}

bool Handler::UseCommand(const string command)
{
	switch (COMMAND_LIST_WITHOUT_VALUE[command])
	{
	case 1:
		Handler::FullInfo();
		break;
	case 2:
		Handler::EngineOn();
		break;
	case 3:
		Handler::EngineOff();
		break;
	default:
		ErrorCommand();
	}

	return true;
}

bool Handler::ExecutingCommand(string command)
{
	DelSpaces(command);
	if (command.find(' ') == string::npos)
	{
		UseCommand(command);
	}
	else
	{
		int value = 0;
		SplitCommand(command, value, command);
		UseCommand(command, value);
	}
	return true;
}