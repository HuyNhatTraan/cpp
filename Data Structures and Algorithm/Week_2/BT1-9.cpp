// Ho va Ten: Tran Nhat Huy
// MSSV: 221A010568
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
// BT1
void nhapMang1D(int arr[MAX], int &n){
    cout << "Hay nhap so phan tu co trong mang: "; cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Hay nhap ["<< i << "]: ";
        cin >> arr[i];
    }
}

void xuatMang1D(int arr[MAX], int n){
    cout << "Mang da nhap la: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
// BT2
void sum(int arr[MAX], int n){
    int tong = 0;
    for (int i = 0; i < n; i++)
    {
        tong += i;
    }
    cout << endl;
    cout << "Tong la: " << tong;
}
// BT 3 Dem so khong chan trong mang
void demSoKhongChan(int arr[MAX], int n){
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if ( arr[i] % 2 != 0){
            dem++;
        }
    }
    cout << endl;
    cout << "Tong so khong chan co trong mang la: " << dem;
}
//BT 4
void sumChan(int arr[MAX], int n){
    int tong = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            tong += i;
        }
        
    }
    cout << endl;
}
// BT 5 Tim so nhap vao x
void timKiem(int arr[MAX], int n){
    int x;
    cout << "Hay nhap so can tim: "; cin >> x;
    for (int i = 0; i < n; i++)
    {
        if ( x == arr[i])
        {
            cout << "Da tim thay so can tim!" << endl;
            cout << x;
        }   
    }
    cout << endl;
}
// BT6 viet ham phat sinh so ngau nhien 
void random(int arr[MAX], int n){
    cout << "Hay nhap so phan tu can ngau nhien: "; cin >> n;
    srand(time(0));
    cout << "Cac so ngau nhien trong mang la: " << endl;
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100 + 1;     
        cout << arr[i] << " ";   
    }
    cout << endl;
}
// BT7 random thu tu tang dan
void randomTangDan(int arr[MAX], int n){
    cout << "Hay nhap so phan tu can ngau nhien: "; cin >> n;
    srand(time(0));
    cout << "Cac so ngau nhien la: " << endl;
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100 + 1;        
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Cac so ngau nhien trong mang la (sap xep tang dan): " << endl;
    for (int i = 0; i < n; i++)
    {    
        sort(arr, arr + n);  
        cout << arr[i] << " ";
    }
    cout << endl;
    
}
// BT8 timKiemTuantu
void timKiemTuanTu(int arr[MAX], int n){
    int x;
    cout << "Hay nhap so can tim: "; cin >> x;
    bool timThay = false;
    for (int i = 0; i < n; i++)
    {
        if ( x == arr[i])
        {
            timThay = true;
            cout << "Da tim thay so can tim!" << endl;
            cout << x;
        }   
    } if (!timThay){
        cout << "Khong tim thay so ban vua nhap! ";
    }
    cout << endl;
}
// BT9 timKiemNhiPhan
void timKiemNhiPhan(int arr[MAX], int n){
    int x, left = 0, right = n - 1, mid;;
    cout << "Hay nhap so ban can tim: "; cin >> x;
    bool timThay = false;
    sort(arr, arr + n);
    for (int i = 0; i < right; i++){
        mid = (left + right) / 2;
        if (arr[mid] == x){
            timThay = true;
            cout << "Da tim thay du lieu " << x << endl;
            break;
        } else if (arr[mid] < x){
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (!timThay){
        cout << "Không tìm thấy số này! \n";
    }
}


int main(){
    int n, arr[MAX];
    nhapMang1D(arr, n); // B1
    xuatMang1D(arr, n);
    sum(arr, n); // B2
    demSoKhongChan(arr, n); // B3
    sumChan(arr, n); // B4
    timKiem(arr, n); // B5
    random(arr, n); // B6
    randomTangDan(arr, n); // B7
    timKiemTuanTu(arr, n);  // B8
    timKiemNhiPhan(arr, n); // B9
    return 0;
}
