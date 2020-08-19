#include<iostream>

using namespace std;

int arr[100];
int n;

// Thuật toán sinh hoán vị ngược ngược 
// 1. Duyệt từ cuối về, tìm vị trí sao cho a[j-1] > a[j];
// 2. Tìm phần thử a[k] sao cho a[k] là lớn nhất nhưng lại nhỏ hơn a[j-1] với k: j->n;
// 3. Đổi chỗ a[k] với a[j-1];
// 4. Lật ngược đoạn từ j->n;



void init() {
    cin >> n;
    int x = n;
    for(int i = 1; i <= n; i++) {
        arr[i] = x;
        x--;
    }
}

void nextPermutation() {
    int j = n;
    while(arr[j-1] < arr[j] && j>0) {
        j--;
    }
    int index;
    for(int k = j; k <= n; k++) {
        int max = 0;
        if(arr[j-1] > arr[k] && max < arr[k]) {
            max = arr[k];
            index = k;
        }
    }
    int temp = arr[index];
    arr[index] = arr[j-1];
    arr[j-1] =temp;
    int l = j;
    int r = n;
    while(l < r) {
        temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;
        l++;
        r--;
    }
}

void display() {
    for(int i = 1; i <= n; i++) {
        cout << arr[i];
    }
    cout << " ";
}

bool check() {
    for(int i = n ; i>0 ;i--) {
         if(arr[i] < arr[i-1]) return false;
    }
    return true;
}

int main()
{
    int test;
    cin >> test;
    while(test > 0) {
        init();
        while(check() == false) {
            display();
            nextPermutation();
        }
        display();
        cout<<endl;
        test--;
    }
    return 0;
}
