#include<iostream>

using namespace std;

int arr[100];
int arr2[100];
int n;

// Thuật toán sinh mã gray:
// 1. Sinh nhị phân như bình thường
// 2. Sử dụng công thức gray = (binary<-1)^binary;


void init() {
    for(int i = 0; i <= n; i++) {
        arr[i] = 0;
    }
}

void nextBit() {
    int j = n;
    while(arr[j] == 1 && j > 0) {
        j--;
    }
    arr[j] = 1;
    for(int i = j+1; i<=n; i++) {
        arr[i] = 0;
    }
}

void toGray() {
    for(int i = 1; i <=n; i++) {
        arr2[i] = arr[i-1];
    }
    for(int i = 1; i <=n ; i++) {
        arr2[i] = (arr2[i]^arr[i]);
    }
}

void display(int arr[]) {
    for(int i = 1; i<=n; i++) {
        cout<<arr[i];
    }
    cout<< " ";
}

bool check() {
    for(int i = 1; i<=n ; i++) {
        if(arr[i] == 0) return false;
    }
    return true;
}

int main()
{
    int test;
    cin >> test;
    while(test > 0) {
        cin>>n;
        init();
        while(check()== false) {
            toGray();
            display(arr2);
            nextBit();
        }
        toGray();
        display(arr2);
        cout<<endl;
        test--;
    }
    return 0;
}
