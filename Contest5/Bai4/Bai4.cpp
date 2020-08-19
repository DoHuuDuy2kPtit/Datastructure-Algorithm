#include<bits/stdc++.h>

using namespace std;


int solve(int a[],int n, int k){
    int matrix[1005][50];
    matrix[0][0] = 0;
    for(int i = 1; i < k; i++){
        matrix[0][i] = -1005;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < k; j++){
            matrix[i][j] = max(matrix[i-1][j],matrix[i-1][(j+k-a[i]%k)%k]+1);
        }
    }
    return matrix[n][0];
}

int main(){
    int t,k,n;
    cin >> t;
    while(t--){
        cin >> n >> k;
        int a[n];
        for(int i = 1; i <= n; i++) cin >> a[i];
        cout << solve(a,n,k) << endl;
    }
    return 0;
}
