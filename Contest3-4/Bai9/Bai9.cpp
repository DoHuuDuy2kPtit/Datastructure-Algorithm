#include<bits/stdc++.h>

using namespace std;

struct job {
    int index;
    int deadline;
    int profit;
};

bool compare(job a, job b){
    return a.profit > b.profit;
}

void solve(job a[], int n) {
    // Sắp xếp theo thứ tự tăng dần của profit
    sort(a,a+n,compare);
    bool mark[1000];
    int sum = 0;
    int count = 0;
    for(int i = 0; i < n; i++) {
        mark[i] = true;
    }
    // Chọn công việc ưu tiên theo gần deadline nhất
    for(int i = 0; i < n; i++) {
        for(int j = min(n,a[i].deadline)-1; j >=0 ; j--) {
            if(mark[j]==true) {
                sum += a[i].profit;
                mark[j] = false;
                count++;
                break;
            }
        }
    }
    cout << count << " " << sum << endl;
}

int main() {
    int test;
    cin >> test;
    while(test--) {
        int n;
        cin >> n;
        job a[1000];
        for(int i = 0; i < n; i++) {
            cin >> a[i].index >> a[i].deadline >> a[i].profit;
        }
        solve(a,n);
    }
    return 0;
}
