#include<bits/stdc++.h>
#define M 1000000007

using namespace std;

long long power(int n, int k) {
    if(k==0) {
        return 1;
    }
    long long temp = power(n,(k/2))%M;
    if(k%2==0) return temp%M*temp%M;
    return n%M*temp%M*temp%M;
}

int main(){
    int test;
    cin >> test;
    while(test--) {
        long long n,k;
        cin >> n >> k;
        cout << power(n,k) << endl;
    }
    return 0;
}
