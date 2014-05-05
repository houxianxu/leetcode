/* http://oj.leetcode.com/problems/max-points-on-a-line/
 * Given n points on a 2D plane, find the maximum number of points that lie on the same straight line. */
	
 #include <iostream>
 #include <vector>
 #include <map>
 #include <cfloat> // :: FLT_MAX using for maximum slop
 using namespace std;


 // Definition for a point.
 struct Point {
     int x;
     int y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
 };
 
class Solution {
public:

	float computeSlop(vector<Point> &points, int i, int j) {
		float x1 = float(points[i].x);
		float y1 = float(points[i].y);
		float x2 = float(points[j].x);
		float y2 = float(points[j].y);

		if (x1 == x2) {
			return FLT_MAX;
		} else {
			return ((y1 - y2) / (x1 - x2));
		}
	}

	bool isSamePoint(vector<Point> &points, int i, int j) {
		return (points[i].x == points[j].x) && (points[i].y == points[j].y);
	}
	// compute the max points by given the ith point
	int maxPointsByFirst(vector<Point> &points, int i) {
		if (i == points.size() - 1) {
			return 1;
		}
		// the number of the same point 
		int numSame = 1; // include the point self
		map<float, int> slopMap; // store the slop
		for (int j = i + 1; j < points.size(); j++) {
			if (isSamePoint(points, i, j)) {
				numSame += 1;
				continue;
			} 
			float slop = computeSlop(points, i, j);
			if (slopMap.count(slop) == 1) {
				slopMap[slop] += 1;
			} else { // no slop in the map
				slopMap[slop] = 1;
			}
		}

		int res = 0;
		for (map<float, int>::iterator it = slopMap.begin(); it != slopMap.end(); it++) {
			if (it->second > res) {
				res = it->second;
			}
		}
		return res + numSame;
	}	

    int maxPoints(vector<Point> &points) {
    	if (points.size() <= 2) { return points.size(); }

    	int res = 0;
  		for (int i = 0; i < points.size(); i++) {
  			int tmpMax = maxPointsByFirst(points, i);
  			if (tmpMax > res) {
  				res = tmpMax;
  			}
  		}
  		return res;
    }
};

int main(int argc, char const *argv[])
{
	Solution ss;

	Point p1 = Point(1, 1);
	Point p2 = Point(0, 1);
	Point p3 = Point(2, 45);
	vector<Point> points;
	points.push_back(p1);
	points.push_back(p2);
	points.push_back(p3);
	cout << ss.maxPoints(points) << endl;
	return 0;
}