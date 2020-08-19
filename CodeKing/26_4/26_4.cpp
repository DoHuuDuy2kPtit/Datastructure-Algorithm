#include<iostream>
#include<vector>
#define LIM 100000

using namespace std;

int GCD(int a,int b) {
    while(b != 0) {
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}

bool check(vector<int> result, int x) {
    for(int i = 0; i < result.size();i++) {
        if(GCD(result[i],x) == 1) return false;
    }
    return true;
}

void solve(int a[],int n) {
    int MAX = 0;
    for(int i = 1; i <= n; i++) {
        vector<int> result;
        result.push_back(a[i]);
        for(int j = 1; j <= n; j++) {
            if(GCD(a[j],a[i]) == 1 || j == i) ;
            else {
                if(check(result,a[j]) == true) {
                    result.push_back(a[j]);
                }
            }

        }
        for(int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << endl;
        if(MAX < result.size()) {
            MAX = result.size();
        }
        result.clear();
    }
    cout << MAX << endl;
}


int main() {
    int n;
    int a[LIM];
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    solve(a,n);
}
