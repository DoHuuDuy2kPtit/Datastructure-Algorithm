#include<iostream>

using namespace std;

int a[10][10];
bool chuaxet[50], xuoi[50], nguoc[50];
int x[50];
int MAX;

int sum() {
    int total = 0;
    for(int j = 1; j<=8; j++) {
        total += x[j];
    }
    return total;
}

void Try(int i) {
    for(int j = 1; j <= 8; j++) {
        if(chuaxet[j] && xuoi[i-j+8] && nguoc[i+j-1]) {
            x[i] = a[i][j];
            chuaxet[j] = false;
            xuoi[i-j+8] = false;
            nguoc[i+j-1] = false;
            if(i==8) {
                if(MAX < sum()) {
                    MAX = sum();
                }
            }
            else Try(i+1);
            chuaxet[j] = true;
            xuoi[i-j+8] = true;
            nguoc[i+j-1] = true;
        }
    }
}

int main()
{
    int test;
    cin >> test;
    while(test--) {
        for(int i = 1; i <= 8; i++) {
            chuaxet[i] = true;
            for(int j =1; j <= 8; j++) {
                cin >> a[i][j];
            }
        }
        for(int i = 1; i <= 16; i++) {
            xuoi[i] = true;
            nguoc[i] = true;
        }
        MAX = 0;
        Try(1);
        cout << MAX << endl;
    }
}
