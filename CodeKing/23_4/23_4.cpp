#include<iostream>
#define M 1000000007

using namespace std;

void solve(int n,int x) {
    long long sumPerson = 1;
    int temp = 1+x;
    int i = 1;
    while(i < n) {
        sumPerson = temp*sumPerson;
        i++;
    }
    cout << sumPerson << endl;
}

int main()
{
    int test;
    cin >> test;
    while(test--) {
        int n;
        int x;
        cin >> x >> n;
        solve(n,x);

    }
    return 0;
}
