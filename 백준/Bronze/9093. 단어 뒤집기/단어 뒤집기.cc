#include <iostream>
#include <string.h>
#include <stack>
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int n, sw;
string str;

int main() {
  cin>>n;
  cin.ignore();  // 버퍼 무시
  for(int k=0; k<n; k++)
  {
    getline(cin, str);  //라인 입력
    for(int i=0; i<str.size(); i++)
    {
      if(str[i]==' ')  //공백이 있으면
      {
        for(int j=i-1; str[j]!=' ' && j>=0; j--)  //공백 뒤부터 거꾸로 읽으며 출력
          cout<<str[j];
        cout<<" ";
      }
    }
    
    for(int j=str.size()-1; str[j]!=' '&&j>=0; j--)  //마지막 단어 거꾸로 출력
      cout<<str[j];
    cout<<" \n";
  }
}