#include<bits/stdc++.h>

using namespace std;

bool isNumber(char x){
    return ('0' <= x && x <= '9');
}

int postToInfix(string s){
    stack<int> stk;
    for(int i = 0; i < s.size(); i++){
        if(isNumber(s[i])){
            stk.push(s[i]-'0');
        }
        else {
//            string op1 = stk.top(); stk.pop();
//            string op2 = stk.top(); stk.pop();
//            string temp = "("+op2+s[i]+op1+")";
//            stk.push(temp);

            int op1 = stk.top(); stk.pop();
            int op2 = stk.top(); stk.pop();
            switch(s[i]){
                case '+':
                    stk.push(op2+op1);
                    break;
                case '-':
                    stk.push(op2-op1);
                    break;
                case '*':
                    stk.push(op2*op1);
                    break;
                case '/':
                    stk.push(op2/op1);
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
        cout << postToInfix(s) << endl;
    }
    return 0;
}
