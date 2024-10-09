#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int bfs(string str, string target, vector<string> words, int num);
bool compare(string str, string word);

int solution(string begin, string target, vector<string> words) {
    bool flag = false;
    for (string s : words) {
        if (s == target) {
            flag = true;
        }
    }
    if (!flag) {
        return 0;
    }

    return bfs(begin, target, words, 0);
}

int bfs(string str, string target, vector<string> words, int num) {
    if (str == target)
        return num;
    
    int temp = 100;
    for(string s : words) {
        if (compare(str, s)) {
            vector<string> newWords = words;
            newWords.erase(remove(newWords.begin(), newWords.end(), s), newWords.end());
            int newNum = num + 1;
            temp = min(bfs(s, target, newWords, newNum), temp);
        }
    }
    return temp;
}

bool compare(string str, string word) {
    int len = str.length();
    int num = 0;
    for(int i = 0; i < len; i++) {
        if (str[i] != word[i])
            num++;
    }
    if (num == 1) {
        return true;
    }
    else {
        return false;
    }
}
