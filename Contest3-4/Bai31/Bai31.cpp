#include<bits/stdc++.h>
#define ll long long
#define M 1000000007
#define matrix vector<vector<ll>>
using namespace std;

ll n,k;

matrix multiply2Matrix(matrix matrixA,matrix matrixB) {
    matrix matrixTemp;
    matrixTemp.resize(n);
    for(int i = 0; i<n; i++) {
        matrixTemp[i].resize(n);
        for(int j = 0; j < n; j++)
            for(int k = 0 ; k < n; k++)
                matrixTemp[i][j] = (matrixTemp[i][j]%M + ((matrixA[i][k]%M)*(matrixB[k][j]%M))%M)%M;
    }
    return matrixTemp;
}

matrix power(matrix matrixInput,long long k) {
    if(k==1) return matrixInput;
    matrix temp = power(matrixInput,k/2);
    if(k%2==0) return multiply2Matrix(temp,temp);
    else return multiply2Matrix(multiply2Matrix(temp,temp),matrixInput);
}


int main() {
    int test;
    cin >> test;
    while(test--) {
        cin >> n >> k;
        matrix matrixA;
        matrixA.resize(n);
        for(int i = 0; i < n; i++) {
            matrixA[i].resize(n);
            for(int j = 0; j < n; j++)
                cin >> matrixA[i][j];
        }
        matrix result = power(matrixA,k);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++)
                cout << result[i][j] << " ";
            cout << endl;
        }
    }
}
