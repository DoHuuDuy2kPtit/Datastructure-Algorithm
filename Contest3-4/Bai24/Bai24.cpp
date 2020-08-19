#include<bits/stdc++.h>
#define M 123456789

using namespace std;

// 1                                          ==> n = 1 co 1 day;
// 11 2                                       ==> n = 2 co 2 day;
// 111 21 12 3                                ==> n = 3 co 4 day;
// 1111 31 22 13 4 112 211 121                ==> n = 4 co 8 day;
// ........                                   ==> n = N co 2^(N-1) day;

long long power(long long n, long long k) {
    if(k==0) return 1;
    long long temp = power(n,k/2)%M;
    if(k%2 == 0) return (temp*temp)%M;
    else return (n*temp*temp)%M;
}

int main() {
    int test;
    cin >> test;
    while(test--) {
        long long n;
        cin >> n;
        cout << power(2,n-1) <<endl;
    }
    return 0;
}


