#include<iostream>
#include<vector>

using namespace std;

int count = 0;

long long GCD(long long a,long long b) {
    long long r;
    while(b != 0) {
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

void solve(vector<long long> a) {
    long long temp = GCD(a[0],a[1]);
    for(int i = 2; i < a.size(); i++) {
        temp = GCD(temp,a[i]);
        if(temp == 1) break;
    }
    for(int i = 1; i <= temp; i++) {
        if(temp%i==0) count++;
    }
    cout << count << endl;
}

int main()
{
    int n;
    cin >> n;
    long long x;
    vector<long long> a;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        a.push_back(x);
    }
    solve(a);
    return 0;
}
