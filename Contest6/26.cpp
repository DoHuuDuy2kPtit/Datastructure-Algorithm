#include<bits/stdc++.h>

using namespace std;

int main(){
    int t = 1;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n-1; i++){
            cout << "Buoc " << i+1 << ": ";
            for(int j = i+1; j < n; j++){
                if(a[i] > a[j]){
                    swap(a[j],a[i]);
                }
            }
            for(int j = 0; j < n; j++) cout << a[j] <<  " ";
            cout << endl;
        }
    }
    return 0;
}
