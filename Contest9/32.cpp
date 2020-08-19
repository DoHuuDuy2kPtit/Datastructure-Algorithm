#include<bits/stdc++.h>

using namespace std;

int n, m;
int rowNbr[] = {-1, -1, -1, 0, 0, 1, 1,1};
int colNbr[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool isSafe(int a[][502],int row, int col, bool chuaxet[][502]){
    return (row>=0) && (row<n) && (col>=0) && (col<m) && (a[row][col] && chuaxet[row][col]);
}

void DFS(int a[][502], int row, int col, bool chuaxet[][502]){
    chuaxet[row][col] = false;
    for(int i = 0; i < 8; i++){
        if(isSafe(a,row+rowNbr[i],col+colNbr[i],chuaxet))
        DFS(a,row+rowNbr[i],col+colNbr[i],chuaxet);
    }
}

int countIsland(int a[][502], bool chuaxet[][502])
{
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] && chuaxet[i][j]){
                DFS(a,i,j,chuaxet);
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        int a[502][502];
        bool chuaxet[502][502];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> a[i][j];
                chuaxet[i][j] = true;
            }
        }
        cout << countIsland(a,chuaxet) << endl;
    }
}
