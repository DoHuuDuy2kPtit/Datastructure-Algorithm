#include<bits/stdc++.h>

using namespace std;

int preIndex = 1;

int searchRoot(int in[],int root, int startIn, int endIn)
{
    for(int i = startIn; i <= endIn; i++){
        if(in[i] == root) return i;
    }
    return -1;
}

void printPost(int in[], int pre[], int startIn,int endIn)
{
    if(startIn > endIn) return;

    int root = searchRoot(in,pre[preIndex++],startIn,endIn);

    printPost(in,pre,startIn,root-1);
    printPost(in,pre,root+1,endIn);

    cout << in[root] << " ";
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int in[n+1];
        int pre[n+1];
        for(int i = 1; i <= n; i++) cin >> in[i];
        for(int i = 1; i <= n; i++) cin >> pre[i];
        printPost(in,pre,1,n);
        cout << endl;
    }
}
