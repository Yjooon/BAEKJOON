#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;
int n, m;
vector<int> arr;

int main() {
    FAST;
    int count = 0;
    cin >> n >> m;
    arr.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int mask = 0; mask < (1 << n); mask++) {
        int sum = 0;
        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                sum += arr[i];
                flag = true;
            }
        }

        if (sum == m && flag) {
            count++;
        }
    }

    cout << count;

    return 0;
}
