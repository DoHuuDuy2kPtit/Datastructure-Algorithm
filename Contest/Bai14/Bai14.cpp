#include<iostream>

using namespace std;

// Sử dụng 1 mảng rate[] để đánh giá những chiến sĩ được sử dụng
// rate[] = 1 là những chiến sĩ sử dụng lần 1
// rate[] = 2 là những chiến sĩ sử dụng lần 2
// Số lượng giá trị rate[] = 1 sẽ là số lượng chiến sĩ được tạm nghỉ

void init(int n, int rate[]){
    for(int i = 1; i <= n+1; i++) {
        rate[i] = 0;
    }
}

void nextCombination(int arr[],int n,int k,int rate[]) {
    for(int m = 1; m <= k; m++) {
        rate[arr[m]] = 1;
    }
    int i =k;
    int count = 0;
    while(arr[i] == n-k+i && i > 0) {
        i--;
    }
    if(i!=0){
        arr[i]++;
        for(int j = i+1; j <= n; j++){
            arr[j] = arr[j-1] + 1;
        }
        for(int m = 1; m <= k; m++) {
            rate[arr[m]] = 2;
        }
        for(int h = 1; h <= n ;h ++) {
            if(rate[h]==1) count++;
        }
        cout << count <<endl;
    }
    else cout << k << endl;

}

int main()
{
    int test;
    cin >> test;
    int n, k;
    int arr[100];
    int rate[100];
    while(test > 0) {
        cin >> n >> k;
        for(int i = 1; i <=k ; i++) {
            cin >> arr[i];
        }
        init(n, rate);
        nextCombination(arr,n,k,rate);
        test--;
    }
    return 0;
}
