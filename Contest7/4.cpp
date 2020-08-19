#include<bits/stdc++.h>

using namespace std;

bool check(string s){
    vector<char>  result;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '{' || s[i] == '[' || s[i] == '(') result.push_back(s[i]);
        else {
            if(result.empty()) return false;
            if(s[i] == ')' && result.back() != '(') return false;
            if(s[i] == '}' && result.back() != '{') return false;
            if(s[i] == ']' && result.back() != '[') return false;

            result.pop_back();
        }
    }
    if(result.empty()) return true;
    else return false;
}

int main()
{
    int test;
    cin >> test;
    while(test--){
        string s;
        cin >> s;
        if(check(s)==true) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
}
