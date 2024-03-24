// Ho va ten: Tran Nhat Huy 
// MSSV: 221A010568
#include <bits/stdc++.h>    // #include <iostream, ctime, algorithm, stdlib.h>
using namespace std;

/*  Viet chuong trinh thuc hien cac yeu cau sao voi mang 1 chieu 
    cac so nguyen co N phan tu dc phat sinh ngau nhien:
        1. In ra mang.
        2. Tim gia tri lon nhat trong mang.
        3. Tim vi tri do chua gia tri lon nhat trong mang.
        4. Tim tat ca cac vi tri co chua gia tri lon nhat
        5. Tim vi tri co gia tri x duoc nhap tu ban phim bang tim kiem tuyen tinh.
*/

void hamRandom(int arr[], int &n){
    cout << "Hay nhap so phan tu ban muon co trong mang : "; cin >> n;
    srand((int)time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1;
    }
    cout << "Mang sau khi random -> ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}   

void MaxNum(int arr[], int n){
    for (int i = 0; i < n; i++) {
        sort(arr, arr + n);
    }
    cout << "So lon nhat trong mang la: " << arr[n-1] << endl;
}

void viTriMax(int arr[], int n){
    int maxpos = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > maxpos){
            maxpos = i;
        }
    }
    cout << "So lon nhat o vi tri thu " << maxpos << endl;
}

void allMaxPos(int arr[], int n) {
    int allpos = 0;
    cout << "Tat ca cac so lon nhat o vi tri thu: ";
    for (int i = 0; i < n; i++) {
        if (arr[i] == allpos) {
            cout << i << " ";
        }
    }
    cout << endl;
}

void timKiemTuyenTinh(int arr[], int n){
    int key;
    cout << "Hay nhap so ban can tim: "; cin >> key;
    bool timthay = false;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key){
            timthay = true;
            cout << "Da tim thay so ban can tim: " << key << endl;
            break;
        }
    }
    if (!timthay){
        cout << "Khong tim thay so nay trong mang!" << endl;
    }
}

void menu(){
    cout << "=========================== Menu =========================== \n";
    cout << "1. In mang ra man hinh." << endl;
    cout << "2. Tim gia tri lon nhat trong mang." << endl;
    cout << "3. Tim vi tri do chua gia tri lon nhat trong mang." << endl;
    cout << "4. Tim tat ca cac vi tri co chua gia tri lon nhat!" << endl;
    cout << "5. Tim vi tri co gia tri x duoc nhap tu ban phim bang tim kiem tuyen tinh." << endl;
    cout << "6. Thoat khoi menu." << endl;
    cout << "=========================== [01] ============================ \n";
    cout << "Hay nhap lua chon cua ban: ";
}

int main(){
    int n, arr[100], choices;
    do {
        menu();
        cin >> choices;
        switch (choices)
        {
        case 1:
            hamRandom(arr, n);
            break;
        case 2:
            MaxNum(arr, n); 
            break;
        case 3:
            viTriMax(arr, n);
            break;
        case 4:
            allMaxPos(arr, n);
            break;
        case 5:
            timKiemTuyenTinh(arr, n);
            break;
        case 6:
            cout << "Thoat khoi menu!" << endl;
            break;
        default:
            cout << "Ban nhap sai roi xin nhap lai!" << endl;
            break;
        }
    } while (choices != 6);
    return 0;
}