#include<bits/stdc++.h>

using namespace std;

bool isNumber(char x){
    return ('0' <= x && x <= '9');
}

int preToInfix(string s){
    stack<int> stk;
    for(int i = s.size()-1; i>=0; i--){
        if(isNumber(s[i])){
            stk.push(s[i]-'0');
        }
        else {
            int op1 = stk.top(); stk.pop();
            int op2 = stk.top(); stk.pop();
            switch(s[i]){
                case '+':
                    stk.push(op1+op2);
                    break;
                case '-':
                    stk.push(op1-op2);
                    break;
                case '*':
                    stk.push(op1*op2);
                    break;
                case '/':
                    stk.push(op1/op2);
                    break;
            }
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
