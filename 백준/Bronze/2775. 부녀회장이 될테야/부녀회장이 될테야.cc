#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;


int getNum(int a, int b) {
    if (b == 1)
        return 1;
    if (a == 0)
        return b;
    return (getNum(a - 1, b) + getNum(a, b - 1));
}

int main() {
    FAST;
    int T, k, n;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> k >> n;
        cout << getNum(k, n) << '\n';
    }

    return 0;
}
