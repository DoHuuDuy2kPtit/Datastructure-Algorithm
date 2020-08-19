#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        bool test = true;
        bool check[n+1];
        for(int i = 2; i <= n; i++) check[i] = true;

        for(int i = 2; i <= n; i++){
            if(check[i]==true){
                for(int j = 2*i; j <= n; j+=i){
                    check[j] = false;
                }
            }
        }

        for(int i = 2; 2*i <= n; i++){
            if(check[i] && check[n-i]) {
                test = false;
                cout << i << " " << n-i;
                break;
            }
        }
        if(test) cout << -1;
        cout << endl;
    }
}
