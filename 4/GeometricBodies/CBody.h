#pragma once
#include <string>

using namespace std;

class CBody
{
public:
	CBody(const string type, double density);
	double GetDensity() const;
	double GetMass() const;
	string ToString() const;
	virtual double GetVolume() const = 0;

private:
	double m_density;
	string m_type;
	virtual void AppendProperties(ostream& strm) const = 0;
};