#include <iostream>
#include <vector>
#include <string>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;
int n, input;
vector<int> arr;

int main() {
    FAST;
    cin >> n;
    arr.push_back(1);
    arr.push_back(2);
    for (int i = 2; i < n; i++) {
        arr.push_back((arr[i - 2] + arr[i - 1]) % 10007);
    }

    cout << arr[n - 1];
    return 0;
}
