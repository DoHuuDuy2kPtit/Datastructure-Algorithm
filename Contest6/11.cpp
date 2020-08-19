#include<bits/stdc++.h>

using namespace std;

int partition(int a[],int low,int high){
    int x = a[high];
    int i = low-1;
    for(int j= low; j < high; j++){
        if(a[j] <=x){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[high]);
    return i+1;
}

void quickSort(int a[],int low, int high){
    if(low < high) {
        int p = partition(a,low,high);
        quickSort(a,low,p-1);
        quickSort(a,p+1,high);
    }
}

int sumClosestZero(int a[],int n){
    int sum, min_sum = INT_MAX;
    int l =0;
    int r = n-1;
    int min_l = l;
    int min_r = n-1;

    quickSort(a,l,r);

    while(l < r){
        sum = a[l]+a[r];
        if(abs(sum)<abs(min_sum)){
            min_sum = sum;
            min_l = l;
            min_r = r;
        }
        if(sum < 0){
            l++;
        }
        else{
            r--;
        }
    }
    return min_sum;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n+1];
        for(int i = 0; i < n; i++) cin >> a[i];
        cout << sumClosestZero(a,n) << endl;
    }
    return 0;
}
