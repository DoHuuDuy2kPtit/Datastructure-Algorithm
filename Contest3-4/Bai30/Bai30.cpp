#include<bits/stdc++.h>
#define M 1000000007
using namespace std;

void multiply(long long matrixA[2][2], long long matrixB[2][2]) {
    long long x = ((matrixA[0][0]*matrixB[0][0])%M + (matrixA[0][1]*matrixB[1][0])%M)%M;
    long long y = ((matrixA[0][0]*matrixB[0][1])%M + (matrixA[0][1]*matrixB[1][1])%M)%M;
    long long z = ((matrixA[1][0]*matrixB[0][0])%M + (matrixA[1][1]*matrixB[1][0])%M)%M;
    long long t = ((matrixA[1][0]*matrixB[0][1])%M + (matrixA[1][1]*matrixB[1][1])%M)%M;

    matrixA[0][0] = x;
    matrixA[0][1] = y;
    matrixA[1][0] = z;
    matrixA[1][1] = t;
}

void power(long long matrixA[2][2], long long n){
    if(n==0 || n == 1) return;
    long long temp[2][2] = {{1,1},{1,0}};
    power(matrixA,n/2);
    multiply(matrixA,matrixA);
    if(n%2!=0) {
        multiply(matrixA,temp);
    }
}

long long solve(long long n) {
    long long matrixA[2][2] = {{1,1},{1,0}};
    if(n==0) return 0;
    power(matrixA,n-1);
    return matrixA[0][0];
}

int main() {
    int test;
    cin >> test;
    while(test--) {
        long long n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}
