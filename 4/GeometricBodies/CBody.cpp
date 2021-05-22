#include "CBody.h"
#include <sstream>
using namespace std;

CBody::CBody(const string type, double density): m_density(density) ,m_type(type)
{

}

double CBody::GetDensity()const
{
	return m_density;
}

double CBody::GetMass()const
{
	return GetVolume() * GetDensity();
}

string CBody::ToString()const
{
	ostringstream strm;
	strm << m_type << ":"
		 << "\ndensity = " << GetDensity() << " kg/m^3"<< endl
		 << "\nvolume = "  << GetVolume()  << " m^3"   << endl
		 << "\nmass = "    << GetMass()    << " m"     << endl;
	AppendProperties(strm);
	return strm.str();
}