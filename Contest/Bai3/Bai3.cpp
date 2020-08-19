#include<iostream>
#define MAX 10000

using namespace std;

// Sinh hoán vị
// Duyệt từ cuối về đầu tìm phần tử đầu tiên sao cho a[i] > a[i-1];
// 1. Nếu tìm thấy: 
//    + Ta tìm phần tử từ vị trí thứ n đến vị trí thứ i a[k] > a[i-1];
//    + Đổi chỗ a[k] với a[i-1];
//    + Lật ngược lại đoạn từ a[i] đến a[n];
// 2. Nếu không tìm thấy thì reset về trạng thái ban đầu.

void init(int arr[], int n) {
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
}

void swap1(int &m, int &n) {
    int temp;
    temp = m;
    m = n;
    n =temp;
}



void nextPermutation(int arr[], int &n) {
    int i = n;
    while(arr[i] <= arr[i-1] && i > 0) {
        i--;
    }
    if((i-1) != 0) {
        int k = n;
        while(arr[k] < arr[i-1]) {
            k--;
        }
        swap1(arr[k],arr[i-1]);
        int l = i;
        int r = n;
        while(l < r) {
            swap1(arr[l],arr[r]);
            l++;
            r--;
        }
    }
    else {

        for(int j = 1; j <= n; j++) {
            arr[j] = j;
        }
    }
}

void display(int arr[], int n) {
    for(int i = 1; i <= n ;i++) {
        cout << arr[i] << " ";
    }
    cout<<endl;
}

int main()
{
    int test,n;
    int arr[MAX];
    cin>>test;
    while(test > 0) {
        cin >> n;
        init(arr,n);
        nextPermutation(arr,n);
        display(arr,n);
        test--;
    }
}
