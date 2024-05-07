#include <iostream>
#include <string>
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

using namespace std;

int main() {
    FAST;
    string input;
    getline(cin, input);

    int index = 0;

    while(index < input.length()) {
        if (input[index] == ' ') {
            cout << ' ';
            index++;
            continue;
        }
        else if (input[index] == '<') { // 안 뒤집기
            while(index < input.length() && input[index] != '>') {
                cout << input[index];
                index++;
            }
            cout << input[index]; // ">"
            index++;
            continue;
        }
        else {  // 뒤집기
            int start = index;
            while(index < input.length() && input[index] != ' ' && input[index] != '<') {
                index++;
            }
            for (int i = index - 1; i >= start; i--) {
                cout << input[i];
            }
            continue;
        }
    }

    return 0;
}
