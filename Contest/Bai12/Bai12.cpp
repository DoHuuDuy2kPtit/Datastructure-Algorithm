#include<iostream>

using namespace std;

int arr[100];
int n,k;

// Quay lui/Sinh nhị phân sau đó kiểm tra xem có đúng k bit 1 không?

void display() {
    for(int i = 1; i <= n; i++) {
        cout<< arr[i];
    }
    cout<<endl;
}

bool check() {
    int count = 0;
    for(int i = 1; i <= n; i++) {
        if(arr[i]== 1) count ++;
    }
    if(count == k) return true;
    else return false;
}

void Try(int i) {
    for(int j = 0; j <= 1 ;j++) {
        arr[i] = j;
        if(i == n) {
            if(check()==true)
                display();
        }
        else Try(i+1);
    }
}

int main()
{
    int test;
    cin>>test;
    while(test > 0) {
        cin>>n;
        cin>>k;
        Try(1);
        test--;
    }
    return 0;
}
