#include <iostream>
#include <vector>
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

using namespace std;

// 15988

int main() {
    FAST;

    int T;
    vector<long long> input;
    cin >> T;
    input.resize(T);

    for(int i = 0; i < T; i++) {
        cin >> input[i];
    }

    vector<int> dp(1000001);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i = 4; i < 1000001; i++) {
        dp[i] = ((dp[i-1] + dp[i-2]) % 1000000009 + dp[i-3]) % 1000000009;
    }

    for(int i = 0; i < T; i++) {
        cout << dp[input[i]] << "\n";
    }

    return 0;
}
