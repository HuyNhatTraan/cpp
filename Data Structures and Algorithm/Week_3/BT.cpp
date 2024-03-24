#include <bits/stdc++.h>
using namespace std;

void nhapMang(int arr[], int &n){
    cout << "Hay nhap so phan tu ban muon: "; cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Hay nhap [" << i << "]: ";
        cin >> arr[i];
    }
    cout << endl;
}
void xuatMang(int arr[], int n){
    cout << "Mang  da nhap la: \n"; 
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void InterchangeSort(int arr[], int n){
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    cout << "Mang 1 chieu da sort lai la: \n"; 
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void SelectionSort(int arr[], int n){
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min]){
                min = j;
            }
            swap(arr[j], arr[min]);
        }
    }
    cout << "Mang 1 chieu da sort lai la: \n"; 
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
} 

void BubbleSort(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (arr[j] < arr[j - 1]){
                swap(arr[j], arr[j-1]);
            }
        }
    }
    cout << "Mang 1 chieu da sort lai la: \n"; 
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
}

void menu(){
    cout << "===================================== \n";
    cout << "1. Nhap mang." << endl;
    cout << "2. Xuat mang." << endl;
    cout << "3. Sap xep mang tang dan theo phuong phap doi cho truc tiep." << endl;
    cout << "4. Sap xep mang tang dan theo phuong phap chen truc tiep." << endl;
    cout << "5. Sap xep mang tang dan theo phuong phap noi bot." << endl;
    cout << "6. Thoat khoi menu." << endl;
    cout << "===================================== \n";
    cout << "Hay nhap lua chon cua ban: ";
}

int main(){
    int choices, arr[100], n;
    do
    {
        menu();
        cin >> choices;
        switch (choices)
        {
        case 1:
            nhapMang(arr, n);
            break;
        case 2:
            xuatMang(arr, n);
            break;
        case 3:
            InterchangeSort(arr, n);
        case 4:
            SelectionSort(arr, n);
            break;
        case 5:
            BubbleSort(arr, n);
            break;
        case 6:
            cout << "Thoat khoi menu! \n";
            break;
        default:
            cout << "Nhap sai roi vui long nhap lai!" << endl;
            break;
        }
    } while (choices != 6);
    return 0;
}