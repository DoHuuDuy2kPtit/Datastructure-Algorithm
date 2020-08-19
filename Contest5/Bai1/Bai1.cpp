#include<bits/stdc++.h>

using namespace std;
int l[1001][1001];
string s1,s2;

int lcs(){
    for(int i = 0; i <= s1.size(); i++){
        for(int j = 0; j <= s2.size(); j++){
            if(i==0 || j == 0) l[i][j] = 0;
            else if(s1[i-1]==s2[j-1]) l[i][j] = 1 + l[i-1][j-1];
            else l[i][j] = max(l[i-1][j],l[i][j-1]);
        }
    }
    return l[s1.size()][s2.size()];
}

int main(){
    int test;
    cin >> test;
    while(test--) {
        cin >> s1 >> s2;
        cout << lcs() << endl;
    }
    return 0;
}
