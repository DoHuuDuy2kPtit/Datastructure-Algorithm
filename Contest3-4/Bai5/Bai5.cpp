#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

// Sắp xếp mảng a[] theo thứ tự tăng dần
// 1. Tính tổng các phần tử
// 2. So sánh k và n-k xem cái nào lớn hơn
// 3. Tính tổng từ đầu đến phần tử vị trí thứ k nếu k lớn hơn n-k hoặc đến vị trí thứ n-k nếu n-k lớn hơn k
 

int solve(int a[], int n,int k) {
    int sumSubArr = 0;
    int sumArr = 0;
    for(int i = 1; i <= n; i++) {
        sumArr += a[i];
    }
    sort(a+1,a+n+1,greater<int>());
    int M = max(k,n-k);
    for(int i = 1; i <= M; i++) {
        sumSubArr += a[i];
    }
    return sumSubArr - (sumArr - sumSubArr);
}

int main() {
    int test;
    cin >> test;
    while(test--) {
        int n, k;
        int a[100];
        cin >> n >> k;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        cout << solve(a,n,k) << endl;
    }
    return 0;
}
