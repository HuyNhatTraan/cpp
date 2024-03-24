// Ho va Ten: Tran Nhat Huy
// MSSV: 221A010568

#include <bits/stdc++.h>
using namespace std;

// 1. Nhập xuất mảng một chiều.
// 2. Sắp xếp mảng tăng dần theo phương pháp đổi chỗ trực tiếp.
const int MAX = 100;

void nhapXuatMang1D(int arr[MAX], int &n){
    cout << "Hay nhap so phan tu co trong mang: "; cin >> n;
    // Nhap mang 1 chieu
    for (int i = 0; i < n; i++)
    {
        cout << "Hay nhap [" << i << "]: ";
        cin >> arr[i];
    }
    // Xuat mang 1 chieu
    cout << "Mang 1 chieu da nhap la: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int arr[MAX], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout << "Mang 1 chieu sau khi dc sort lai la: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main(){
    int arr[MAX], n;
    nhapXuatMang1D(arr, n);
    bubbleSort(arr, n);
    return 0;
}
