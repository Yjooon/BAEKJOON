#include <iostream>
#include <vector>
#include <cmath>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

using namespace std;

// 1748

int main() {
    FAST;

    int input;
    cin >> input;

    int result;

    //1~9 
    //10~99
    //100~999
    //log 값이 0 = 1~9 = output: 1 * (input - 0)
    //log 값이 1 = 10~99 = ou5tput: 9 + 2 * (input - 10)
    //log 값이 2 = 100~999 = output: 9 + 2 * (99 - 10) + 3 * (input - 100)

    //9 + 90 * 2 + 900 * 3 + 9000 * 4
    // 

    if (int(log10(input)) > 0) {
        int inputLog = log10(input);
        result = (inputLog + 1) * (input - int(pow(10, inputLog)) + 1);

        int temp = 0;
        while(inputLog > 0) {
            temp += 9 * int(pow(10, inputLog - 1)) * inputLog;
            inputLog--;
        }
        cout << temp + result;
    }
    else {
        cout << input;
    }


    return 0;
}
