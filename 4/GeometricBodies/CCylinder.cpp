#include "CCylinder.h"
#include <sstream>

using namespace std;

const double MyPI = 3.14;

CCylinder::CCylinder(double density, double baseRadius, double height) : CBody("Cylinder", density), m_baseRadius(baseRadius), m_height(height)
{

}

double CCylinder::GetBaseRadius() const
{
	return m_baseRadius;
}

double CCylinder::GetHeight() const
{
	return m_height;
}

double CCylinder::GetVolume() const 
{
	return (MyPI * GetBaseRadius() * GetHeight());
}

void CCylinder::AppendProperties(ostream& strm) const
{
	strm << "\nbase radius = " << GetBaseRadius() << " m^2" << "\nheight = " << " m" << GetHeight() << endl;
}