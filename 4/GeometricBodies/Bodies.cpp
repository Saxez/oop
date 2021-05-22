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

using namespace std;



void main()
{
    Handler handler(cout);
	string inp;
    while (getline(cin, inp))
    {
       handler.ExecutingCommand(inp);
        
    }
    handler.FindMaxMass();
    handler.FindMaxArchimed();
    handler.WriteInfo();
}