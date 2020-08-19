#include<bits/stdc++.h>

using namespace std;

int main(){
    long long t; cin>>t;
    while(t--){
        bool check=true;
        long long res;
        int len;
        cin>>len;
        long long a[len];
        for(long long i=1;i<len;i++) {cin>>a[i]; if(check&&a[i]!=i) {res=i;check=false;}}
        cout<<(check?len:res)<<endl;
    }
}
