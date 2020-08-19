#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

vector<long long> result;

bool check(long long n,long long m) {
    long long c = sqrt(n);
    long long l, r;
    long long x, y;
    for(long long i = 2; i <= c; i++) {
        if(n%i==0) {
            x = n/i;
            y = i;
            if((y+x-1)%2==0) {
                r = (y+x-1)/2;
                l = x - r;
                if(l >= 1 && r > 1) {
                    result.push_back(r - l + 1);
                }
            }
        }
    }
    for(int j = 0; j < result.size(); j++) {
        if(result[j]== m) return true;
    }
    if(n == m) return true;
    if(m == 1) return true;
    return false;
}

void solve(long long a[],long long n) {
    int count = 0;
    for(int i = 0; i < n-1; i++) {
        if(check(2*a[i],a[i+1]));
        else {
            for(int j = 0; j < result.size(); j++) {
               a[i+1] = result[j];
               break;
            //cout << result[j] << " ";
            }
            //cout << endl;
            count++;
            result.clear();
        }
    }
    //for(int i = 0; i < n; i++) {
        //cout << a[i] << " ";
    //}
    //cout << endl;
    cout << count << endl;
}

int main() {
    long long a[5000], n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    solve(a,n);
    return 0;
}
