#include <iostream>
#include <algorithm>
#include <vector>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

const int MOD = 1000000000;

int main() {
    FAST;
    int N;
    cin >> N;

    vector<vector<int>> dp(N + 1, vector<int>(10, 0));

    for (int i = 1; i <= 9; i++) {
        dp[1][i] = 1;
    }

    for (int length = 2; length <= N; length++) {
        for (int digit = 0; digit <= 9; digit++) {
            if (digit - 1 >= 0) {
                dp[length][digit] += dp[length - 1][digit - 1];
                dp[length][digit] %= MOD;
            }
            if (digit + 1 <= 9) {
                dp[length][digit] += dp[length - 1][digit + 1];
                dp[length][digit] %= MOD;
            }
        }
    }

    int totalCount = 0;
    for (int i = 0; i <= 9; i++) {
        totalCount += dp[N][i];
        totalCount %= MOD;
    }

    cout << totalCount << endl;

    return 0;
}
