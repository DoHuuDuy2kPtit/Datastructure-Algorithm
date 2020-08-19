#include<iostream>

using namespace std;

// Duyệt từ cuối mảng money về, 
// nếu số tiền hiện có lớn hơn money[i] thì số tiền hiện có sẽ trừ đi money[i]
// nếu số tiến hiện có nhỏ hơn money[i] sẽ i--; 

void solve(int n,int money[]) {
    int i = 9;
    int count = 0;
    while(i >= 0) {
        if(n < money[i]) {
            i--;
        }else {
            n = n - money[i];
            count++;
        }
        if(n==0) break;
    }
    cout << count << endl;
}

int main() {
    int money[]= {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
    int test;
    cin >> test;
    while(test--) {
        int n;
        cin >> n;
        solve(n,money);
    }
    return 0;
}
