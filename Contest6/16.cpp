#include<bits/stdc++.h>

using namespace std;

// int partition(int a[],int low,int high){
//     int x = a[high];
//     int i = low-1;
//     for(int j= low; j < high; j++){
//         if(a[j] <=x){
//             i++;
//             swap(a[i],a[j]);
//         }
//     }
//     swap(a[i+1],a[high]);
//     return i+1;
// }

int partition(int a[],int low,int hight)
{
    int x = a[hight];
    int left = low;
    int right = hight-1;
    while(true){
        while(left <= right && a[left] < x) left++;
        while(left <= right && a[right] > x) right--;
        if(left >= right) break;
        swap(a[left],a[right]);
        left++;
        right--;
    }
    swap(a[left],a[hight]);
    return left;
}

void quickSort(int a[],int low, int high){
    if(low < high) {
        int p = partition(a,low,high);
        quickSort(a,low,p-1);
        quickSort(a,p+1,high);
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        quickSort(a,0,n-1);
        for(int i = 0; i < n; i++) cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}
