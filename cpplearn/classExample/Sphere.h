// This demo comes form the book Data Abstraction & Problem Soloving with C++
// I just use it to learn C++

/* @file Sphere.h*/
const double PI = 3.1415926;


/* Definition of a class of Spheres */
class Sphere {
private:
	double theRadius; // the sphere's radius

public:
	/* Default constructor: creates a sphere and initializes the radius with a default value. 
	 * None para */
	Sphere();

	/* constructor: with a desired radius 
	 * @para: double */
	Sphere(double initialRadius);

	/* Set the sphere's radius, change to new value
	 * @para: double
	 * @return: none */
	void setRadius(double newRadius);

	/* Get the sphere's radius 
	 * @para: none 
	 * @return: double - the sphere's radius */
	double getRadius() const;

	/* Get the sphere's diameter 
	 * @para: none 
	 * @return: double - the sphere's diameter */
	double getDiameter() const;

	/* Get the sphere's circumference
	 * @para: none, using PI
	 * @return double */
	double getCircumference() const;

	/* Get the sphere's area 
	 * @para: none; Using PI 
	 * @return: double */
	double getArea() const;

	/* Get the sphere's volume 
	 * @para: none: using PI
	 * @return double */
	double getVolume() const;

	/* display the statistic
	 * @para: none 
	 * @return none -- print out all the statistics */
	void displayStat() const;
	
}; // end of Sphere
// endof header file