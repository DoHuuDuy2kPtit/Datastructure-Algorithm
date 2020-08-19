#include<iostream>
#include<algorithm>
#include<vector>
#define M 1000000007


using namespace std;

void solve(vector<long long> a) {
    sort(a.begin(),a.end());
    long long sum = 0;
    for(int i = 0; i < a.size(); i++) {
        sum += (a[i]%M)*(i%M);
        sum = sum%M;
    }
    cout << sum << endl;
}

int main() {
    int test;
    cin >> test;
    while(test--) {
        long long n;
        long long x;
        vector<long long> a;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> x;
            a.push_back(x);
        }
        solve(a);
    }
    return 0;
}
