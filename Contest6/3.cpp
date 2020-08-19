#include<bits/stdc++.h>

using  namespace std;

int minSwap(int arr[],int n){
    vector< pair< int , int > > pos(n);
    for(int i = 0; i < n; i++){
        pos[i].first = arr[i];
        pos[i].second = i;
    }

    sort(pos.begin(),pos.end());

    int ans = 0;

    for(int i = 0; i < n; i++){
        if(i != pos[i].second) {
            swap(pos[i],pos[pos[i].second]);
            ans++;
        }
    }
    return ans;
}

int main(){
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++) cin >> arr[i];
        cout << minSwap(arr,n) << endl;
    }
}
