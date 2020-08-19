#include<bits/stdc++.h>

using namespace std;

long long n,index;
long long fibo[93];

string fibonacciString(long long n, long long index){
    if(n==1) return "A";
    if(n==2) return "B";
    if(index <= fibo[n-2]) return fibonacciString(n-2,index);
    else return fibonacciString(n-1,index - fibo[n-2]);
}


int main(){
    int test;
    cin >> test;
    fibo[1] = 1;
    fibo[2] = 1;
    for(int i = 3; i < 93; i++) {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    while(test--) {
        cin >> n >> index;
        cout << fibonacciString(n,index) << endl;
    }
}
