#include<iostream>
#include<vector>

using namespace std;

void solve(long long a[],long long b[],int n) {
    vector<int> left;
    vector<int> right;
    left.push_back(0);
    for(int i = 0; i < n-1; i++) {
        if(a[i] > a[i+1]) {
            right.push_back(i);
            left.push_back(i+1);
        }
    }
    right.push_back(n-1);
    int index;
    long long MAX = 0;
    for(int j = 0; j < left.size();j++) {
        long long total = 0;
        for(int i = left[j]; i <= right[j]; i++) {
            total+= b[i];
        }
        if(MAX < total) {
            MAX = total;
            index = j;
        }
    }
    cout << left[index] << " " << right[index] << endl;
}

void solve(long long a[],long long b[],int n) {
    long long MAX = 0;
    int index = 0;
    for(int i = 0; i < n; i++) {
        if(MAX <= a[i]) {
            MAX = a[i];
            index = i;
        }
    }
    int total = 0;
    for(int j = 0; j < index; j++) {
        total += b[i];
    }
    int sum = 0;
    for(int i = index; i < n; i++) {
        sum+= b[i];
    }
}

int main()
{
    long long a[100001];
    long long b[100001];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >>  b[i];
    }
    solve(a,b,n);
    return 0;
}
