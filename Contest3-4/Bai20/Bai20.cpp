#include<bits/stdc++.h>

using namespace std;

void solve(string s) {
    // vector position de luu vi tri cua dau '['
    vector<int> position;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '[') {
            position.push_back(i);
        }
    }
    // bien count nhu bien trang thai, bien result de luu ket qua, bien p de cho ta biet duoc vi tri cua ki tu '['
    int count = 0;
    int result = 0;
    int p = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '[') {
            ++count;
            ++p;
        }
        if(s[i] == ']') {
            --count;
        }
        if(count < 0) {
            result += position[p] - i;
            swap(s[i],s[position[p]]);
            ++p;
            count = 1;
        }
    }
    cout << result << endl;
}

int main(){
    int test;
    cin >> test;
    while(test--) {
        string s;
        cin >> s;
        solve(s);
    }
    return 0;
}
