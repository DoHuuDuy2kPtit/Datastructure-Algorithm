#include<bits/stdc++.h>

using namespace std;

// Xóa bỏ các cặp đóng mở ngoặc '(',')'
// Số lượng dấu ngoặc đổi chiều tính bằng công thức 
// x = m/2 + n%2; trong đó m là kích thước của dãy sau khi xóa.
//                         n là số các dấu mở ngoặc của dãy sau khi xóa.

int countMinChange(string s){
    stack<char> temp;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == ')' && !temp.empty()){
            if(temp.top() == '(') temp.pop();
            else temp.push(s[i]);
        }
        else temp.push(s[i]);
    }
    int m = temp.size();
    int n = 0;
    while(!temp.empty()){
        if(temp.top()=='(') n++;
        temp.pop();
    }
    return m/2 + n%2;
}

int main(){
    int test;
    cin >> test;
    while(test--){
        string s;
        cin >> s;
        cout << countMinChange(s) << endl;
    }
}
