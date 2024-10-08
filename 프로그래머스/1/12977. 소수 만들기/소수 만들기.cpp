#include <vector>
#include <iostream>
using namespace std;

bool isPrime(int num);

int solution(vector<int> nums) {
    int answer = 0;

    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            for (int k = j + 1; k < nums.size(); k++) {
                if (isPrime(nums[i] + nums[j] + nums[k])) 
                    answer++;
            }
        }
    }
    
    cout << answer << endl;
    return answer;
}

bool isPrime(int num) {
    if (num == 2) 
        return true;
    int temp = 2;
    while (temp < num) {
        if (num % temp == 0) {
            return false;
        }
        temp++;
    }
    return true;
}