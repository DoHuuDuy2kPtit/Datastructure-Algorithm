#include<bits/stdc++.h>

using namespace std;

bool isOperator(char x){
    switch(x){
        case '+':
        case '-':
        case '*':
        case '/':
            return true;
        default:
            return false;
    }
}

// Duyệt từ trái qua phải gặp toán hạng thì đẩy vào stk, gặp toán tử thì lấy 2 toán hạng tạo thành biểu thức s[i] + op2+ op1 sau đó đẩy vào stk

string postToPre(string s){
    stack<string> stk;
    for(int i = 0; i < s.size(); i++){
        if(isOperator(s[i])){
            string op1 = stk.top(); stk.pop();
            string op2 = stk.top(); stk.pop();
            string temp = s[i]+op2+op1;
            stk.push(temp);
        }else {
            string temp = "";
            temp+=s[i];
            stk.push(temp);
        }
    }
    return stk.top();
}

int main(){
    int test;
    cin >> test;
    while(test--){
        string s;
        cin >> s;
        cout << postToPre(s) << endl;
    }
    return 0;
}
