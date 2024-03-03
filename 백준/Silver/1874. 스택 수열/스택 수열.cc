#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <set>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int n;

int m = 0;

int num = 1;

vector<int> arr;
set<int> poppedNumbers;

stack<int> s;
vector<char> result;

bool flag = false;

void spush() {
    s.push(num);
    num++;
    result.push_back('+');
}

void spop() {
    poppedNumbers.insert(s.top());
    s.pop();
    result.push_back('-');
}

int main() {
    FAST;
    cin >> n;

    arr.resize(n);

    set<int> seen;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        if (poppedNumbers.find(arr[i]) != poppedNumbers.end()) {
            flag = true;
        }
        if (flag)
            break;
        if (i == 0) {
            for (int j = 0; j < arr[i]; j++) {
                spush();
            }
            spop();
        }
        else {
            if (arr[i - 1] > arr[i]) {
                while (s.size() != 0 && arr[i] <= s.top()) {
                    spop();
                }
            }
            else {
                if (s.empty()) {
                    spush();
                }

                while (s.size() != 0 && arr[i] > s.top()) {
                    spush();
                }
                spop();
            }
        }
    }
    if (flag)
        cout << "NO" << "\n";
    else {
        for (char i : result) {
            cout << i << "\n";
        }
    }
    return 0;
}