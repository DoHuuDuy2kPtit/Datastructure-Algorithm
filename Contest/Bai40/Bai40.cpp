#include<iostream>

using namespace std;

int c[100][100], n;
bool chuaxet[100];
int x[100];
int MIN = 1000000;

void update() {
    int total = 0;
    for(int i = 1; i < n; i++) {
        total +=c[x[i]][x[i+1]];
    }
    total+= c[x[n]][x[1]];
    if(total < MIN) {
        MIN = total;
    }
}

void Try(int i) {
    for(int j = 1; j <= n ; j++) {
        if(chuaxet[j] == true) {
            x[i]=j;
            chuaxet[j] = false;
            if(i==n) {
                update();
            } else
                Try(i+1);
            chuaxet[j] = true;
        }
    }
}

int main() {
    cin >> n;
    for(int i = 1; i <=n ; i++) {
        chuaxet[i] = true;
        for(int j = 1; j <= n; j++) {
            cin >> c[i][j];
        }
    }
    Try(1);
    cout << MIN << endl;
    return 0;
}
