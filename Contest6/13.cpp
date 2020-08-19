#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x;
        int count = 0;
        cin >> n >> x;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i]==x) count++;
        }
        if(count != 0) cout << count << endl;
        else cout << -1 << endl;
    }
}
