#include<iostream>

using namespace std;

bool chuaxet[20], xuoi[50], nguoc[50];
int n, count;

void Try(int i) {
    for(int j = 1; j <=n ;j++) {
        if(chuaxet[j]==true && xuoi[i-j+n]==true && nguoc[i+j-1]==true) {
            chuaxet[j] = false;
            xuoi[i-j+n] = false;
            nguoc[i+j-1] = false;
            if(i==n) {
                count++;
            }
            else Try(i+1);
            chuaxet[j] = true;
            xuoi[i-j+n] = true;
            nguoc[i+j-1] = true;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--){
    cin >> n;
    count = 0;
    for(int i = 1; i <=n; i++) {
        chuaxet[i] = true;
    }
    for(int i = 1; i <= 2*n; i++) {
        xuoi[i] = true;
        nguoc[i] = true;
    }
    Try(1);
    cout << count << endl;
    }
}
