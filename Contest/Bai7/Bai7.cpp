#include<iostream>

using namespace std;

int n;
int arr[100];
int sum = 0;

// Hàm in 

void display() {
    int total = 0;
    cout << "(";
    for(int i = 1; i <= n ;i++) {
        cout<< arr[i];
        total += arr[i];
        if(total == n) {
            cout << ")";
            break;
        }
        cout<<" ";
    }
    cout << " ";
}

// Hàm kiểm tra giảm dần

bool checkDecre() {
    for(int i = 1;i< n;i++) {
        if(arr[i] < arr[i+1])
        {
            return false;
        }
    }
    return true;
}

// Hàm quay lui 
// Thử giá trị từ n-sum đến 1

 void Try(int i) {
    for(int j = n-sum ; j >= 1; j--) {
        if(arr[i] >= arr[i+1]){
            arr[i] = j;
            sum+=j;
        if(sum == n) {
            if(checkDecre()==true)
                display();
        }
        else Try(i+1);
        sum-=j;
        }
    }
}


int main()
{
    int test;
    cin >> test;
    while(test > 0) {
        cin >> n;
        for(int i = 0;i<=n;i++) {
            arr[i] = 0;
        }
        Try(1);
        cout<<endl;
        test--;
    }
    return 0;
}
