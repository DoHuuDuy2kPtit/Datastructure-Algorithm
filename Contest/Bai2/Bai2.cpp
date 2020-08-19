#include<iostream>
#define MAX 10000

using namespace std;

void init(int arr[],int k) {
    for(int i = 1; i <= k; i++) {
        cin >> arr[i];
    }
}

// Sinh tổ hợp chập k của n
// Duyệt từ cuối về, tìm vị trí đầu tiên có arr[i] != n-k+i;
// 1. Nếu tìm thấy thì tăng arr[i] lên 1 và cập nhập các phần tử phía sau nó: arr[j] = arr[j-1] với j: i+1->k;
// 2. Nếu không tìm thấy thì reset về trạng thái ban đầu arr[i] = i với i: i->k; 

void nextCombination(int arr[],int n, int k) {
    int i = k;
    while(arr[i] == n-k+i && i > 0) {
        i--;
    }
    if(i != 0) {
        arr[i]++;
        for(int j = i+1; j <= k; j++) {
            arr[j] = arr[j-1] + 1;
        }
    }
    else {
        for(int i = 1 ; i <= k; i++) {
            arr[i] = i;
        }
    }
}

void display(int arr[],int k) {
    for(int i = 1; i<=k; i++) {
        cout << arr[i] << " ";
    }
    cout<<endl;
}

int main()
{
    int test;
    int arr[MAX];
    cin >> test;
    while(test > 0){
        int n;
        int k;
        cin>>n>>k;
        init(arr,k);
        nextCombination(arr,n,k);
        display(arr,k);
        test--;
    }
    return 0;
}
