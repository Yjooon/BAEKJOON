#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;
int n, m;
vector<int> arr;
vector<int> result;


void isNum(int num, int start, int end) {    
    if (end == start) {
        if (arr[start] == num)
            result.push_back(1);
        else
            result.push_back(0);
        return;
    }

    if (num > arr[(start + end) / 2]) { // 절반 위 
        isNum(num, (start + end) / 2 + 1, end);
        return;
    }
    else { //절반 아래
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
    int input = 0;
    for (int i = 0; i < m; i++) {
        cin >> input;
        isNum(input, 0, n - 1);
    }

    for (int i : result) {
        cout << i << " ";
    }

    return 0;
}

