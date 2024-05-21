#include <iostream>
#include <string>
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

using namespace std;

// 10824

int main() {
    FAST;
    int input[4];
    for(int i = 0; i < 4; i++) {
        cin >> input[i];
    } 
    string temp = to_string(input[0]) + to_string(input[1]);
    string temp2 = to_string(input[2]) + to_string(input[3]);

    cout << stoll(temp) + stoll(temp2);

    return 0;
}