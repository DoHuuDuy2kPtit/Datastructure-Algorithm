#include<bits/stdc++.h>
#include<map>

using namespace std;

void solve(string s, int k) {
    priority_queue<int,vector<int>,less<int>> countAppearance;
    map<char,int> count;
    for(int i = 0; i < s.length(); i++) {
        count[s[i]]++;
    }
    for(auto it : count) {
        countAppearance.push(it.second);
    }
    while(k > 0) {
        int temp = countAppearance.top();
        countAppearance.pop();
        --temp;
        countAppearance.push(temp);
        k--;
    }
    int sum = 0;
    while(!countAppearance.empty()) {
        int p = countAppearance.top();
        countAppearance.pop();
        sum += p*p;
    }
    cout << sum << endl;
    return ;
}

int main() {
    int test;
    cin >> test;
    while(test--){
        string s;
        int k;
        cin >> k;
        cin >> s;
        solve(s,k);
    }
    return 0;
}

