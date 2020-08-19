#include<bits/stdc++.h>
using namespace std;

void merge(long long a[],long long n,long long b[],long long m){
    sort(a,a+n);
    sort(b,b+m);
    vector<long long> result;
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < n && j < m){
        if(a[i] < b[j]){
            result.push_back(a[i]);
            i++;
        }
        else {
            result.push_back(b[j]);
            j++;
        }
    }
    while(i < n){
        result.push_back(a[i]);
        i++;
    }
    while(j < m){
        result.push_back(b[j]);
        j++;
    }
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n,m;
        cin >> n >> m;
        long long a[n], b[m];
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int j = 0; j < m; j++) cin >> b[j];
        merge(a,n,b,m);
    }
    return 0;
}
