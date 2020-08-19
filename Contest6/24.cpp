#include<bits/stdc++.h>

using namespace std;

int binarySearch(int a[], int l, int r, int x){
    if(l > r) return -1;
    int mid = (l+r)/2;
    if(x==a[mid]) return mid;

    if(x > a[mid]) return binarySearch(a,mid+1,r,x);
    else return binarySearch(a,l,mid-1,x);
}

int findPivot(int a[],int l, int r){
    if(l>r) return -1;
    if(l==r) return l;

    int mid = (l+r)/2;
    if(mid < r && a[mid] > a[mid+1]) return mid;

    if(mid > l && a[mid] < a[mid-1]) return (mid-1);

    if(a[l] >= a[mid]) return findPivot(a,l,mid-1);
    else return findPivot(a,mid+1,r);
}

int solve(int a[],int n, int x){
    int p = findPivot(a,0,n-1);
    if(p == -1) return binarySearch(a,0,n-1,x);

    if(a[p] == x) return p;

    if(a[0] < x) return binarySearch(a,0,p-1,x);
    return binarySearch(a,p+1,n-1,x);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,x;
        cin >> n >> x;
        int a[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        cout << solve(a,n,x)+1 << endl;
    }
}
