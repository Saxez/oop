#pragma once
#include "CBody.h"
#include <iostream>
#include <istream>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include <map>
#include <regex>

using namespace std;

class Handler
{
public:
	Handler(ostream& output);

	bool ExecutingCommand(string command);
	void WriteInfo();
	void FindMaxMass();
	void FindMaxArchimed();
private:
	void HandleParallepiped(string inp);
	void HandleSphere(string inp);
	void HandleCylinder(string inp);
	void HandleCone(string inp);

	vector <int> m_masses;
	vector <unique_ptr<CBody>> m_store;
	ostream& m_output;
};

