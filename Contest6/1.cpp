#include<bits/stdc++.h>

using namespace std;

int partition(int a[], int low, int high){
    int pivot = a[high];
    int left = low;
    int right = high-1;
    while(true){
        while(left <= right && a[left] < pivot) left++;
        while(right >= left && a[right] > pivot) right--;
        if(left>= right) break;
        swap(a[left],a[right]);
        left++;
        right--;
    }
    swap(a[left],a[high]);
    return left;
}

void quickSort(int a[],int low, int high){
    if(low < high){
        int p = partition(a,low,high);
        quickSort(a,low,p-1);
        quickSort(a,p+1,high);
    }
}

int main(){
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        int a[n];
        for(int i = 1; i <= n; i++) cin >> a[i];
        quickSort(a,1,n);
        int i = 1;
        int j = n;
        while(i <= j){
            if(i==j){
                cout << a[i] << " ";
            } else {
                cout << a[j] << " " << a[i] << " ";
            }
            i++;
            j--;
        }
        cout << endl;
    }
}
