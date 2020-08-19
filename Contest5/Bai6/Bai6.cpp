#include<bits/stdc++.h>

using namespace std;
int L[1001][1001];

int LPS(string s){
    int n = s.length();
    int i, j, len;

    for(int k = 0; i <s.size();i++){
        for(int h = 0; j < s.size(); j++){
            L[k][h] = 0;
        }
    }

    for(i = 0; i < n; i++){
        L[i][i] = 1;
    }

    for(len = 2; len <= n; len++){
        for(i = 0; i < n - len +1; i++) {
            j = i + len - 1;
            if(s[i] == s[j] && len == 2) L[i][j] = 2;
            else if(s[i]==s[j]) L[i][j] = L[i+1][j-1]+2;
            else L[i][j] = max(L[i][j-1],L[i+1][j]);
        }
    }
    return L[0][n-1];
}

int main(){
    int test;
    cin >> test;
    while(test--){
        string s;
        cin >> s;
        cout << LPS(s) << endl;
    }
    return 0;
}
