#include<bits/stdc++.h>
#define M 1000000007

using namespace std;

void solve(long long a[],long long n) {
    priority_queue< long long , vector<long long> , greater<long long> > pq(a,a+n);
    // for(int i = 0; i < n; i++) {
    //     pq.push(a[i]);
    // }
    long long sum = 0;
    while(pq.size() > 1) {
        long long first = pq.top(); pq.pop();
        long long second = pq.top(); pq.pop();
        sum = sum%M + ((first%M) + (second%M))%M;
        sum = sum%M;
        pq.push((first%M + second%M)%M);
    }
    cout << sum << endl;
}

int main(){
    long long n;
    cin >> n;
    long long a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    solve(a,n);
    return 0;
}
