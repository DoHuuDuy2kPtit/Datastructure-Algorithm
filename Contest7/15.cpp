#include<bits/stdc++.h>

using namespace std;

bool isOperand(char x){
    return (x >= 'a' && x <= 'z')||(x >= 'A'&& x <= 'Z');
}

string postToInfix(string s){
    stack<string> stk;
    for(int i = 0; i < s.length(); i++){
        if(isOperand(s[i])){
            string temp = "";
            temp+= s[i];
            stk.push(temp);
        }
        else {
            string op1 = stk.top(); stk.pop();
            string op2 = stk.top(); stk.pop();
            string temp = "("+op2+s[i]+op1+")";
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
        cout << postToInfix(s) << endl;
    }
}
