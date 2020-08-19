#include<iostream>
#include<algorithm>

using namespace std;

int n, k, checkCase;
void display(int result[], int a[]);

bool isEqualK(int result[],int a[]) {
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += a[i]*result[i];
    }
    return sum==k;
}

void Try(int i,int result[],int a[]){
    for(int j = 1; j >= 0; j--){
        result[i] = j;
        if(i==n){
            if(isEqualK(result,a)) display(result,a);
        }
        else Try(i+1,result,a);
    }
}

void display(int result[], int a[]) {
    checkCase = 1;
    int mark = 0;
    for(int i = n; i >= 1; i--) {
        if(result[i]){
            mark = i;
            break;
        }
    }
    cout << "[";
    for(int i = 1; i <= n; i++){
        if(result[i]){
            cout << a[i];
            if(i!=mark) cout<< " ";
        }
    }
    cout <<  "] ";
}

int main()
{
    int test;
    cin >> test;
    while(test--) {
        int result[100] = {0};
        int a[100];
        checkCase = 0;
        cin >> n >> k;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a+1,a+n+1);
        Try(1,result,a);
        if(checkCase == 0) cout << "-1";
        cout << endl;
    }
    return 0;
}
