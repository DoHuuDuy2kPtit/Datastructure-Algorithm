#include<iostream>

using namespace std;

int a[50];
int input[50];
int n, checkCase,total;

bool checkSum() {
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        sum+= a[i]*input[i];
    }
    return sum==(total/2);
}

void Try(int i) {
    if(checkCase) return;
    for(int j = 1; j >= 0; j--) {
        if(checkCase) return;
        a[i] = j;
        if(i == n) {
            if(checkSum()) {
                checkCase++;
                return;
            }
        }
        else Try(i+1);
    }
}

int main()
{
    int test;
    cin >> test;
    while(test--) {
        checkCase = 0;
        cin >> n;
        total = 0;
        for(int i = 1; i <= n; i++) {
            cin >> input[i];
            total += input[i];
        }
        if(total%2 != 0 || n==1 || (n==2 && a[1]!=a[2]));
        else Try(1);
        if(checkCase == 0) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}
