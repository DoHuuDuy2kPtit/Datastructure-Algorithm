#include<bits/stdc++.h>

using namespace std;

// Điều kiện không thỏa mãn: 
// 1. Khi tổng s lớn hơn 9*d
// 2. Khi s = 1 nhưng d != 1;
// Cách làm:
// 1. Bớt s đi 1 đơn vị
// 2. Mảng res[] lưu kết quả
// 3. Duyệt mảng res từ d-1 đến 1;
// 4. Nếu s > 9 thì phần tử res[i] nhận giá trị là 9;
// 5. Nếu s < 9 thì phần tử res[i] nhận giá trị là s và cho s = 0;
// 6. Phần tử res[0] = s + 1;

void solve(int s, int d) {
    if(s > 9*d) {
        cout << -1 << endl;
        return;
    }
    if(s == 1) {
        if(d == 1) {
            cout << 1 << endl;
            return;
        }
        else {
            cout << -1 << endl;
            return;
        }
    }
    s-= 1;
    int res[d];
    for(int i = d-1; i > 0; i--) {
        if(s > 9) {
            res[i] = 9;
            s-=9;
        }
        else {
            res[i] = s;
            s = 0;
        }
    }
    res[0] = s + 1;
    for(int i = 0; i < d; i++) {
        cout << res[i];
    }
    cout << endl;
}

int main() {
    int test;
    cin >> test;
    while(test--) {
        int s, d;
        cin >> s >> d;
        solve(s,d);
    }
    return 0;
}
