#include <iostream>
#include <vector>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

int main() {
    FAST; 

    int n;
    cin >> n;

    int result = 1;
    for(int i = n; i > 1; i--) {
        result *= i;
    }

    cout << result;
    return 0;
}
