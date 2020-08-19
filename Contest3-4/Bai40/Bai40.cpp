#include<bits/stdc++.h>

using namespace std;

int findFirstZero(int arr[],int l, int h){
    if(h >= l){
        int m = l + (h - l)/2;
        if((m == 0 || arr[m-1]==1) && arr[m] == 0) return m;
        if(arr[m] == 1) return findFirstZero(arr,m+1,h);
        else return findFirstZero(arr,l,m-1);
    }
    return -1;
}

int main(){
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        int first = findFirstZero(arr,0,n-1);
        if(first == -1) cout << 0 << endl;
        else cout << (n - first) << endl;
    }
}
