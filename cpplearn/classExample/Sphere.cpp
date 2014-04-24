/* @file Sphere.cpp */
#include "Sphere.h"
#include <iostream>
using namespace std;

Sphere::Sphere() {
	theRadius = 1.0;
} // end of default construct

Sphere::Sphere(double initialRadius) {
	setRadius(initialRadius); // Sphere not needed here
}// end of construct

void Sphere::setRadius(double newRadius) {
	if (newRadius > 0) {
		theRadius = newRadius;
	} else {
		theRadius = 1.0;
	}
} // end of setRadius

double Sphere::getRadius() const {
	return theRadius;
}// end of getRadius

double Sphere::getDiameter() const {
	return 2.0 * theRadius;
} // end of getDiameter

double Sphere::getCircumference() const {
	return PI * getDiameter();
} // end of getCircumference

double Sphere::getArea() const {
	return 4 * PI * theRadius * theRadius;
} // end of getArea

double Sphere::getVolume() const {
	double radiusCubed = theRadius * theRadius * theRadius;
	return (4.0 * PI * radiusCubed) / 3.0;
} // end of getVolume

void Sphere::displayStat() const {
	cout << "theRadius: " << getRadius() << endl;
	cout << "getDiameter: " << getDiameter() << endl;
	cout << "getCircumference: " << getCircumference() << endl;
	cout << "getArea: " << getArea() << endl;
	cout << "getVolume: " << getVolume() << endl;
}
// end of implementation file.
