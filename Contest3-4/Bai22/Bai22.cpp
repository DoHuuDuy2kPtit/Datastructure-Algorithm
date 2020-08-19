#include<bits/stdc++.h>

using namespace std;

int n, k;
int a[100000];

int binarySearch(int left, int right){
    if(left>right) return 0;
    int mid = (left+right)/2;
    if(a[mid]==k) return mid;
    if(a[mid] < k) return binarySearch(mid+1,right);
    else return binarySearch(left,mid-1);
}

int main() {
    int test;
    cin >> test;
    while(test--){
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        if(binarySearch(1,n)) cout << binarySearch(1,n) << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
