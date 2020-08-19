#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        long long a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a,a+n);
        long long result = 0;
        for(int i = 0; i < n-1; i++){
            if(a[i+1] - a[i] > 1) result += (a[i+1]-a[i]-1);
        }
        cout << result << endl;
    }
}
