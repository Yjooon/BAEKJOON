#include <iostream>
#include <vector>
#include <algorithm>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
long double n, m;

int main() {
    FAST;
    cin >> n >> m;
    cout.precision(9);
    cout << fixed;
    cout << n / m;
   
    return 0;
}
