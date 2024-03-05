#include <iostream>
#include <string>
#include <list>
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int n;
list<int> result;
string input;

int main() {
    FAST;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> input;
        if (input == "push") {
            int temp;
            cin >> temp;
            result.push_back(temp);
        }
        else if (input == "pop") {
            if(result.empty()) 
                cout << "-1" << "\n";
            else { 
                cout << result.front() << "\n";
                result.pop_front();
            }
        }
        else if (input == "size") {
            cout << result.size() << "\n";
        }
        else if (input == "empty") {
            if(result.empty()) {
                cout << "1" << "\n";
            }
            else
                cout << "0" << "\n";
        }
        else if (input == "front") {
            if (result.empty())
                cout << "-1" << "\n";
            else 
                cout << result.front() << "\n";
        }
        else if (input == "back") {
            if (result.empty())
                cout << "-1" << "\n";
            else 
                cout << result.back() << "\n";
        }
    }
    
    return 0;
}
