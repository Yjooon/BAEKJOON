#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    set<int> s;
    for (int i : nums) {
        s.insert(i);
    }
    
    int maxi = nums.size() / 2;
    
    if (maxi <= s.size())
        return maxi;
    else {
        return s.size();
    }
    
    
    return answer;
}