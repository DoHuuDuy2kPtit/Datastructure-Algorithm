#include<bits/stdc++.h>

using namespace std;

int* solve(int P[],int Q[],int m,int n){
    int *prod = new int[m+n-1];
    for(int i = 0; i < m+n-1; i++){
        prod[i] = 0;
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++) {
            prod[i+j] += P[i]*Q[j];
        }
    }
    return prod;
}

int main(){
    int test;
    cin >> test;
    while(test--) {
        int P[100];
        int Q[100];
        int m,n;
        cin >> m >> n;
        for(int i = 0; i < m; i++) cin >> P[i];
        for(int i = 0; i < n; i++) cin >> Q[i];
        int *prod = solve(P,Q,m,n);
        for(int i = 0; i < m+n-1; i++){
            cout <<  prod[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
