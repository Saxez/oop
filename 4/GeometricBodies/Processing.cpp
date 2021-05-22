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

using namespace std;

string const ERROR_BODY = "This body doesnt exist\n";
regex  const REGULAR("([a-zA-Z]+)([0-9 ])+");

void ErrorBody()
{
	cout << ERROR_BODY;
}



string FindBody(const string line)
{
	cmatch result;

	regex_match(line.c_str(), result, REGULAR);
	return result[1];
}