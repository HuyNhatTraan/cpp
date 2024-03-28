#include <iostream>
#include <algorithm>
#include <ctime>
#include <stdlib.h>
using namespace std;

const int MAX = 1000;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void random(int arr[], int &n){ // Hàm random mảng 
    cout << "Hay nhap so phan tu ban muon random: "; cin >> n;
    srand((int)time(0)); // stdlib.h và ctime
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 5 + 1; // 100 + 1 = random từ 1 -> 100
    }
    cout << "Mang da random: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void LinearSearch(int arr[MAX], int n) {
    int key;
    bool daTimThay = false;
    cout << "Hay nhap so ban muon tim kiem: "; cin >> key;
    cout << "Vi tri xuat hien cua so nay la: ";
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << i << " ";
        }
    }
    cout << endl;
}

void SelectionSort(int arr[], int n){ 
    int min_idx;
    for (int i = 0; i < n - 1; i++) 
    {
        min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        swap(arr[i], arr[min_idx]);
    }
    cout << "Mang sau khi da sort la (Chon truc tiep)-> ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl; 
}  

void Menu() {
    cout << "================= Menu =====================" << endl;
    cout << "1. Nhap & xuat danh sach." << endl;
    cout << "2. Tim kiem so & so day da xuat hien bao lan." << endl;
    cout << "3. Selection sort." << endl;
    cout << "4. Thoát khỏi menu!" << endl;
    cout << "============================================" << endl;
}

int main(){
    int n, arr[MAX], choices;
    do {
        Menu();
        cout << "Hay nhap lua chon cua ban: "; cin >> choices;
        switch (choices) {
            case 1:
                random(arr, n);
                break;
            case 2:
                LinearSearch(arr, n);
                break;
            case 3:
                SelectionSort(arr, n);
                break;
            case 4:
                cout << "Thoat khoi menu!" << endl;
                break;
            default:
                cout << "Nhap sai roi vui long nhap lai!" << endl;
                break;
        }
    } while (choices != 4);
    
    return 0;
}