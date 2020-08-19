#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        long long a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        long long MIN = INT_MAX;
        for(int i = 0; i < n; i++){
            if(a[i] < MIN) MIN = a[i];
        }
        long long MIN2 = INT_MAX;
        for(int i = 0; i < n; i++){
            if(a[i]==MIN) continue;
            if(a[i] < MIN2) MIN2 = a[i];
        }
        if(MIN2 == INT_MAX) cout << -1 << endl;
        else cout << MIN << " " << MIN2 << endl;
    }
    return 0;
}
