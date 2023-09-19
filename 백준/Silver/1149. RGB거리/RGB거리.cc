#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;
int n, index;
int house[1001][3];
int dp[1001][3];


int main() {
    FAST;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> house[i][0] >> house[i][1] >> house[i][2];
    }
    dp[1][0] = house[1][0];
    dp[1][1] = house[1][1];
    dp[1][2] = house[1][2];
    for (int i = 2; i <= n; i++) {
        dp[i][0] = house[i][0] + min(dp[i - 1][1], dp[i-1][2]);
        dp[i][1] = house[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = house[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
    }
    
    cout << min(dp[n][0], min(dp[n][1], dp[n][2]));

    
    return 0;
}
