#include <iostream>
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int main()
{
    FAST;
    int n, k, index = 0;
    string input;
    cin >> n;
   
    int S[10001] = { 0, };
    
    for (int i = 0; i < n; i++) {
        cin >> input;
        if (input == "push") {
            cin >> k;
            S[index] = k;
            index++;
        }
        else if (input == "top") {
            if (index == 0) {
                cout << -1 << endl;
                continue;
            }
            cout << S[index - 1] << endl;
        }
        else if (input == "size") {
            cout << index << endl;
        }
        else if (input == "empty") {
            if (index == 0) {
                cout << 1 << endl;
            }
            else
                cout << 0 << endl;
        }
        else if (input == "pop") {
            if (index == 0) {
                cout << -1 << endl;
                continue;
            }
            cout << S[index - 1] << endl;
            index--;
        }
    }


    return 0;
}
