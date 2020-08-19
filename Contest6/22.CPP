#include<bits/stdc++.h>

using namespace std;

int binaSearch(int a[],int low, int high, int x){
    if(low > high) return -1;
    int mid = (low + high)/2;
    if(a[mid] == x) return 1;
    if(a[mid] > x) return binaSearch(a,low,mid-1,x);
    else return binaSearch(a,mid+1,high,x);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n , x;
        cin >> n >> x;
        int a[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        cout << binaSearch(a,0,n-1,x) << endl;
    }
    return 0;
}
