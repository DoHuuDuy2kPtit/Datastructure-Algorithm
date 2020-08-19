#include<bits/stdc++.h>

using namespace std;

long long partition(long long a[],long long low,long long high){
    long long x = a[high];
    long long i = low-1;
    for(long long j= low; j < high; j++){
        if(a[j] <=x){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[high]);
    return i+1;
}

void quickSort(long long a[],long long low,long long high){
    if(low < high) {
        int p = partition(a,low,high);
        quickSort(a,low,p-1);
        quickSort(a,p+1,high);
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n, m;
        cin >> n >> m;
        long long a[n];
        long long b[m];
        for(long long i = 0; i < n; i++) cin >> a[i];
        for(long long i = 0; i < m; i++) cin >> b[i];
        quickSort(a,0,n-1);
        quickSort(b,0,m-1);
        cout << (a[n-1]*b[0]) << endl;
    }
}
