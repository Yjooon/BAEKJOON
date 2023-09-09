#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;
int n, m, num;

vector<int> result;

int main() {
    FAST;
    cin >> n >> m;
    for (int i = 0; i < n + m; i++) {
        cin >> num;
        result.push_back(num);
    }
    sort(result.begin(), result.end());
    for (int k : result) {
        cout << k << " ";
    }
   

    return 0;
}

