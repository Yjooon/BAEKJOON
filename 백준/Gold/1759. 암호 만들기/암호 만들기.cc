#include <iostream>
#include <algorithm>
#include <vector>
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL) 

using namespace std;
int l, c;
vector<string> arr;
vector<string> temp;
vector<int> index;
int vowels = 0, consonants = 0;

void backtrack() {
	if (temp.size() == l) {
		for (string i : temp) {
			if (i == "a" || i == "e" || i == "i" || i == "o" || i == "u") {
				vowels++;
			}
			else
				consonants++;
		}

		if (vowels >= 1 && consonants >= 2) {
			for (string i : temp) {
				cout << i;
			}
			cout << "\n";
		}

		vowels = 0; consonants = 0;
		return;
	}

	for (int i = 0; i < c; i++) {
		if (index.size() > 0 && i <= index[index.size() - 1])
			continue;	

		temp.push_back(arr[i]);
		index.push_back(i);
		backtrack();
		temp.pop_back();
		index.pop_back();
	}
	return;
}

int main(void) {	
	FAST;
	cin >> l >> c;

	arr.resize(c);
	for (int i = 0; i < c; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	backtrack();
	
	return 0;
}