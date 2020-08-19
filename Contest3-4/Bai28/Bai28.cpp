#include<bits/stdc++.h>

using namespace std;

// Sắp xếp mảng a (mảng chứa kích thước của kangaroo) theo thứ tự tăng dần về chiều cao
// Khởi tạo biến result = n;
// Duyệt từ n/2 -> 1: nếu a[i]*2 <= a[n] thì result--;
// Kết quả sẽ là biến result;

int main() {
    int test;
    cin >> test;
    while(test--) {
        int n;
        cin >> n;
        int a[n+1];
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a+1,a+n+1);
        int result = n;
        for(int i = n/2; i>=1; i--){
            if(a[i]*2 <= a[result]) result--;
        }
        cout << result << endl;
    }
}
