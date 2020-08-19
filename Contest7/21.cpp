#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        int a[n];
        int b[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
            b[i] = a[i];
        }
        for(int i = 0; i < n-1; i++){
            int j = i + 1;
            while(j<n && a[j] <= a[i]) j++;
            if(j == n) a[i] = -1;
            else{
                int k = j+1;
                while(k < n && a[k] >= a[j]) k++;
                if(k == n) a[i] = -1;
                else a[i] = a[k];
            }
        }
        for(int i = 0; i < n-1; i++){
            cout << a[i] << " ";
        }
        cout << -1 << endl;
    }
}

