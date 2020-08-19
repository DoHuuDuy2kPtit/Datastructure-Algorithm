#include<bits/stdc++.h>

using namespace std;

long long n,k;

// Binary search:
// Nếu left == right return 1;
// Tính mid = (left+right)/2;
// Nếu mid == k thì return numAdd;
// Nếu mid > k thì binary search (numAdd-1,left,mid-1);
// Nếu mid < k thì binary search (numAdd-1,mid+1,right);

long long findKthElement(long long numAdd,long long left,long long right) {
    if(left==right) return 1;
    long long mid = (left+right)/2;
    if(mid==k) return numAdd;
    if(mid > k) findKthElement(numAdd-1,left,mid-1);
    else findKthElement(numAdd-1,mid+1,right);
}

int main(){
    int test;
    cin >> test;
    while(test--){
        cin >> n >> k;
        long long l=1,numAdd=1;
        for(int i = 1; i < n; i++) {
            l = 2*l+1;
            numAdd++;
        }
        cout << findKthElement(numAdd,1,l) << endl;
    }
    return 0;
}
