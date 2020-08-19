#include<bits/stdc++.h>

using namespace std;

long long floorSearch(long long arr[],long long low,long long high,long long x){
    if(low > high) return -1;
    if(x >= arr[high]) return high;
    long long mid = (low+high)/2;
    if(arr[mid]==x) return mid;
    if(mid > 0 && arr[mid-1] <= x && x < arr[mid]) return mid-1;
    if(x < arr[mid]) return floorSearch(arr,1,mid-1,x);
    return floorSearch(arr,mid+1,high,x);
}

int main(){
    int test;
    cin >> test;
    while(test--){
        long long n, x;
        cin >> n >> x;
        long long arr[n+1];
        for(int i = 1; i<=n; i++){
            cin >> arr[i];
        }
        long long index = floorSearch(arr,1,n,x);
        cout << index << endl;
    }
}
