#include<iostream>
#include<vector>

using namespace std;

// Sinh hoán vị theo cột sau đó tỉnh tổng các phần tử tại matrix[i][col[i]];

vector<int> result;

void nextPermutation(int col[], int n) {
    int i = n - 1;
    while(col[i] < col[i-1] && i > 0) i--;
    int k = n - 1;
    while(col[k] < col[i-1]) k--;
    int temp = col[k];
    col[k] = col[i-1];
    col[i-1] = temp;
    int l = i;
    int r = n-1;
    while(l < r) {
        temp = col[l];
        col[l] = col[r];
        col[r] = temp;
        l++;
        r--;
    }
}

void display(vector<int> result, int n) {
    int countNum = 0;
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
        countNum++;
        if(countNum == n) {
            countNum = 0;
            cout << endl;
        }
    }
}

bool check(int col[], int n) {
    for(int i = n-1; i > 0; i--) {
        if(col[i] > col[i-1]) return false;
    }
    return true;
}

bool isEqualK(int col[], int matrix[][20], int &n, int &k){

    int total = 0;
    for(int i = 0; i < n; i++) {
        total += matrix[i][col[i]-1];
    }
    if(total == k) return true;
    else return false;
}

int main()
{
    int n,k, count = 0;
    int col[100];
    int matrix[20][20];
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        col[i] = (i+1);
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }
    while(check(col,n) != true) {
        if(isEqualK(col,matrix,n,k)== true) {
            for(int i = 0; i < n; i++) {
                result.push_back(col[i]);
            }
            count++;
        }
        nextPermutation(col,n);
    }
    if(isEqualK(col,matrix,n,k)== true) {
        for(int i = 0; i < n; i++) {
            result.push_back(col[i]);
        }
        count++;
    }
    cout << count << endl;
    display(result,n);
}
