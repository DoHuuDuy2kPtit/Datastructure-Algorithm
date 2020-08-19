#include<bits/stdc++.h>

using namespace std;

int maxCrossingSum(int arr[],int l, int m, int r){
    int sum = 0;
    int left_sum = INT_MIN;
    for(int i = m; i >= l; i--){
        sum+=arr[i];
        if(sum > left_sum) {
            left_sum = sum;
        }
    }

    sum = 0;
    int right_sum = INT_MIN;
    for(int i = m+1; i <= r; i++){
        sum+=arr[i];
        if(sum > right_sum) {
            right_sum = sum;
        }
    }
    return max(
               max(left_sum,right_sum),
               left_sum+right_sum
               );
}

int  maxSubArraySum(int arr[],int l, int r){
    if(l==r){
        return arr[l];
    }
    int m = (l+r)/2;
    return max(
               max(maxSubArraySum(arr,l,m),maxSubArraySum(arr,m+1,r)),
               maxCrossingSum(arr,l,m,r)
               );
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
        cout << maxSubArraySum(arr,0,n-1) << endl;
    }
    return 0;
}
