#include <iostream>
#include <string>
#include <vector>

void func_1(const std::vector<std::string>& arr, int num, int a) { 
    if(arr[a] != ".")
        std::cout << arr[a];
    if (arr[a + 1] != ".") { //왼쪽 존재
        for (int i = a + 3; i < num; i += 3) {
            if (arr[i] == arr[a + 1]) {
                func_1(arr, num, i);
            }
        }
    }
    if (arr[a + 2] != ".") { //오른쪽 존재
        for (int i = a + 3; i < num; i += 3)
            if (arr[i] == arr[a + 2]) {
                func_1(arr, num, i);
            }
    }
}

void func_2(const std::vector<std::string>& arr, int num, int a) {
    if (arr[a + 1] != ".") { //왼쪽 존재
        for (int i = a + 3; i < num; i += 3) {
            if (arr[i] == arr[a + 1]) {
                func_2(arr, num, i);       
                std::cout << arr[a];
            }
        }
    }
    else {
        std::cout << arr[a];
    }

    if (arr[a + 2] != ".") { //오른쪽 존재
        for (int i = a + 3; i < num; i += 3)
            if (arr[i] == arr[a + 2]) {
                func_2(arr, num, i);
            }
    }
}

void func_3(const std::vector<std::string>& arr, int num, int a) {
    if (arr[a + 1] != ".") { //왼쪽 존재
        for (int i = a + 3; i < num; i += 3) {
            if (arr[i] == arr[a + 1]) {
                func_3(arr, num, i);
                if (arr[a + 2] != ".") { //오른쪽 존재
                    for (int i = a + 3; i < num; i += 3)
                        if (arr[i] == arr[a + 2]) {
                            func_3(arr, num, i);
                        }
                }
                std::cout << arr[a];
            }            
        }
    }
    else if (arr[a + 2] != ".") { //오른쪽 존재
        for (int i = a + 3; i < num; i += 3)
            if (arr[i] == arr[a + 2]) {
                func_3(arr, num, i);
                std::cout << arr[a];
            }
    }
    else {
        std::cout << arr[a];
    }
}
    

int main()
{
    std::vector<std::string> strings;

    int num;
    std::cin >> num;
    
    num *= 3;

    std::string input;
    for (int i = 0; i < num; i++) {
        std::cin >> input;
        strings.push_back(input);
    }

    std::vector<std::string> arr;
    int a = 0;
    
    // 전위 순회    
    func_1(strings, num, a);
    std::cout << std::endl;

    // 중위 순회
    func_2(strings, num, a);
    std::cout << std::endl;

    // 후위 순회    
    func_3(strings, num, a);
    return 0;
}

