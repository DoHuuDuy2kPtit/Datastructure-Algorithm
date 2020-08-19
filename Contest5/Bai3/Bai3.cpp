#include<bits/stdc++.h>

using namespace std;

bool tableResult[10000][100000];

bool isSubSumSet(int a[],int n, int sum){
    for(int i = 0; i <= n; i++) {
        tableResult[i][0] = true;
    }
    for(int i = 1; i <= sum; i++){
        tableResult[0][i] = false;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum; j++){
            if(j < a[i-1]) tableResult[i][j] = tableResult[i-1][j];
            else tableResult[i][j] = tableResult[i-1][j] || tableResult[i-1][j-a[i-1]];
        }
    }

    return tableResult[n][sum];
}

int main(){
    int test;
    cin >> test;
    while(test--){
        int n, sum;
        cin >> n >> sum;
        int a[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        if(isSubSumSet(a,n,sum)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
