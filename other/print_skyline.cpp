#include <iostream>
#include <set>
#include <vector>
using namespace std;
 
struct Point {
	int x; 
	int y;
	bool beg;
	Point(int x1, int y1, bool b) : x(x1), y(y1), beg(b) {}
};
 
void print_skyline(const vector<Point>& v) {
	multiset<int> s;
	s.insert(0);
	int level = 0;
	for (auto pt: v) {
		if (pt.beg) {
			s.insert(pt.y);
			if (level < pt.y) {
				level = pt.y;
				cout << "(" << pt.x << "," << pt.y << ")" << endl;
			}
		} else {
			s.erase(pt.y);
			int high = *s.rbegin();
			if (level != high) {
				level = high;	
				cout << "(" << pt.x << "," << level << ")" << endl; 
			}
 
		}
	}
}
 
int main() {
	// your code goes here
	Point p1(2, 10, true); Point p2(3, 15, true); Point p3(5, 12, true);
	Point p4(7, 15, false); Point p5(9, 10, false); Point p6(12, 12, false);
	Point p7(15, 10, true); Point p8(19, 8, true); Point p9(20, 10, false); Point p10(24, 8, false);
	vector<Point> v = {p1, p2, p3, p4, p5, p6, p7, p8, p9, p10};
	print_skyline(v);
	return 0;
}
