#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
 
int main() {
	// your code goes here
	int digits;
	while (cin >> digits) {
		int lim = pow(10, digits);
		for (int n = 0; n < lim; ++n) {
			string s = to_string(n);
			reverse(s.begin(), s.end());
			while (s.size() < digits)
				s += "0";
			reverse(s.begin(), s.end());
			string part1 = s.substr(0, digits/2);
			string part2 = s.substr(digits/2, digits);
			int n1 = stoi(part1);
			int n2 = stoi(part2);
			if (pow((n1 + n2), 2) == n)
				cout << s << endl;
		} 
	}
	return 0;
}
