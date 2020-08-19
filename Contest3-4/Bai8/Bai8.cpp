#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

// Sắp xếp mảng công việc theo thứ tự tăng dần về thời gian kết thúc
// Nếu việc tại i có thời gian kết thúc sau thời gian bắt đầu của công việc j thì sẽ tăng lên 1 

// void sort(int start[],int finish[],int n) {
//     for(int i = 1; i < n; i++) {
//         for(int j = i+1; j <=n ;j++) {
//             if(finish[i] > finish[j]) {
//                 swap(finish[i],finish[j]);
//                 swap(start[i],start[j]);
//             }
//         }
//     }
// }

// void solve(int start[],int finish[],int n) {
//     sort(start,finish,n);
//     int i = 1;
//     int dem = 1;
//     for(int j = 2; j <= n; j++) {
//         if(finish[i] <= start[j]) {
//             dem++;
//             i = j;
//         }
//     }
//     cout << dem << endl;
// }

bool myCompare(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}

void solve(vector< pair<int,int> > a){
    int i = 0;
    int dem = 1;
    for(int j = 1; j < a.size(); j++){
        if(a[i].second <= a[j].first){
            dem++;
            i = j;
        }
    }
    cout << dem << endl;
}

int main() {
    int test;
    cin >> test;
    while(test--) {
        int n;
        cin >> n;
        vector< pair<int,int> > a;
        int start[n+1];
        int finish[n+1];
        for (int i = 0; i < n; i++)
        {
            cin >> start[i] ;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> finish[i] ;
        }

        for (int i = 0; i < n; i++)
        {
            a.push_back({start[i],finish[i]}) ;
        }
        sort(a.begin(),a.end(),myCompare);

        solve(a);
        // int start[n];
        // int finish[n];
        // for(int i = 1; i <= n; i++) {
        //     cin >> start[i];
        // }
        // for(int i = 1; i <= n; i++) {
        //     cin >> finish[i];
        // }
        // solve(start,finish,n);
    }
}
