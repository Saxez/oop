#include "CCone.h"
#include <sstream>

using namespace std;

const double MyPI = 3.14;

CCone::CCone(double density, double baseRadius, double height) : CBody("Cone", density), m_baseRadius(baseRadius), m_height(height)
{

}

double CCone::GetBaseRadius() const
{
	return m_baseRadius;
}

double CCone::GetHeight() const
{
	return m_height;
}

double CCone::GetVolume() const
{
	return (1/3 * MyPI * GetBaseRadius() * GetHeight());
}

void CCone::AppendProperties(ostream& strm) const
{
	strm << "\nbase radius = " << GetBaseRadius() << " m^2" << "\nheight = " << " m" << GetHeight() << endl;
}