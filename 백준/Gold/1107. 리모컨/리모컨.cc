#include <iostream>
#include <vector>
#include <string>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int channel = 100;
int n, m;
int resultD = 0, resultU = 0;
int bitmask = (1 << 10) - 1;
int errorNum;
bool flag;

int main() {
    FAST;
    cin >> n;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> errorNum;
        bitmask &= ~(1 << errorNum); // 고장: 0 정상: 1
    }
    string str = to_string(n);
    string pushU, pushD;
    resultU = str.length();
    resultD = str.length();

    flag = false; //고장나서 다른거 누르면 true

    if (m == 10) { //전부 고장
        cout << abs(channel - n);
        return 0;
    }
    for (int i = 0; i < str.size(); i++) {
        if (!flag && (bitmask >> str[i] - '0' & 1)) { //고장 아니면 누르고 
            pushU += str[i];
            continue;
        }
        else { //고장이면 인접한 수 눌러야함 (위쪽, 가장 작은 수)
            if (!flag) { //첫 고장이면
                for (int j = 1; j <= 9 - (str[i] - '0'); j++) {
                    if (bitmask >> str[i] - '0' + j & 1) {
                        pushU += str[i] + j;
                        flag = true;
                        break;
                    }
                }
                if (!flag) { //위쪽 다 고장나면 0부터 시작해서 고장나지 않은 숫자로 돌리고 그 위의자리에 + 1
                    bool flag2 = false;
                    int p;
                    for (int k = 0; k < 10; k++) {
                        if (!flag2 && bitmask >> k & 1) {
                            int l = resultU - pushU.length();
                            for (p = 0; p < l; p++) {
                                pushU += to_string(k);
                                flag2 = true;
                            }
                        }
                        if (flag2)
                            break;
                    }

                    flag2 = false;
                    if (p == pushU.length()) { //한 칸 더 위가 없으면
                        resultU++;
                        for (int z = 0; z < 10; z++) {
                            if (bitmask >> z & 1) {
                                pushU += z + '0'; 
                                break;
                            }
                        }

                        for (int z = 1; z < 10; z++) {
                            if (bitmask >> z & 1) {
                                pushU[0] = z + '0';
                                break;
                            }
                        }
                        break;
                    }
                    for (int k = pushU[resultU - p - 1] - '0' + 1; k < 10; k++) { //위의 자리에 1 더하는 과정
                        if (bitmask >> k & 1) { //위의 자리에서 큰 수 중 고장 안난 것 찾기
                            pushU[pushU.length() - p - 1] = k + '0';
                            flag2 = true;
                            break;
                        }             
                        if (k == 9 && !flag2) { //위의 자리에서 위쪽 다 고장나면 한 칸 더 위로
                            pushU[resultU - p - 1] = 0 + '0';
                            k = 0;
                            p++;  
                            if (p == pushU.length()) { //한 칸 더 위가 없으면
                                resultU++;
                                for (int z = 0; z < 10; z++) {
                                    if (bitmask >> z & 1) {
                                        pushU += z + '0'; 
                                        break;
                                    }
                                }
                                
                                for (int z = 1; z < 10; z++) {
                                    if (bitmask << z & 1) {
                                        pushU[0] = z + '0'; 
                                        break;
                                    }
                                }                               
                                break;
                            }
                        }
                    }                    
                    break;
                }
            }
            else { //고장 한 번 난 이후로 가장 작은 것 찾기
                bool flag2 = false;
                for (int k = 0; k < 10; k++) {                    
                    if (bitmask >> k & 1) {
                        int l = resultU - pushU.length();
                        for (int p = 0; p < l; p++) {
                            pushU += to_string(k);
                            flag2 = true;
                        }
                        if (flag2)
                            break;
                    }
                }
                if (flag2)
                    break;
            }
        }
    }
    if (resultU != 0 && pushU.length() == resultU) //정상적으로 번호 들어왔을 경우
        resultU += abs(n - stoi(pushU));
    else
        resultU = 1000000;

    flag = false;
    for (int i = 0; i < str.size(); i++) {
        if (!flag && (bitmask >> str[i] - '0' & 1)) { //고장 아니면 누르고 
            pushD += str[i];
            continue;
        }
        else { //고장이면 인접한 수 눌러야함 (아래쪽, 가장 큰 수)
            if (!flag) {
                for (int j = 1; j <= str[i] - '0'; j++) {
                    if (bitmask >> str[i] - '0' - j & 1) {
                        pushD += str[i] - j;
                        flag = true;
                        break;
                    }
                }
                if (!flag) { //아래쪽 다 고장나면 자리수 내려서 가장 큰 수 찾기
                    bool flag2 = false;
                    int p;
                    for (int k = 9; k >= 0; k--) {
                        if (!flag2 && bitmask >> k & 1) {
                            int l = resultD - pushD.length();
                            for (p = 0; p < l; p++) {
                                pushD += to_string(k);
                                flag2 = true;
                            }
                        }
                        if (flag2)
                            break;
                    }

                    flag2 = false;
                    if (p == pushD.length()) { //자릿수가 없으면
                        resultD--;
                        pushD.erase(pushD.size() - 1);                        
                        break;
                    }
                    for (int k = pushD[resultD - p - 1] - '0' - 1; k >= 0; k--) { //위의 자리에 1 빼는 과정
                        if (bitmask >> k & 1) { //아랫 자리에서 작은 수 중 고장 안난 것 찾기
                            pushD[resultD - p - 1] = k + '0';
                            flag2 = true;
                            break;
                        }
                        if (!flag2) {
                            pushD[0] = 0 + '0';
                        }
                    }
                    break;
                }
            }
            else {
                for (int k = 9; k >= 0; k--) {
                    if (bitmask >> k & 1) {
                        pushD += to_string(k);
                        break;
                    }
                }
            }
        }
    }
    if (resultD != 0 && pushD.length() == resultD)
        resultD += abs(n - stoi(pushD));
    else
        resultD = 1000000;

    for (int i = 0; i < pushU.length(); i++) {
        if (i != pushU.length() - 1 && pushU[i] - '0' == 0) {
            resultU--;
        }
        else
            break;
    }
    for (int i = 0; i < pushD.length(); i++) {
        if (i != pushD.length() - 1 && pushD[i] - '0' == 0) {
            resultD--;
        }
        else
            break;
    }

    cout << min(abs(channel - n), min(resultU, resultD));

    return 0;
}