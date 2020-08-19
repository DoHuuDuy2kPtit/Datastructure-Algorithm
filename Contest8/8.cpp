#include<bits/stdc++.h>

using namespace std;

// Đẩy 1 vào q;
// Lặp cho đến khi q.front() % n == 0:
// Đẩy (q.front + 0) vào q;
// Đẩy (q.front + 1) vào q;
// Xóa phần tử đầu tiên trong q;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        queue<string> q;
        q.push("1");
        while(stoi(q.front())%n != 0){
            q.push(q.front()+"0");
            q.push(q.front()+"1");
            q.pop();
        }
        cout << q.front()<< endl;
    }
}
