#include<iostream>
#define M 1000000007

using namespace std;

long long binomialCoefficient ( int n, int k )
{
    long long res = 1;
    for ( int i = 1; i <= k ; i ++ , n-- )
    {
        res = res *n/i;
    }
    return res;
}

int solve(long long n) {
    if(n == 2) return 3;
    if(n == 3) return 6;
    else {
        return solve(n-1)*solve + solve(n-2)*solve(n-2);
    }
}

int main() {
    long long n;
    cin >> n;
    cout << solve(n) << endl;
}
