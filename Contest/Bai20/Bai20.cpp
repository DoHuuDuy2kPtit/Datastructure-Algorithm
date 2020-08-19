#include<iostream>
#include<vector>

using namespace std;

// Cách thức hoạt động của hàm Xuất màn hình:
// Đầu vào là vector<int> output và n;
// Khởi tạo giá trị count = 1;
// Khởi tạo giá trị bắt đầu in là m = k - 1;
// Khởi tạo giá trị kết thúc in là k = k.size();
// 1. Ta sẽ thực hiện in từ vị trí m đến vị trí k-2;
// 2. Sau đó ta mới in vị trị k-1;
// 3. Cập nhập lại vị trí bắt đầu là m = m - count;
// 4. Cập nhập lại vị trí kết thúc là k = k - count + 1;
// Các bước trên lặp cho đến khi count > n; 


void display(vector<int> output,int n) {
    int k = output.size();
    int count = 1;
    int m = k-1;
    while(count <= n){
        cout << "[";
        for(int i = m;i < k -1; i++) {
            cout << output[i] << " ";
        }
        cout << output[k-1] << "] ";
        count++;
        k = k - count + 1;
        m = m - count ;
    }
}

void recursion(int result[], int a[], int n,vector<int> &output) {
    if(n == 0) return;
    else {
        for(int i = 0; i < n-1; i++) {
            result[i] = a[i] + a[i+1];                  // Lưu kết quả của phép tính a[i] + a[i+1] vào mảng result
            output.push_back(result[i]);                // Đẩy kết quả trên vào trong output   
        }
        for(int i = 0; i < n-1; i++) {
            a[i] = result[i];                           // Gán lại kết quả cho a[i]
        }
        recursion(result,a,n-1,output);                 // Thực hiện đệ quy 
    }
}

int main()
{
    int n;
    int result[100];
    int a[100];
    vector<int> output;
    int test;
    cin >> test;
    while(test--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            output.push_back(a[i]);
        }
        recursion(result,a,n,output);
        display(output,n);
        cout << endl;
    }
    return 0;
}
