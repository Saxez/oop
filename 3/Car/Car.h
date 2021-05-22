#pragma once


class Car
{
public:

	Car();
	~Car();
	bool TurnOnEngine();
	bool TurnOffEngine();

	bool SetGear(int gear);
	bool SetSpeed(int speed);
	bool SetDirection(int dir);

	bool IsTurnedOn() const;
	int  GetDirection() const;
	int  GetSpeed() const;
	int  GetGear() const;

private:
	bool m_isOn;
	int  m_dir;
	int  m_gear;
	int  m_speed;
	
};