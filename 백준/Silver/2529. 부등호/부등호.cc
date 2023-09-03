#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
int n;
vector<string> inequality(n);
vector<int> num;
vector<int> temp;
string result_big, result_small;
bool find_min = false, find_big = false;

void backtrack_min() {
    if (find_min)
        return;

    if (temp.size() == inequality.size() + 1) {
        for (int i : temp) {
            result_small += to_string(i);
        }        
        find_min = true;
        return;
    }    

    for (int i = 0; i < 10; i++) {
        bool flag = false;
        for (int k : temp) {
            if (num[i] == k)
                flag = true;
        }
        if (flag)
            continue;

        if (temp.size() > 0) {
            if (inequality[temp.size() - 1] == ">") {
                if (temp[temp.size() - 1] < num[i])
                    continue;
            }
            else {
                if (temp[temp.size() - 1] > num[i])
                    continue;
            }
        }

        temp.push_back(num[i]);
        backtrack_min();
        temp.pop_back();
    }
}

void backtrack_big() {
    if (find_big)
        return;

    if (temp.size() == inequality.size() + 1) {
        for (int i : temp) {
            result_big += to_string(i);
        }
        find_big = true;
        return;
    }

    for (int i = 9; i >= 0; i--) {
        bool flag = false;
        for (int k : temp) {
            if (num[i] == k)
                flag = true;
        }
        if (flag)
            continue;

        if (temp.size() > 0) {
            if (inequality[temp.size() - 1] == ">") {
                if (temp[temp.size() - 1] < num[i])
                    continue;
            }
            else {
                if (temp[temp.size() - 1] > num[i])
                    continue;
            }
        }

        temp.push_back(num[i]);
        backtrack_big();
        temp.pop_back();
    }
}


int main() {
    FAST;

    for (int i = 0; i < 10; i++)
        num.push_back(i);

    cin >> n;
    inequality.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> inequality[i];
    }   

    backtrack_min();
    backtrack_big();

    cout << result_big << "\n" << result_small;
   
    return 0;
}
