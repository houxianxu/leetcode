/* using Sphere as base class */
#include "Sphere.h" 
enum Color { RED, BLUE, GREEN, YELLOW };
class SphereInColor: public Sphere {
private:
	Color sphereColor;

public:
	/* constructor */
	SphereInColor(Color initialColor);

	SphereInColor(Color initialColor, double initialRadius);

	void setColor(Color newColor);

	Color getColor() const;
}; // end of SphereInColor class
