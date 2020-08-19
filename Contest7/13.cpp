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

// Duyệt phải qua trái gặp toán hạng thì đẩy vào stk gặp toán tử thì lấy 2 toán hạng ra tạo thành bt op1 + op2 + s[i] (chú ý ko có dấu ngoặc)

string preToPost(string s){
    stack<string> stk;
    for(int i = s.size()-1; i>=0; i--){
        if(isOperator(s[i])){
            string op1 = stk.top(); stk.pop();
            string op2 = stk.top(); stk.pop();
            string temp = op1+op2+s[i];
            stk.push(temp);
        }
        else{
            string temp = "";
            temp+=s[i];
            stk.push(temp);
        }
    }
    return stk.top();
}

int main()
{
    int test;
    cin >> test;
    while(test--){
        string s;
        cin >> s;
        cout << preToPost(s) << endl;
    }
    return 0;
}
