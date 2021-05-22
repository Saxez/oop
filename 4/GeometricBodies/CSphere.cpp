#include "CSphere.h"
#include <sstream>

using namespace std;

const double MyPI = 3.14;

CSphere::CSphere(double density, double radius): CBody("Sphere", density), m_radius(radius)
{

}

double CSphere::GetRadius()const
{
	return m_radius;
}

double CSphere::GetVolume()const
{
	return (pow(m_radius, 3) * MyPI) * 4 / 3;
}

void CSphere::AppendProperties(ostream& strm) const
{
	strm << "\nradius = " << " m^2" << GetRadius() << endl;
}