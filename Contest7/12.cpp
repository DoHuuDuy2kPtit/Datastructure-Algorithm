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

// Duyệt từ phải qua trái;
// Gặp toán tử thì lấy ra lấy 2 toán hạng ra và tạo thành biểu thức có dạng ( op1 + s[i] + op2) sao đó đẩy biểu thức này vào trong ngăn xếp;
// Gặp toán hạng thì đẩy vào ngăn xếp 

string preToInfix(string s){
    stack<string> stk;
    for(int i = s.size()-1; i >= 0; i--){
        if(isOperator(s[i])){
            string op1 = stk.top(); stk.pop();
            string op2 = stk.top(); stk.pop();

            string temp = "("+op1+s[i]+op2+")";

            stk.push(temp);
        }
        else {
            stk.push(string(1,s[i]));
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
        cout << preToInfix(s) << endl;
    }
    return 0;
}
