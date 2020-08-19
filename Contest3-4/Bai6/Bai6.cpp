#include<bits/stdc++.h>

using namespace std;

// Sao chép mảng a ra mảng copy
// Sắp xếp mảng copy theo thứ tự tăng dần
// So sánh mảng copy với mảng a
// Nếu phần tử copy[i] != a[i] và copy[i] != a[n-1-i] thì không sắp xếp tham lam được
// Còn trong các trường hợp còn lại thì đều có thể sắp xếp tham lam được

bool checkArray(int a[],int copy[],int n) {
    sort(copy,copy+n);
    for(int i = 0; i < n; i++) {
        if(!(copy[i] == a[i]) && !(copy[i] == a[n-1-i]))
            return false;
    }
    return true;
}

int main() {
    int test;
    cin >> test;
    while(test--) {
        int n;
        int a[100], copy[100];
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            copy[i] = a[i];
        }
        if(checkArray(a,copy,n)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
