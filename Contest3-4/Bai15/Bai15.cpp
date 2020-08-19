#include<bits/stdc++.h>

using namespace std;

// Điều kiện để người đó không đủ lương thực để tồn tại là:
// 1. Đơn vị thức ăn tối đa người đó mua trong 1 ngày nhỏ hơn đơn vị lương thực một ngày cần để tồn tại
// 2. Tổng lượng thức ăn trong mua trong 6 ngày ít hơn tổng lượng thức ăn ăn trong 7 ngày và số lượng ngày tồn tại lớn hơn 7

void solve(int n, int s, int m) {
    if(n < m) {
        cout << -1 << endl;
        return;
    }
    if(6*n < m*7 && s >= 7) {
        cout << -1 << endl;
        return;
    }
    int count = (s*m)/n;
    if((s*m)%n != 0) count++;
    cout << count << endl;
    return;
}

int main(){
    int test;
    cin >> test;
    while(test--) {
        int n , s, m;
        cin >> n >> s >> m;
        solve(n,s,m);
    }
    return 0;
}
