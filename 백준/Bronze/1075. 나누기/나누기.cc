#include <iostream>

using namespace std;

int N, F;

int main() {
    cin >> N >> F;

    for (int i = 0; i < 100; i++) {
        int temp_N = N / 100 * 100 + i;

        if (temp_N % F == 0) {
            if (i < 10)
                cout << 0;
            cout << i << endl;
            break;
        }
    }

    return 0;
}
