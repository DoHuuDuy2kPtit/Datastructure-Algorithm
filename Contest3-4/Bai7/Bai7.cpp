#include<bits/stdc++.h>
#define M 1000000007

using namespace std;

// Sắp xếp 1 mảng theo thứ tự tăng dần và 1 mảng theo thứ tự giảm dần
// Tính tổng sum = sum + a[i]*b[i];

void solve(vector<long long> a,vector<long long> b,int n) {
    sort(a.begin(),a.end());
    sort(b.begin(),b.end(),greater<int>());
    long long sum = 0;
    for(int i = 0; i < n; i++) {
        sum += (a[i])*(b[i]);
    }
    cout << sum << endl;
}

int main(){
    int test;
    cin >> test;
    while(test--) {
        vector<long long> a;
        vector<long long> b;
        int n;
        int temp;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> temp;
            a.push_back(temp);
        }
        for(int i = 0; i < n; i++) {
            cin >> temp;
            b.push_back(temp);
        }
        solve(a,b,n);
    }
    return 0;
}
