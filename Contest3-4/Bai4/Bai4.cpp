#include<bits/stdc++.h>

using namespace std;

// Sắp xếp mảng a theo thứ tự tăng dần
// Số thứ nhất sẽ được tạo bởi các phần tử ở vị trí có i chẵn
// Số thứ hai sẽ được tạo bởi các phần tử ở vị trí có i lẻ

long long solve(int a[],int n) {
    long long firstNum = 0;
    long long secondNum = 0;
    sort(a,a+n);
    for(int i = 0; i < n; i++) {
        if(i%2==0) {
            firstNum = firstNum*10 + a[i];
        }
        else secondNum = secondNum*10 + a[i];
    }
    return firstNum + secondNum;
}

int main() {
    int test;
    cin >> test;
    while(test--) {
        int n;
        int a[50];
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << solve(a,n) << endl;
    }
    return 0;
}
