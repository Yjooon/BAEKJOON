#include <iostream>
#include <algorithm>
#include <vector>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;
int n;
vector<int> T;
vector<int> P;
vector<int> dp(n + 1);

int main(void) {
	FAST;
	cin >> n;
	T.resize(n);
	P.resize(n);
	dp.resize(n + 1);

	for (int i = 0; i < n; i++) {
		cin >> T[i] >> P[i];
	}

	for (int i = n - 1; i >= 0; i--) {
		int nextDay = i + T[i];
		if (nextDay > n) {
			dp[i] = dp[i + 1];
		}
		else {
			dp[i] = max(dp[i + 1], P[i] + dp[nextDay]);
		}
	}

	cout << dp[0] << "\n";

	return 0;
}