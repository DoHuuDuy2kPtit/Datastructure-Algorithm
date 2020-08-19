#include<bits/stdc++.h>

using namespace std;



int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        int count = 0;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a, a + n);

        int res = 0;
        for (int i = 0; i < n; i++) {
            int j = i+1;
            while (j < n && a[j] - a[i] < k) {
                res++;
                j++;
            }
        }
        cout << res << endl;
    }
}
