#include<bits/stdc++.h>

using namespace std;

int main(){
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        int a[n];
        for(int i =0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < n-1; i++){
            int testcase = 0;
            for(int j = i+1; j < n;j++){
                if(a[j]>a[i]) {
                    testcase = 1;
                    a[i] = a[j];
                    break;
                }
            }
            if(testcase == 0) a[i] = -1;
            cout << a[i] << " ";
        }
        cout << -1 << endl;
    }
}
