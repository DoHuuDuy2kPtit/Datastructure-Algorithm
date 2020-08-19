#include<bits/stdc++.h>

using namespace std;

// Đếm số lần xuất hiện của các kí tự trong s;
// Sắp xếp số lần xuất hiện theo thứ tự giảm dần;

void solve(string s,int d){
    bool chuaxet[s.length()];
    map<char,int> count;
    priority_queue<int,vector<int>,less<int>> pq;
    for(int i = 0; i < s.length(); i++) {
        count[s[i]]++;
        chuaxet[i] = true;
    }
    for(auto it : count) {
        pq.push(it.second);
    }
    while(!pq.empty()){
        int p = pq.top();
        pq.pop();
        int t = 0;
        while(!chuaxet[t]) t++;
        for(int q = 0; q < p; q++){
            if(t+q*d >= s.length()) {
                cout << -1 << endl;
                return;
            }
            chuaxet[t+q*d] = false;
        }
    }
    cout << 1 << endl;
    return;
}

int main() {
    string s;
    int d;
    cin >> d >> s;
    solve(s,d);
}
