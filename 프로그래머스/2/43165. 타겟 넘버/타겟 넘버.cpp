#include <string>
#include <vector>

using namespace std;

int temp = 0;
int answer = 0;

void dfs(int temp, vector<int> numbers, int index, int target);

int solution(vector<int> numbers, int target) {
    dfs(0, numbers, 0, target);
    
    return answer;
}

void dfs(int temp, vector<int> numbers, int index, int target) {
    if (index >= numbers.size()) {
        if (temp == target) {
            answer++;
            return;
        }
        else 
            return;
    }
    
    int tempPlus = temp + numbers[index];
    int tempMinus = temp - numbers[index];
    index++;
    dfs(tempPlus, numbers, index, target);
    dfs(tempMinus, numbers, index, target);
}