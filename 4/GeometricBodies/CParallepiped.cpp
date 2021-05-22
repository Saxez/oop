#include "CParallepiped.h"
#include <sstream>

using namespace std;

CParallepiped::CParallepiped(double density, double width, double height, double depth) : CBody("Parallepiped", density), m_width(width),
																						  m_height(height), m_depth(depth)
{

}

double CParallepiped::GetWidth() const
{
	return m_width;
}

double CParallepiped::GetHeight() const
{
	return m_height;
}

double CParallepiped::GetDepth() const
{
	return m_depth;
}
double CParallepiped::GetVolume() const
{
	return ( m_depth * m_height * m_width);
}

void CParallepiped::AppendProperties(ostream& strm) const
{
	strm << "\nwidth = " << GetWidth() << " m" << "\nheight = " << GetHeight() << " m" << "\ndepth = " << GetDepth() << "m" << endl;
}