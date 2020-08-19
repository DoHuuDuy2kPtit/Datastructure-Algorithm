#include<iostream>
#include<vector>

using namespace std;

vector<char> s;
int n;
int a[100][100];
int test1;

// Kiểm tra ô bên dưới có bằng 1 không nếu có thì gọi đệ quy tại ô đó
// Kiểm tra ô bên phải có bằng 1 hay không, nếu cí thì gọi đệ quy tại ô đó
// Chú ý luôn phải xét ô bên dưới trước ô bên phải sau

void Try(int i, int j) {
    if(a[i+1][j]==0 && a[i][j+1] == 0) {
        return;
    }
    if(a[i+1][j]==1) {
            s.push_back('D');
            Try(i+1,j);
            s.pop_back();
    }
    if(a[i][j+1]==1) {
            s.push_back('R');
            Try(i,j+1);
            s.pop_back();
    }
    if(i==n && j == n) {
        test1++;
        for(int i = 0; i < s.size(); i++) {
            cout << s[i];
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
        cin >> n;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    if(a[1][1] == 0 || a[n][n] == 0) {
        ;
    }
    else Try(1,1);
    if(test1 == 0) cout << "-1";
    s.clear();
    cout << endl;
    }
    return 0;
}
