//#include<bits/stdc++.h>
//
//using namespace std;
//
//int n, m;
//
////void DFS(int u)
////{
////    stack<int> stk;
////    stk.push(u);
////    cout << u << " ";
////    chuaxet[u] = false;
////    while(!stk.empty())
////    {
////        int s = stk.top();
////        stk.pop();
////        for(int i = 0; i < a[s].size(); i++){
////            if(chuaxet[a[s][i]] && a[s][i]!=0){
////                stk.push(s);
////                stk.push(a[s][i]);
////                cout << a[s][i] << " ";
////                chuaxet[a[s][i]] = false;
////                break;
////            }
////        }
////    }
////    cout << endl;
////}
//
//void BFS(int u,vector<int> a[], bool chuaxet[]){
//    queue<int> q;
//    q.push(u);
//    chuaxet[u] = false;
//    while(!q.empty())
//    {
//        int s = q.front();
//        q.pop();
//        for(int i = 0; i < a[s].size(); i++){
//            if(chuaxet[a[s][i]]){
//                q.push(a[s][i]);
//                chuaxet[a[s][i]] = false;
//            }
//        }
//    }
//}
//
//bool check(bool chuaxet[]){
//    for(int i = 1; i <= n; i++){
//        if(chuaxet[i]) return false;
//    }
//    return true;
//}
//
//int main()
//{
//    int t;
//    cin >> t;
//    while(t--)
//    {
//        cin >> n >> m;
//        vector<int> a[n+1];
//        bool chuaxet[n+1];
//        for(int i = 1; i <= m; i++)
//        {
//            int u, v;
//            cin >> u >> v;
//            a[u].push_back(v);
//            a[v].push_back(u);
//        }
//        for(int i = 1; i <= n; i++) chuaxet[i] = true;
//        for(int i = 1; i <= n; i++){
//            for(int j = 0; j < a[i].size(); j++){
//                if(a[i][j] > i){
//                    int u = a[i][j];
//                    a[i][j] = 0;
//                    // DFS(1);
//                    BFS(1,a,chuaxet);
//                    if(check(chuaxet)==false) cout << i << " " << u << " ";
//                    a[i][j] = u;
//                    for(int i = 1; i <= n; i++) chuaxet[i] = true;
//                }
//
//            }
//        }
//    }
//}
//
#include<bits/stdc++.h>
using namespace std;
int dinh,canh;

int dem(vector<int> arr[]){
        vector<bool> vs; vs.resize(dinh);
        int res=0;
        for(int i=0;i<dinh;i++){
            if(!vs[i]){
                res++;

                //DFS
                vs[i]=true;
                stack<int> st;
                st.push(i);
                while(!st.empty()){
                    int temp=st.top(); st.pop();
                    for(int j=0;j<arr[temp].size();j++){
                        if(vs[arr[temp][j]]==false){
                            vs[arr[temp][j]]=true;
                            st.push(temp);
                            st.push(arr[temp][j]);
                        }
                    }
                }
            }
        }
        return res;
}

int dem2(vector<int> arr[],int dinhBoQua1,int dinhBoQua2){
        vector<bool> vs; vs.resize(dinh);
        int res=0;
        for(int i=0;i<dinh;i++){
            // if(i==dinhBoQua) continue;
            if(!vs[i]){
                res++;

                //DFS
                vs[i]=true;
                stack<int> st;
                st.push(i);
                while(!st.empty()){
                    int temp=st.top(); st.pop();
                    for(int j=0;j<arr[temp].size();j++){
                        if( (arr[temp][j]==dinhBoQua1 and temp==dinhBoQua2)
                            or (arr[temp][j]==dinhBoQua2 and temp==dinhBoQua1)
                            or vs[arr[temp][j]]==true );
                            else{
                            vs[arr[temp][j]]=true;
                            st.push(temp);
                            st.push(arr[temp][j]);
                        }
                    }
                }
            }
        }
        return res;
}


main(){
    int t;cin>>t;
    while(t--){
        //input
         cin>>dinh>>canh;
        vector<int> arr[dinh];
        vector<int> danhSachCanh[canh];
        for(int i=0;i<canh;i++){
            int temp1,temp2; cin>>temp1>>temp2;
            danhSachCanh[i].push_back(temp1-1);
            danhSachCanh[i].push_back(temp2-1);
            arr[temp1-1].push_back(temp2-1);
            arr[temp2-1].push_back(temp1-1);
        }

        //so tp lien thong


        int soThanhPhanLienThong=dem(arr);
        for(int i=0;i<canh;i++){
            if(dem2(arr,danhSachCanh[i][0],danhSachCanh[i][1])>soThanhPhanLienThong) cout<<danhSachCanh[i][0]+1<<" "<<danhSachCanh[i][1]+1<<" ";

        }
        // cout<<dem2(arr,1,4);
        cout<<endl;
    }
}



