#include<iostream>

using namespace std;

void solve(int a[],int n) {
    int MAX = 0;
    for(int i = 1; i <= n; i++) {
        if(MAX < a[i]) {
            MAX = a[i];
        }
    }
    int total = MAX - n;
    if(total%2==0) cout << "Bi" << endl;
    else cout << "Lema" << endl;
}

int main() {
    int test;
    cin >> test;
    while(test--){
        int a[200];
        int n;
        cin >> n;
        int count = 0;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            if(a[i]%2 == 0) count++;
        }
        if(count == n) cout << "Lema" << endl;
        else solve(a,n);
    }
    return 0;
}
