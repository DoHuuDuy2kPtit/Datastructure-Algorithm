#include<bits/stdc++.h>

using namespace std;

void solve(int a[],int b[], int n){
    sort(b,b+n);
    int indexL = 0;
    int indexR = 0;
    for(int i = 0; i < n; i++){
        if(a[i]!=b[i]) {
            indexL=i;
            break;
        }
    }
    for(int i = n-1; i > 0; i--){
        if(a[i]!=b[i]) {
            indexR = i;
            break;
        }
    }
    cout << indexL+1 << " " << indexR+1 << endl;
}

int main(){
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        int a[n], b[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            b[i] = a[i];
        }
        solve(a,b,n);
    }
}
