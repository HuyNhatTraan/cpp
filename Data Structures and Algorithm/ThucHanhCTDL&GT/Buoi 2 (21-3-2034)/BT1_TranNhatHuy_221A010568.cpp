#include <bits/stdc++.h> // #include <stdlib>, #include <iostream>, #include <ctime>
using namespace std;
const int MAX = 100;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void random(int &n, int arr[MAX]){
    cout << "Hay nhap so phan tu muon random: "; cin >> n;
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1;
    }
    cout << "Cac phan tu da duoc random la: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void XuatArr(int n, int arr[MAX]) {
    cout << "Cac phan tu trong mang la: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

}

void thuatToanTimKiemNeHiHi(){
    int key, n, arr[MAX];
    bool daTimThay = false;
    cout << "Hay nhap so can tim kiem: "; cin >> key;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Da tim thay du lieu."  << endl;
            daTimThay = true;
            break;
        }
    }
    if (!daTimThay) {
        cout << "Khong tim thay du lieu can tim." << endl;
    }
}

void InsertionSort(int n, int arr[MAX]) {
    int temp, x;
    for (int i = 1; i < n; i++) {
        x = arr[i];
        temp = i - 1;
        while ((temp >= 0) && (arr[temp] > x) ){
            arr[temp + 1] = arr[temp];
            temp--;
        }
        arr[temp] = x;
    }
    cout << "Insertion Sort -> ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void InterchangeSort(int n, int arr[MAX]){
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i],arr[j]);
            }
        }
    }
    cout << "Interchange Sort -> ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void BubbleSort(int n, int arr[MAX]){
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--) {
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
            }
        }
    }
    cout << "Bubble Sort -> ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void QuickSort(int arr[MAX], int left, int right){
    int i, j, x, tam, n;
    x = arr[(left + right) / 2];
    i = left, j = right;
    do {
        while (arr[i] < x) i++;
        while (arr[j] > x) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
        
    } while (i < j);
    if (left < j)
        QuickSort(arr, left, j);
    if (i < right)
        QuickSort(arr, i, right);
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
        arr[k] = R[j];
        j++;
    }
    k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void MenuNeHihihi(){
    cout << "============= Menu =============" << endl;
    cout << "1. Random cac phan tu co trong mang. " << endl;
    cout << "2. Xuat danh sach Array. " << endl;
    cout << "3. Linear Search." << endl;
    cout << "4. Insertion sort." << endl;
    cout << "5. Interchange sort." << endl;
    cout << "6. Bubble sort." << endl;
    cout << "7. Quick Sort. " << endl;
    cout << "8. Merge Sort" << endl;
    cout << "9. Thoat khoi menu." << endl;
    cout << "================================" << endl;
}

int main(){
    int choices, n, m, arr[MAX], arr2[MAX], left, right;
    do {
        MenuNeHihihi();
        cout << "Hay nhap lua chon cua ban: "; cin >> choices;
        switch (choices) {
        case 1:
            random(n , arr);
            break;
        case 2:
            XuatArr(n, arr);
            break;
        case 3:
            thuatToanTimKiemNeHiHi();
            break;
        case 4:
            InsertionSort(n, arr);
            break;
        case 5:
            InterchangeSort(n, arr);
            break;
        case 6:
            BubbleSort(n, arr);
            break;
        case 7:
            QuickSort(arr, left, right);
            XuatArr(n, arr);
            break;
        case 8:
            mergeSort(arr, 0, n - 1);
            XuatArr(n, arr);
            break;
        case 9:
            cout << "Thoat khoi menu!" << endl;
            break;
        default:
             cout << "Be oi tu tu! Nhap sai roi ne." << endl;
            break;
        }
    } while (choices != 9);
    return 0;
}