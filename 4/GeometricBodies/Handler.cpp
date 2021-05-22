#include "Handler.h"

#include "Processing.h"
#include "CCone.h"
#include "CBody.h"
#include "CCylinder.h"
#include "CParallepiped.h"
#include "CSphere.h"
#include <iostream>
#include <istream>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include <map>
#include <regex>
#include <typeinfo>	
using namespace std;


map<string, int> CASE_INP = { {"cylinder", 1},
                               {"cone", 2},
                               {"parallepiped", 3},
                               {"sphere", 4} };

int const DEN_WATER = 1000;
double const G = 9.8;

string const MIN_ARCHIMED = "Body it is easiest to weigh when fully submerged in water: ";

string const MAX_MASS_BODY = "Body with max mass: ";

vector <string> BODIES = { "cylinder", "cone", "parallepiped", "sphere" };

Handler::Handler(ostream& output) : m_output(output)
{

}

void Handler::HandleSphere(string inp)
{
	stringstream str(inp);
	double den;
	double rad;
	str >> den;
	str >> rad;
	m_store.push_back(make_unique<CSphere>(den, rad));
}

void Handler::HandleCone(string inp)
{
	stringstream str(inp);
	double den;
	double rad;
	double height;
	str >> den;
	str >> rad;
	str >> height;
	m_store.push_back(make_unique<CCone>(den, rad, height));
}

void Handler::HandleCylinder(string inp)
{
	stringstream str(inp);
	string name;
	double den;
	double rad;
	double height;
	str >> name;
	str >> den;
	str >> rad;
	str >> height;
	m_store.push_back(make_unique<CCylinder>(den, rad, height));
}

void Handler::HandleParallepiped(string inp)
{
	stringstream str(inp);
	double den;
	double height;
	double width;
	double depth;
	str >> den;
	str >> width;
	str >> height;
	str >> depth;
	m_store.push_back(make_unique<CParallepiped>(den, width, height, depth));
}


bool Handler::ExecutingCommand(string input)
{
	if (find(BODIES.begin(), BODIES.end(), FindBody(input)) != BODIES.end())
	{
		switch (CASE_INP[FindBody(input)])
		{
		case (1):
			HandleCylinder(input);
			break;
		case (2):
			HandleCone(input);
			break;
		case(3):
			HandleParallepiped(input);
			break;
		case (4):
			HandleSphere(input);
			break;
		}
	}
	else
	{
		ErrorBody();
		return false;
	}
}

void Handler::WriteInfo()
{
	for (auto& item : m_store)
	{
		cout << item->ToString() << endl << endl;
	}
}

void Handler::FindMaxMass()
{
	double maxMass = 0;
	string info;
	for (auto& item : m_store)
	{
		if (item->GetMass() > maxMass)
		{
			maxMass = item->GetMass();
			info = item->ToString();
		}
	}
	cout << MAX_MASS_BODY << info << endl;
}

void Handler::FindMaxArchimed()
{
	double maxArchimed = DBL_MAX;
	string info;
	for (auto& item : m_store)
	{
		double m_water = (item->GetDensity() - DEN_WATER) * G * item->GetVolume();

			if ((m_water) < maxArchimed)
			{
				maxArchimed = (item->GetDensity() - DEN_WATER) * G * item->GetVolume();
				info = item->ToString();
			}
	}
	cout << MIN_ARCHIMED << info << endl << endl;
}