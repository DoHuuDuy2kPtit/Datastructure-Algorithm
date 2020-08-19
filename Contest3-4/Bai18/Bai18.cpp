#include<bits/stdc++.h>

using namespace std;

// Thực hiện vòng lặp cho đến khi n <= 0
// 1. Nếu n%7 == 0 thì b++(biến lưu số các số 7) và n = n - 7;
// 2. Nếu n%4 == 0 thì a++(biến lưu số các số 4) và n = n - 4;
// 3. Nếu cả 2 trường hợp trên đều sai thì a++ và n = n - 4;
// Nếu n sau vòng lặp != 0 thì không thỏa mãn
// Ngược lại thì ta xuất ra màn hình a số 4 và b số 7; 

void solve(int n) {
    int a = 0, b = 0;
    while(n > 0) {
        if(n%7 == 0) {
            b++;
            n = n -7;
        } else if(n%4==0) {
            a++;
            n = n - 4;
        } else {
            a++;
            n = n - 4;
        }
    }
    if(n==0) {
        for(int i = 0; i < a; i++) {
            cout << 4;
        }
        for(int i = 0; i < b; i++) {
            cout << 7;
        }
        cout << endl;
    }
    else cout << -1 << endl;
}

int main(){
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        solve(n);
    }
}
