#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

long long a, b, c;


long long mod_pow(long long A, long long B, long long C) {
    long long result = 1;
    while (B > 0) {
        if (B % 2 == 1) {
            result = (result * A) % C;
        }
        A = (A * A) % C;
        B /= 2;
    }
    return result;
}

int main() {
	FAST;
	cin >> a >> b >> c;

    long long result = mod_pow(a, b, c);

    

	cout << result;
    return 0;
}