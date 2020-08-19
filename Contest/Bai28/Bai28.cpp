#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int sum;
vector<int> result;
int n,x;
int testCase;

void display() {
    cout << "[";
    for(int i = 1; i < result.size()-1;i++) {
        cout << result[i] << " ";
    }
    cout << result[result.size()-1] << "] ";
}

bool check() {
    for(int i = 0; i < result.size()-1;i++) {
        if(result[i] > result[i+1]) return false;
    }
    return true;
}


void Try(int i,int a[]) {
    for(int j = 1; j <= n; j++) {
        if(a[j] >= result[i-1]) {
            result.push_back(a[j]);
            sum += a[j];
            if(sum >= x || i == n) {
                if(sum == x) {
                    testCase++;
                    display();
                }
            }
            else Try(i+1,a);
            sum-=a[j];
            result.pop_back();
        }
    }
}

int main() {
    int test;
    cin >> test;
    while(test--) {
        cin >> n >> x;
        int a[100];
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a+1,a+n+1);
        testCase = 0;
        sum = 0;
        result.push_back(0);
        Try(1,a);
        if(testCase == 0) cout << -1;
        result.clear();
        cout << endl;
    }
    return 0;
}
