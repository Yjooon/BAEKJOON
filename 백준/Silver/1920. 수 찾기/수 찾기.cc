#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;
int n, m;

vector<int> arr;
vector<int> arr2;
vector<int> result;

void isNum(int num, int start, int end) {
    if (start == end) {
        if (arr[start] == num)
            result.push_back(1);
        else
            result.push_back(0);
        return;
    }

    if (num > arr[(start + end) / 2]) {
        isNum(num, (start + end) / 2 + 1, end);
        return;
    }
    else {
        isNum(num, start, (start + end) / 2);
        return;
    }
}

int main() {
    FAST;
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    cin >> m;
    arr2.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
        isNum(arr2[i], 0, n - 1);
    }

    for (int i : result) {
        cout << i << "\n";
    }

    return 0;
}

