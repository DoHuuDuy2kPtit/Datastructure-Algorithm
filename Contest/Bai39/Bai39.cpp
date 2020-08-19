#include<iostream>
#include<string>

using namespace std;

void solve(string &s,int n) {
    while(s.length() <= n-1) {
        string temp = s;
        char lastEle = temp[temp.length()-1];
        for(int i = temp.length()-1; i > 0; i--) {
            temp[i] = temp[i-1];
        }
        temp[0] = lastEle;
        s = s + temp;
    }
}

int main() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    solve(s,n);
    cout << s[n-1];
}
