#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;
int dp[1001][1001];

int main(){
    for(int i = 0; i < 1000;i++){
        for(int j = 0; j <= i; j++){
            if(i==j || j == 0) dp[i][j] = 1;
            else dp[i][j] = dp[i-1][j]+dp[i-1][j-1];
            dp[i][j] %= mod;
        }
    }

    int test;
    cin >> test;
    while(test--){
        int n,k;
        cin >> n >> k;
        cout << dp[n][k] << endl;
    }
    return 0;
}
