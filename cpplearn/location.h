class Location
{
public:
	Location(int xVal, int yVal);
	int getX();
	int getY();
	void translate(int x, int y);

private:
	int x, y;
};