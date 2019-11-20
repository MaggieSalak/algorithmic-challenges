#include <iostream>
#include <vector>
using namespace std;
 
int main() {
	// your code goes here
	int n = 10000;
	vector<long long int> dp(n + 1, 0);
	dp[0] = 1;
	for (int i = 1; i <= 21; ++i) for (int j = 0; j <= n; ++j)
		if (j + i * i * i <= n)
			dp[j + i * i * i] += dp[j];
	while (cin >> n) {
		cout << dp[n] << endl;
	}
	return 0;
}
