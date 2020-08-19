#include<iostream>
#include<vector>

using namespace std;

vector<char> result;
bool chuaxet[100][100];
int a[100][100];
int n;
int test1;

// Kiểm tra ô bên dưới có bằng 1 và đã được xét hay chưa nếu bằng 1 và chưa được xét thì ta đệ quy ô đó
// -------- ô bên trái
// -------- ô bên phải
// -------- ô bên trên

void Try(int i, int j) {
    if(i < n && a[i+1][j] == 1 && chuaxet[i+1][j] == true) {
        chuaxet[i+1][j] = false;
        result.push_back('D');
        Try(i+1,j);
        result.pop_back();
        chuaxet[i+1][j] = true;
    }
    if(j > 1 && a[i][j-1] == 1 && chuaxet[i][j-1] == true) {
        chuaxet[i][j-1] = false;
        result.push_back('L');
        Try(i,j-1);
        result.pop_back();
        chuaxet[i][j-1] = true;
    }
    if(j < n && a[i][j+1] == 1 && chuaxet[i][j+1] == true) {
        chuaxet[i][j+1] = false;
        result.push_back('R');
        Try(i,j+1);
        result.pop_back();
        chuaxet[i][j+1] = true;
    }
    if(i > 1 && a[i-1][j] == 1 && chuaxet[i-1][j] == true) {
        chuaxet[i-1][j] = false;
        result.push_back('U');
        Try(i-1,j);
        result.pop_back();
        chuaxet[i-1][j] = true;
    }
    if(i == n && j == n) {
        test1++;
        for(int i = 0; i < result.size(); i++) {
            cout << result[i];
        }
        cout << " ";
        return;
    }
}

int main()
{
    int test;
    cin >> test;
    while(test--) {
        test1 = 0;
        cin >>  n;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                cin >> a[i][j];
                chuaxet[i][j] = true;
            }
        }
        chuaxet[1][1] = false;
    if(a[1][1] == 0 || a[n][n] == 0) ;
    else Try(1,1);
    if(test1 == 0) cout << -1;
    result.clear();
    cout << endl;
    }
    return 0;
}
