#include <iostream>
#include <vector>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

vector<int> josephusPermutation(int N, int K) {
    vector<int> permutation;
    vector<int> people;
    
    for (int i = 1; i <= N; ++i)
        people.push_back(i);

    int index = 0;
    while (!people.empty()) {
        index = (index + K - 1) % people.size();
        permutation.push_back(people[index]);
        people.erase(people.begin() + index);
    }

    return permutation;
}

int main() {
    FAST; 

    int N, K;
    cin >> N >> K;

    vector<int> result = josephusPermutation(N, K);

    cout << "<";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i < result.size() - 1)
            cout << ", ";
    }
    cout << ">";

    return 0;
}
