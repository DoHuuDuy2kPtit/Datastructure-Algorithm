#include<bits/stdc++.h>

using namespace std;

// Xâu thừa cặp ngoặc '(' và ')' khi và chỉ khỉ tổng số ngoặc mở nhiều hơn tổng số toán tử.

bool check(string s){
    int bracket = 0;
    int oper = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i]=='(' && s[i+2] == ')') return true;
        if(s[i]=='(') bracket++;
        if(s[i]== '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') oper++;
    }
    return bracket > oper;
}

int main(){
    int test;
    cin >> test;
    while(test--)
    {
        string s;
        cin >> s;
        if(check(s)) cout << "Yes";
        else cout << "No";
        cout << endl;
    }
}
