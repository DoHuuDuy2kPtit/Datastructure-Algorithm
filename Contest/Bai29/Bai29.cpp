#include<iostream>

using namespace std;

int m,n;
int a[100][100];
int count;


void Try(int i, int j) {
    if(a[i+1][j] > 0 && i < m) {
        Try(i+1,j);
    }
    if(a[i][j+1] > 0 && j < n) {
        Try(i,j+1);
    }
    if(i == m && j == n) {
        count++;
    }
}

// Công thức tổ hợp C(k,n) = n*(n-1)*(n-2)...*(n-k+1) / 1*2*3...*k;

int toHop(int k, int n) {
    if(k==0) return 1;
    else {
        int c =1;
        for(int i=1; i <= k; i++,n--) {
            c = c*n/i;
        }
        return c;
    }
}

int main()
{
    int test;
    cin >> test;
    while(test--) {
        cin >> m >> n;
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                cin >> a[i][j];
            }
        }
        count = 0;
        int k = n-1;

        int b = m+n-2;
        cout << toHop(k,b) << endl;
        //cout << count << endl;
    }

}
