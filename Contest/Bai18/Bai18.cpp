#include<iostream>
#include<algorithm>
using namespace std;

int a[50];
int s;
int n;
int count1 = 0;

void Try() {
    int i = n;
    while(i > 0) {
        if(s >= a[i]) {
            s-= a[i];
            count1++;
        }
        else {
            i--;
        }
    }
}

int main() {

    cin >> n >> s;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    Try();
    cout << count1 << endl;
}

