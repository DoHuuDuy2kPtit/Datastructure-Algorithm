#include<bits/stdc++.h>

using namespace std;

int main(){
    int len;
    cin >> len;
    int a[len];
    for(int i = 0; i < len; i++) cin >> a[i];
    bool falsE=true; int step=1;
        while(falsE){
            int count=0;
            for(int i=1;i<len;i++){
                if(a[i]<a[i-1]) {swap(a[i],a[i-1]);
                count++;}
            }
            if(count==0) falsE=false;
            else{
                 cout<<"Buoc "<<step++<<": ";
                for(int j=0;j<len;j++) cout<<a[j]<<" ";
                cout<<endl;
            }
        }
}
