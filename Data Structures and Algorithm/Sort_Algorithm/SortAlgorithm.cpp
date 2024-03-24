#include <bits/stdc++.h> // include <iostream>
using namespace std;

void random(int arr[], int &n){ // Hàm random mảng 
    cout << "Hay nhap so phan tu ban muon random: "; cin >> n;
    srand((int)time(0)); // stdlib.h và ctime
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1; // 100 + 1 = random từ 1 -> 100
    }
    cout << "Mang da random -> ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void maxMang(int arr[], int n){ // Hàm tìm số lớn nhất trong mảng
    int maxIndex = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > maxIndex) {
            maxIndex = arr[i];
        }
    }
    cout << "So lon nhat trong mang la: " << maxIndex << endl;
} 

void swap(int &a, int &b){ // Hàm đổi chỗ mảng
    int temp = a;
    a = b;
    b = temp;
} 

void InterchangeSort(int arr[], int n) { // Thuật toán sắp xếp trực tiếp 
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                // Swap arr[i] and arr[j]
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    cout << "Mang sau khi da sort la (Sap xep truc tiep) -> ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl; 
}

void SelectionSort(int arr[], int n){ // Thuật toán sắp xếp chọn trực tiếp
    int min_idx; // Tạo min_idx nhằm chọn ra phần tử ban đầu để swap
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

void BubbleSort(int arr[], int n){
    bool daThayDoi = false; // Đặt biến daThayDoi để check xem có hoán đổi vị trí hay chưa
    for (int i = 0; i < n - 1; i++){ // Đặc biến đếm chạy đến cuối dãy (n-1)
        for (int j = 0; j < n - i - 1; j++) // Duyệt từ j = 0 và cho chạy đến giới hạn là n - i - 1 Ví dụ Max n = 5
        {                                   // thì 5-0-1 = 4 => chỉ chạy đến tối đa là arr[4] vì arr[5] đã là số lớn nhất và không cần check 
            if (arr[j] > arr[j + 1]){       // nếu j lớn hơn j + 1 thì swap lại với nhau
                swap(arr[j], arr[j + 1]);
                daThayDoi = true; // Cho daThayDoi thành true để tránh việc lặp lại
            }
        }
        if (!daThayDoi){
            break;
        }
    }
    cout << "Mang sau khi da sort la (Thuat toan noi bot)-> ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl; 
}

void InsertionSort(int arr[], int n) { // Thuật toán sắp xếp chèn Insertion Sort
    int key;    // Tạo 1 key để xác định array                      
    for (int i = 1; i < n - 1; i++) {   // Tạo vòng lặp chạy từ đầu đến cuối mảng
        key = arr[i];   // Cho key = arr[thứ i]
        int j = i - 1;
        while (j > 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    cout << "Mang sau khi da sort la (Sap xep chen) -> ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl; 
}

int partition(int arr[],int low,int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for(int j = low; j <= high; j++) {
        //  If current element is smaller than the pivot
        if(arr[j] < pivot) {
        //  Increment index of smaller element
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return (i+1);
}
 
// Cách Quicksort hoạt động
            
void quickSort(int arr[],int low,int high) {
    //  Nếu low thấp hơn high
    if (low < high) {
    //  pi is the partition return index of pivot
        int pi = partition(arr,low,high);
        //  Đệ quy
        //  smaller element than pivot goes left and
        //  higher element goes right
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
  }
}

int main(){
    int arr[100], n;
    random(arr, n);
    maxMang(arr, n);
    InterchangeSort(arr, n);
    SelectionSort(arr, n);
    BubbleSort(arr, n);
    InsertionSort(arr, n);
    quickSort(arr, 0, n - 1);
    cout << "Mang sau khi da sort la (Quick Sort) -> ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl; 
    return 0;
}