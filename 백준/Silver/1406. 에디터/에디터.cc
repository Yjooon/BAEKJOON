#include <iostream>
#include <string>
#include <list>
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int n;
list<char> result;
string input;
char order, temp;
list<char>::iterator cursor;

int main() {
    FAST;
    cin >> input;
    for (int i = 0; i < input.size(); i++) {
        result.push_back(input[i]);
    }
    cursor = result.end();  // 커서를 맨 끝으로 초기화

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> order;
        switch (order) {
            case 'L':
                if (cursor != result.begin())
                    cursor--;
                break;
            case 'D':
                if (cursor != result.end())
                    cursor++;
                break;
            case 'B':
                if (cursor != result.begin()) {
                    cursor = result.erase(--cursor);
                }
                break;
            case 'P':
                cin >> temp;
                result.insert(cursor, temp);
                break;
            default:
                break;
        }
    }

    for (auto it = result.begin(); it != result.end(); ++it) {
        cout << *it;
    }
    cout << "\n";

    return 0;
}
