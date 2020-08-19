#include<bits/stdc++.h>

using namespace std;

// Sử dụng hàng đợi ưu tiên cho bài toán này
// Đưa các phần tử của mảng a vào hàng đợi pq
// Lặp cho đến khi pq chỉ còn 1 phần tử
// Ta lấy 2 phần tử đầu của pq rồi cộng chúng lại với nhau
// Giá trị sau khi cộng chúng lại sẽ được đẩy lại vào hàng đợi pq

void solve(int a[],int n){
    priority_queue< long long, vector<long long> , greater<long long> > pq;
    for(int i = 0; i < n; i++) {
        pq.push(a[i]);
    }
    long long sum = 0;
    while(pq.size()>1) {
        long long first = pq.top(); pq.pop();
        long long second = pq.top(); pq.pop();
        sum += first + second;
        pq.push(first+second);
    }
    cout << sum << endl;
}

int main(){
    int test;
    cin >> test;
    while(test--) {
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++) {
        cin >> a[i];
        }
        solve(a,n);
    }
    return 0;
}
