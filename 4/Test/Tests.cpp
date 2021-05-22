#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"

#include "../GeometricBodies/CBody.h"
#include "../GeometricBodies/CSphere.h"
#include "../GeometricBodies/CCylinder.h"
#include "../GeometricBodies/CCone.h"
#include "../GeometricBodies/CParallepiped.h"

#include <string>
#include <sstream>



SCENARIO("Test valid sphere creation")
{
	CSphere sphere(10, 10);
	REQUIRE(sphere.GetDensity() == 10);
	REQUIRE(sphere.GetRadius() == 10);
	cout << "Test valid sphere creation is done\n";
}

SCENARIO("Test valid cone creation")
{
	CCone cone(10.1, 10.2, 10.3);
	REQUIRE(cone.GetDensity() == 10.1);
	REQUIRE(cone.GetBaseRadius() == 10.2);
	REQUIRE(cone.GetHeight() == 10.3);
}

SCENARIO("Test valid cylinder creation")
{
	CCylinder cylinder(10.1, 10.2, 10.3);
	REQUIRE(cylinder.GetDensity() == 10.1);
	REQUIRE(cylinder.GetBaseRadius() == 10.2);
	REQUIRE(cylinder.GetHeight() == 10.3);
}

SCENARIO("Test valid parallelepiped creation")
{
	CParallepiped paral(10.1, 10.2, 10.3, 10.4);
	REQUIRE(paral.GetDensity() == 10.1);
	REQUIRE(paral.GetDepth() == 10.4);
	REQUIRE(paral.GetWidth() == 10.2);
	REQUIRE(paral.GetHeight() == 10.3);
}