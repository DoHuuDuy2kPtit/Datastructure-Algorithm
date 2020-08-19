#include<iostream>

using namespace std;

void sort(int d[],int h[],int a) {
    for(int i = 0; i < a; i++) {
        for(int j = 0; j < a-i-1; j++) {
            if(d[j] < d[j+1]) {
                int temp = d[j];
                d[j] = d[j+1];
                d[j+1] = temp;
                temp = h[j];
                h[j] = h[j+1];
                h[j+1] = temp;
            }
        }
    }

}

void solve(int d[],int h[],int a,long long b) {
    sort(d,h,a);
    int testCase = 0;
    int count = 0;
    for(int i = 0; i < a; i++) {
        if(d[i] <= h[i]) continue;
        while(b > 0) {
            b = b - d[0];
            if(b > 0) {
                b = b + h[0];
            }else {
                testCase++;
            }
            count++;
        }
        break;
    }
    if(testCase != 0) {
        cout << count << endl;
    } else {
        cout << "MISSION FAILED!" << endl;
    }
}

int main() {
    //int test;
    //cin >> test;
    //while(test--) {
        int a;
        int d[200];
        int h[200];
        long long b;
        cin >> a >> b;
        for(int i = 0; i < a; i++) {
            cin >> d[i];
            cin >> h[i];
        }
        sort(d,h,a);

    //}
    for(int i = 0; i < a; i++) {
        cout << d[i] << " " << h[i] << endl;
    }
    return 0;
}
