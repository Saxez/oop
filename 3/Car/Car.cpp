#include "Car.h"
#include <iostream>
#include <map>

using namespace std;

Car::Car()
{
	m_isOn = false;
	m_dir = 0;
    m_gear = 0;
	m_speed = 0;
}

Car::~Car()
{

}

bool Car::TurnOnEngine()
{
	m_isOn = true;
	return true;
}

bool Car::TurnOffEngine()
{
	m_isOn = false;
	return true;
}

bool Car::SetGear(int gear)
{
	m_gear = gear;
	return true;
}

bool Car::SetSpeed(int speed)
{
	m_speed = speed;
	return true;
}

bool Car::IsTurnedOn() const
{
	return m_isOn;
}

int Car::GetDirection() const
{
	return m_dir;
}

int Car::GetSpeed() const
{
	return m_speed;
}

int Car::GetGear() const
{
	return m_gear;
}

bool Car::SetDirection(int dir)
{
	m_dir = dir;
	return true;
}