#include <iostream>
#include <string>
#include <stack>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int n;
string str;

stack<int> s;
bool flag;

int main() {
    FAST;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        while (!s.empty()) {
            s.pop();
        }

        getline(cin, str);
        for (int j = 0; j < str.length(); j++) {
            if (str[j] == '(') {
                s.push(1);
            }
            else if (str[j] == ')' && !s.empty()) {
                s.pop();
            }
            else if (str[j] == ')' && s.empty()) {
                cout << "NO\n";
                flag = true;
                break;
            }
        }
        if (flag) {
            flag = false;
            continue;
        }
        if (s.empty())
            cout << "YES\n";
        else
            cout << "NO\n";        
    }

    return 0;
}