#include<bits/stdc++.h>

using namespace std;

string removeBracket(string s){
    string result="";
    stack<int> stk;
    for(int i = 0; i < s.size();i++){
        if(s[i]=='(') stk.push(i);
        else if(s[i] == ')'){
            if(stk.size() > 0) {
                int top = stk.top();
                stk.pop();
                if(top==0) continue;
                else if(s[top-1]=='+') continue;
                else if(s[top-1]=='-'){
                    for(int j = top; j <= i;j++){
                        if(s[j]=='+') s[j] = '-';
                        else if(s[j] == '-') s[j]='+';
                    }
                }
            }
        }
    }
    for(int i = 0; i < s.size();i++){
        if(s[i] != '(' && s[i]!=')') result+=s[i];
    }
    return result;
}

int main(){
    int test;
    cin >> test;
    while(test--){
        string s1;
        string s2;
        cin >> s1 >> s2;
//        cout << removeBracket(s1) << " " << removeBracket(s2) << endl;
        if(removeBracket(s1)==removeBracket(s2)) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
    return 0;
}
