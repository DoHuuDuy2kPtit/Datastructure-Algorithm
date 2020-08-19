#include<bits/stdc++.h>

using namespace std;

int count(int x,int y[],int m,int NoOfY[]){
    if(x==0) return 0;
    if(x==1) return NoOfY[0];
    int* index = upper_bound(y,y+m,x);
    int ans = (y+m) - index;

    ans+=NoOfY[0]+NoOfY[1];

    if(x==2) ans -= (NoOfY[3]+NoOfY[4]);

    if(x==3) ans += NoOfY[2];

    return ans;
}

int solve(int x[],int y[],int n, int m){
    int NoOfY[5] = {0};
    for(int i = 0; i < m; i++){
        if(y[i] < 5){
            NoOfY[y[i]]++;
        }
    }

    sort(y,y+m);
    int total_pair = 0;
    for(int i = 0; i < n;i++){
        total_pair += count(x[i],y,m,NoOfY);
    }
    return total_pair;
}

int main(){
    int test;
    cin >> test;
    while(test--){
    int n,m;
        cin >> n >> m;
        int a[n], b[m];
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<m;i++) cin >> b[i];
        cout << solve(a,b,n,m) << endl;
    }
}
