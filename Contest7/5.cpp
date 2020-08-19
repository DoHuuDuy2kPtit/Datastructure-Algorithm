#include<bits/stdc++.h>

using namespace std;

void solve(string s){
    stack<int> stk;
    stk.push(-1);
    int result = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(') stk.push(i);
        else{
            stk.pop();
            if(!stk.empty()) result = max(result,i-stk.top());

            else stk.push(i);
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
