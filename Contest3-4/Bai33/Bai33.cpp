#include<bits/stdc++.h>
#define M 1000000007

using namespace std;

long long power(long long n,long long m) {
    if(m==0) return 1;
    long long temp = power(n,m/2);
    if(m%2==0) return (temp%M*temp%M)%M;
    else return n*(temp%M*temp%M)%M;
}

long long reverseN(long long n) {
    long long m = 0;
    while(n > 0) {
        m = m*10+n%10;
        n = n/10;
    }
    return m;
}

int main() {
    int test;
    cin >> test;
    while(test--){
        long long n;
        cin >> n;
        long long m = reverseN(n);
        cout << power(n,m) << endl;
    }
    return 0;
}
