#include<bits/stdc++.h>

using namespace std;

void solve(string s){
    vector<char> result;
    int i = 0;
    while(i < s.size()){
        // Đưa từ vào trong vector result;
        while(i<s.size() && s[i] != ' ' ){
            result.push_back(s[i]);
            i++;
        }
        // In từ theo thứ tự ngược lại
        while(!result.empty()){
            cout << result.back();
            result.pop_back();
        }
        // In dấu ' '
        if(i<s.size()){
            cout << s[i++];
        }
    }
}

int main(){
    int test;
    cin >> test;
    string s;
    getline(cin,s);
    while(test--){
        getline(cin,s);
        solve(s);
        cout << endl;
    }
}
