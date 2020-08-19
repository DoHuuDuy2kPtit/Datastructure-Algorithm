#include<iostream>

using namespace std;

int testCase;

void solve(int a, long long b,int dh[][2]) {
    long long MIN = 1000000000000;
    long long x = b;
    for(int i = 0; i < a; i++) {
        if(dh[i][0] <= dh[i][1]) continue;
        long long count = 0;
        while(x > 0 && count < MIN) {
            x = x - dh[i][0];
            if(x > 0) {
                x = x + dh[i][1];
            }else {
                testCase++;
            }
            count++;
        }
        x = b;
        if(count < MIN) {
            MIN = count;
        }
    }
    if(testCase == 0) {
        cout << "MISSION FAILED!" << endl;
    } else
    cout << MIN << endl;
}

int main() {
    int test;
    cin >> test;
    while(test--) {
        int a;
        long long b;
        testCase = 0;
        cin >> a >> b;
        int dh[150][2];
        for(int i = 0; i < a; i++) {
            for(int j = 0; j < 2; j++) {
                cin >> dh[i][j];
            }
        }
        solve(a,b,dh);
    }
    return 0;
}
