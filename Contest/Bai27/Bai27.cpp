#include<bits/stdc++.h>

using namespace std;

int sum;
int k;
bool chuaxet[100];
int n, testCase;

// Để chia được thành k (k < n) tập có tổng bằng nhau thì tổng các phần tử phải chia hết cho k

void Try(int i,int a[],int sotap, int total) {
    if(sotap == k-1) testCase++;
    if(testCase>0) return;
    for(int j = 1; j<=n; j++) {
        if(chuaxet[j] == true) {
            total+=a[j];
            chuaxet[j] = false;
            if(total >= sum/k || i == n) {
                if(total == sum/k) {
                    sotap++;
                    total = 0;
                }
            }
            else Try(i+1,a,sotap,total);
            total-=a[j];
            chuaxet[j] = true;
        }
    }
}

bool solve(int a[]) {
    if(sum%k != 0) return false;
    else {
        if(k > n) return false;
        else
        {
            Try(1,a,0,0);
            if(testCase==0) return false;
            else return true;
        }
    }
}

int main() {
    int test;
    cin >> test;
    while(test--) {
        int a[100];
        sum = 0;
        cin >> n >> k;
        for(int i = 1; i <=n ;i++) {
            cin >> a[i];
            sum += a[i];
            chuaxet[i] = true;
        }
        int sotap = 0;
        int total;
        testCase = 0;
        cout << solve(a) << endl;
    }
    return 0;
}
