#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;
int n, m;
string input;
vector<int> arr(20);
vector<int> result;

int main() {
    FAST;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> input;
        if (input == "add") {
            cin >> m;
            arr[m - 1] = 1;
        }
        else if (input == "remove") {
            cin >> m;
            arr[m - 1] = 0;
        }
        else if (input == "check") {
            cin >> m;
            if (arr[m - 1] == 1)
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }        
        else if (input == "toggle") {
            cin >> m;
            if (arr[m - 1] == 1)
                arr[m - 1] = 0;
            else
                arr[m - 1] = 1;
        }
        else if (input == "all") {
            for (int i = 0; i < 20; i++) {
                arr[i] = 1;
            }
        }
        else if (input == "empty") {
            for (int i = 0; i < 20; i++) {
                arr[i] = 0;
            }
        }
    }

    return 0;
}
