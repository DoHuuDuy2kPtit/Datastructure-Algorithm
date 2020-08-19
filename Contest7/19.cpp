#include<bits/stdc++.h>

using namespace std;

void solve(string s){
    string result;
    stack<int> stk;

    for(int i = 0; i <= s.size();i++){
        stk.push(i+1);
        if(i==s.size() || s[i] == 'I'){
            while(!stk.empty()){
                result += to_string(stk.top());
                stk.pop();
            }
        }
    }
    cout << result << endl;
}

int main()
{
    int test;
    cin >> test;
    while(test--){
        string s;
        cin >> s;
        solve(s);
    }
    return 0;
}
