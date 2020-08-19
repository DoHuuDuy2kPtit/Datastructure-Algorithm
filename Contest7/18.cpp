#include<bits/stdc++.h>

using namespace std;

int precedence(char x){
    if(x == '^') return 3;
    else if(x == '*' || x == '/') return 2;
    else if(x == '+' || x == '-') return 1;
    return -1;
}

bool isNumber(char x){
    return ('0' <= x && x <= '9');
}

int InfixToPost(string s){
    stack<int> Operand;
    stack<char> Operator;

    for(int i = 0; i < s.size();i++){
        // case (
        if(s[i] == '(') Operator.push('(');
        // case toan hang.
        if(isNumber(s[i])){
            int num = 0;
            while(i<s.size() && isNumber(s[i])){
                num = num*10+(s[i]-'0');
                i++;
            }
            Operand.push(num);
        }
        // case toan tu
        if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
            while(!Operator.empty() && precedence(s[i]) <= precedence(Operator.top())){
                int num1, num2;
                num1 = Operand.top(); Operand.pop();
                num2 = Operand.top(); Operand.pop();
                switch(Operator.top()){
                    case '+':
                        Operand.push(num1+num2);
                        break;
                    case '-':
                        Operand.push(num1-num2);
                        break;
                    case '/':
                        Operand.push(num1/num2);
                        break;
                    case '*':
                        Operand.push(num1*num2);
                        break;
                }
                Operator.pop();
            }
        }
        // case )
        if(s[i] == ')'){
            while(!Operator.empty()&&Operator.top() != '('){
                int num1, num2;
                num1 = Operand.top(); Operand.pop();
                num2 = Operand.top(); Operand.pop();
                switch(Operator.top()){
                    case '+':
                        Operand.push(num1+num2);
                        break;
                    case '-':
                        Operand.push(num1-num2);
                        break;
                    case '/':
                        Operand.push(num1/num2);
                        break;
                    case '*':
                        Operand.push(num1*num2);
                        break;
                }
                Operator.pop();
            }
            if(!Operator.empty() && Operator.top() == '(') Operator.pop();
        }
    }
    // tiep tuc tinh gia tri neu chua duyet het string s
    while(!Operator.empty()){
        int num1, num2;
            num1 = Operand.top(); Operand.pop();
            num2 = Operand.top(); Operand.pop();
            switch(Operator.top()){
                case '+':
                    Operand.push(num1+num2);
                    break;
                case '-':
                    Operand.push(num1-num2);
                    break;
                case '/':
                    Operand.push(num1/num2);
                    break;
                case '*':
                    Operand.push(num1*num2);
                    break;
                }
                Operator.pop();
    }
    return Operand.top();
}

int main(){
    int test;
    cin >> test;
    while(test--){
        string s;
        cin >> s;
        cout << InfixToPost(s) << endl;
    }
}
