#include<iostream>
#include<cstring>

using namespace std;

string dic[200];
bool chuaxet[10][10];
int k;
int testCase;
int m,n;

bool checkWord(string s) {
    for(int i = 0; i < k; i++) {
        if(s.compare(dic[i])) return true;
    }
    return false;
}

void findWord(char a[][10],int i,int j, string &s) {
    chuaxet[i][j] = false;
    s = s + a[i][j];
    if(checkWord(s)==true) {cout << s << " "; testCase++;}

    for(int row = i - 1; row <= i+1 && row <= m; row++) {
        for(int col = j-1; col <= j+1 && col <= n; col++) {
            if(chuaxet[row][col]==true && row >= 0 && col >= 0)
                findWord(a,row,col,s);
        }
    }
    s.erase(s.length()-1);
    chuaxet[i][j] = true;
}

int main() {
    int test;
    cin >> test;
    while(test--) {
        char a[10][10];
        testCase = 0;
        cin >> k >> m >> n;
        for(int i = 0; i < k; i++) {
            cin >> dic[i];
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                cin >> a[i][j];
                chuaxet[i][j] = true;
            }
        }
        string  s= "";
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                findWord(a,i,j,s);
            }
        }
        if(testCase == 0) cout << -1;
        cout <<endl;
    }
}
