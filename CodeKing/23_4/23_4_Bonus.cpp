#include<iostream>

using namespace std;

void solve(int n,int m) {
    if(m%n != 0) {
        cout << -1 << endl;
        return;
    }
    else {
        int x = m/n;
        int count = 0;
        while(x%2 == 0 || x%3 == 0) {
            if(x%6 ==0 ) {
                x = x/6;
                count+=2;
            }
            if(x%2 == 0 ) {
                x = x /2;
                count++;
            }
            if(x%3 == 0) {
                x = x/3;
                count++;
            }
        }
        if(x == 1) cout << count << endl;
        else cout << -1 << endl;
    }
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    solve(n,m);
    return 0;
}
