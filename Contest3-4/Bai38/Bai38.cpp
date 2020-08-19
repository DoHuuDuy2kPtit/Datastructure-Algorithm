#include<bits/stdc++.h>

using namespace std;

int mergeArray(int a[],int b[],int m, int n,int index){
    int temp[n+m+1];
    int i = 1;
    int j = 1;
    int k = 1;
    while(i <= m && j <= n){
        if(a[i] > b[j]){
            temp[k] = b[j];
            j++;
        } else {
            temp[k] = a[i];
            i++;
        }
        if(k==index) return temp[k];
        k++;
    }
    while(i <= m){
        temp[k] = a[i];
        if(k==index) return temp[k];
        k++;
        i++;
    }

    while(j <= n) {
        temp[k] = b[j];
        if(k==index) return temp[k];
        k++;
        i++;
    }
}

int main(){
    int test;
    cin >> test;
    while(test--){
        int m,n,k;
        cin >> m >> n >> k;
        int a[m], b[n];
        for(int i = 1; i <= m; i++){
            cin >> a[i];
        }
        for(int j = 1; j <= n; j++){
            cin >> b[j];
        }
        cout << mergeArray(a,b,m,n,k) << endl;
    }
}
