#include "SphereInColor.h"
using namespace std;

SphereInColor::SphereInColor(Color initialColor): Sphere() {
	sphereColor = initialColor;
} // end of constructor

SphereInColor::SphereInColor(Color initialColor, double initialRadius): Sphere(initialRadius) {
	sphereColor = initialColor;
} // end of constructor

void SphereInColor::setColor(Color newColor) {
	sphereColor = newColor;
} // end of setColor

Color SphereInColor::getColor() const {
	return sphereColor;
} // end of getColor