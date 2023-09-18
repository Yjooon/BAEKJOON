#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;
int n, result = 0;
vector<int> arr;
vector<int> dp(100001);

bool isPower(int num) {
    if ((int)pow((int)sqrt(num), 2) == num)
        return true;
    else
        return false;    
}

int main() {
    FAST;    
    cin >> n;
    dp[0] = 0;
    dp[1] = 1; // 1


    int temp = 0;
    for (int i = 2; i <= n; i++) {
        if (isPower(i)) {
            dp[i] = 1;
            continue;
        }
        dp[i] = 5;
        for (int j = 0; j <= (int)sqrt(i) / 2; j++) {
            if (dp[i] > dp[i - (int)pow((int)sqrt(i) - j, 2)] + dp[(int)pow((int)sqrt(i) - j, 2)])
                dp[i] = dp[i - (int)pow((int)sqrt(i) - j, 2)] + dp[(int)pow((int)sqrt(i) - j, 2)];
        }   
    }


    cout << dp[n];

    return 0;
}
