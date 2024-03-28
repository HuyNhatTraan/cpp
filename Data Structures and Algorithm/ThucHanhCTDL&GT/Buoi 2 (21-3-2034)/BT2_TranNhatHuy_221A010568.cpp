#include <bits/stdc++.h> // #include <string>, #include <iostream>, #include <vector>, #include <cstring>
using namespace std;

class SanPham {
private:
    vector <string> MaSP;
    vector <string> TenSP;
    vector <float> DonGia;
    vector <int> SL;
public:
    void swapstring(string &a, string &b){
        string temp = a;
        a = b;
        b = temp;
    }
    void swapint(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }
    void swapfloat(float &a, float &b){
        float temp = a;
        a = b;
        b = temp;
    }

    void nhapSanPham(){
        string ten, ma;
        float gia;
        int n, sl;
        cout << "Hay nhap so san pham can nhap: "; cin >> n;
        while (n <= 0) {
            cout << "Ban nhap sai roi.Vui long nhap so luong san pham can nhap > 0." << endl;
            cout << "Hay nhap so san pham can nhap: "; cin >> n;
        }
        if (MaSP.size() > 40) {
            cout << "Danh sach cac san pham da day! Vui long xoa bot (MAX = 40).";
        } else {
            for (int i = 0; i < n; i++) {
                cout << "Nhap san pham thu " << i + 1 << ": " << endl;
                cout << "Hay nhap MaSP (toi da 5 ky tu): ";
                cin.ignore();
                getline(cin, ma);
                MaSP.push_back(ma);
                while (ma.length() > 5) { // Check ma san pham co vuot qua 5 ky tu khong
                    cout << "MaSP khong duoc qua 5 ky tu!" << endl;
                    cout << "Hay nhap MaSP (toi da 5 ky tu): ";
                    cin.ignore();
                    getline(cin, ma);
                    MaSP.push_back(ma);
                }
                cout << "Hay nhap TenSP (toi da 50 ky tu): ";
                getline(cin, ten);
                TenSP.push_back(ten);
                while (ten.length() > 50) { // Check ten san pham co vuot qua 50 ky tu khong
                    cout << "TenSP khong duoc qua 50 ky tu!" << endl;
                    cout << "Hay nhap TenSP (toi da 50 ky tu): ";
                    getline(cin, ten);
                    TenSP.push_back(ten);
                }
                cout << "Hay nhap DonGia cho SP: ";
                cin >> gia;
                DonGia.push_back(gia);
                cout << "Hay nhap So luong SP: ";
                cin >> sl;
                SL.push_back(sl);
            }
        }
    }

    void xuatDanhSach(){
        int n;
        cout << "Danh sach san pham: " << endl;
        for (int i = 0; i < MaSP.size(); i++) {
            cout << i + 1 << ". MaSP: " << MaSP[i] << " | TenSP:" << TenSP[i] << " | GiaSP: " << DonGia[i] 
            << " | SoLuongSp: " << SL[i] << endl;
            cout << "================================" << endl;
        }
        
    }

    void thuatToanTimKiemNeHiHi(){
    string key;
    bool daTimThay = false;
    cout << "Hay nhap so can tim kiem: "; cin >> key;
    for (int i = 0; i < MaSP.size(); i++) {
        if (MaSP[i] == key) {
            cout << "Da tim thay du lieu."  << endl;
            daTimThay = true;
            break;
        }
    }
    if (!daTimThay) {
        cout << "Khong tim thay du lieu can tim." << endl;
    }
}

    void selectionSort() { 
        int min_idx;
        for (int i = 0; i < MaSP.size() - 1; i++) { 
            min_idx = i; 
            for (int j = i + 1; j < MaSP.size(); j++) { 
                if (MaSP[j] < MaSP[min_idx]) 
                    min_idx = j; 
            } 
            if (min_idx != i) 
                swapstring(MaSP[min_idx], MaSP[i]);
                swapstring(TenSP[min_idx], TenSP[i]);
                swapfloat(DonGia[min_idx], DonGia[i]);
                swapint(SL[min_idx], SL[i]);
        } 
        cout << "Sau khi sort: " << endl;
        xuatDanhSach();
    }

    void insertionSort() {
    string key, ten;
    int i, j;
    float gia;
    int sl;
    for (i = 1; i < MaSP.size(); i++) {
        key = MaSP[i];
        ten = TenSP[i];
        gia = DonGia[i];
        sl = SL[i];
        j = i - 1;
        while (j >= 0 && MaSP[j] > key) {
            MaSP[j + 1] = MaSP[j];
            TenSP[j + 1] = TenSP[j];
            DonGia[j + 1] = DonGia[j];
            SL[j + 1] = SL[j];
            j = j - 1;
        }
        MaSP[j + 1] = key;
        TenSP[j + 1] = ten;
        DonGia[j + 1] = gia;
        SL[j + 1] = sl;
    }
    cout << "Sau khi sort: " << endl;
    xuatDanhSach();
    }
    void BubbleSort(){
        for (int i = 0; i < MaSP.size() - 1; i++) {
            for (int j = MaSP.size() - i - 1; j > i; j--) {
            if (MaSP[j] < MaSP[j - 1]) {
                swapstring(MaSP[j], MaSP[j - 1]);
                swapstring(TenSP[j], TenSP[j - 1]);
                swapfloat(DonGia[j], DonGia[j - 1]);
                swapint(SL[j], SL[j - 1]);
            }
            }
        }
        cout << "Sau khi sort: " << endl;
        xuatDanhSach();
    }
};

void MenuNeHihihi(){
    cout << "============= Menu =============" << endl;
    cout << "1. Nhap danh sach SP. " << endl;
    cout << "2. Xuat danh sach SP. " << endl;
    cout << "3. Tim kiem SP khi biet MaSP." << endl;
    cout << "4. Sap xep tang dan Selection Sort." << endl;
    cout << "5. Sap xep tang dan Insertion Sort." << endl;
    cout << "6. Sap xep tang dan Bubble Sort." << endl;
    cout << "7. Thoat khoi menu." << endl;
    cout << "================================" << endl;
}

int main(){
    SanPham SP;
    int choices;
    do {
        MenuNeHihihi();
        cout << "Hay nhap lua chon cua bn: "; cin >> choices;
        switch (choices)
        {
        case 1:
            SP.nhapSanPham();
            break;
        case 2:
            SP.xuatDanhSach();
            break;
        case 3:
            SP.thuatToanTimKiemNeHiHi();
            break;
        case 4:
            SP.selectionSort();
            break;
        case 5:
            SP.insertionSort();
            break;
        case 6:
            SP.BubbleSort();
            break;     
        case 7:
            cout << "Thoat khoi menu!. " << endl;
            break;
        default:
            cout << "Nhap sai roi vui long nhap lai. " << endl;
            break;
        }
    } while (choices != 7);
    return 0;
}