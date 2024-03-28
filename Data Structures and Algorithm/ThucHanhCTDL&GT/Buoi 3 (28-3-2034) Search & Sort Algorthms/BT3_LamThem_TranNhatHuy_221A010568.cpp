#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class SanPham{
private:
    vector<string> MaSP;
    vector<string> TenSP;
    vector<float> Gia;
    vector<int> Ngay;
    vector<int> Thang;
    vector<int> Nam;
    vector<int> DayUse;
    vector<string> NoiSX;
public:
    template<typename T> // Đặt template để swap nhanh
    void swapNe(T& a, T& b) {
        T temp = a;
        a = b;
        b = temp;
    }

    void nhapThongTin() {
        int n, ngay, thang, nam, ngaysudung;
        string ten, ma, noisx;
        float price;
        cout << "Hay nhap so luong san pham ban muon them vao: "; cin >> n;
        for (int i = 0; i < n; i++) {
            cout << "Nhap thong tin san pham thu " << i + 1 << ": " << endl;
            cout << "Hay nhap MaSP: ";
            cin.ignore();
            getline(cin, ma);
            MaSP.push_back(ma);
            cout << "Hay nhap TenSP: ";
            getline(cin, ten);
            TenSP.push_back(ten);
            cout << "Hay nhap gia tien SP: "; cin >> price;
            Gia.push_back(price);
            cout << "Hay nhap ngay sx: "; cin >> ngay;
            Ngay.push_back(ngay);
            cout << "Hay nhap thang sx: "; cin >> thang;
            Thang.push_back(thang);
            cout << "Hay nhap nam sx: "; cin >> nam;
            Nam.push_back(nam);
            cout << "Hay nhap so ngay su dung: "; cin >> ngaysudung;
            DayUse.push_back(ngaysudung);
            cout << "Hay nhap noi sx: "; 
            cin.ignore();
            getline(cin, noisx);
            NoiSX.push_back(noisx);
        }
    }

    void xuatThongTin() {
        cout << "Thong tin cac ca hoc: " << endl;
        for (int i = 0; i < MaSP.size(); i++) {
            cout << i + 1 << ". MaSP: " << MaSP[i] << " | TenSP: " << TenSP[i] << " | Gia: " << Gia[i]
            << " | Ngay/Thang/Nam: " << Ngay[i] << "/" << Thang[i] << "/" << Nam[i] << 
            " | So Ngay Su Dung: " << DayUse[i] << " | NoiSX: " << NoiSX[i] << endl;
        }
    }

    void timKiemMaSP() {
        string key;
        bool daTimThay = false;
        cout << "Hay nhap MaHP ma ban muon tim kiem: ";
        cin.ignore();
        getline(cin, key);
        for (int i = 0; i < MaSP.size(); i++) {
            if (MaSP[i] == key) {
                daTimThay = true;
                cout << "Da tim thay thong tin hoc phan nay: " << endl;
                cout << i + 1 << ". MaSP: " << MaSP[i] << " | TenSP: " << TenSP[i] << " | Gia: " << Gia[i]
            << " | Ngay/Thang/Nam: " << Ngay[i] << "/" << Thang[i] << "/" << Nam[i] << 
            " | So Ngay Su Dung: " << DayUse[i] << " | NoiSX: " << NoiSX[i] << endl;
            }
            if (!daTimThay) {
                cout << "Khong tim thay hoc phan nay! Vui long thu lai." << endl;
            }
        }
    }

    void timKiemTenSP() {
        string key;
        bool daTimThay = false;
        cout << "Hay nhap TenHP ma ban muon tim kiem: ";
        cin.ignore();
        getline(cin, key);
        for (int i = 0; i < MaSP.size(); i++) {
            if (TenSP[i] == key) {
                daTimThay = true;
                cout << "Da tim thay thong tin hoc phan nay: " << endl;
                cout << i + 1 << ". MaSP: " << MaSP[i] << " | TenSP: " << TenSP[i] << " | Gia: " << Gia[i]
            << " | Ngay/Thang/Nam: " << Ngay[i] << "/" << Thang[i] << "/" << Nam[i] << 
            " | So Ngay Su Dung: " << DayUse[i] << " | NoiSX: " << NoiSX[i] << endl;
            }
            if (!daTimThay) {
                cout << "Khong tim thay hoc phan nay! Vui long thu lai." << endl;
            }
        }
    }

    void inRaKhiBietNoiSX() {
        string key;
        bool daTimThay = false;
        cout << "Hay nhap phong hoc ma ban muon tim kiem: ";
        cin.ignore();
        getline(cin, key);
        for (int i = 0; i < MaSP.size(); i++) {
            if (NoiSX[i] == key) {
                daTimThay = true;
                cout << "Da tim thay thong tin hoc phan nay: " << endl;
                cout << i + 1 << ". MaSP: " << MaSP[i] << " | TenSP: " << TenSP[i] << " | Gia: " << Gia[i]
            << " | Ngay/Thang/Nam: " << Ngay[i] << "/" << Thang[i] << "/" << Nam[i] << 
            " | So Ngay Su Dung: " << DayUse[i] << " | NoiSX: " << NoiSX[i] << endl;
            }
            if (!daTimThay) {
                cout << "Khong tim thay hoc phan nay! Vui long thu lai." << endl;
            }
        }
    }

    void sapXepTenSPTangDan(){
        int min_idx;
        for (int i = 0; i < MaSP.size() - 1; i++) { 
            min_idx = i; 
            for (int j = i + 1; j < MaSP.size(); j++) { 
                if (TenSP[j] < TenSP[min_idx]) 
                    min_idx = j; 
            } 
            if (min_idx != i) 
                swapNe(MaSP[min_idx], MaSP[i]);
                swapNe(TenSP[min_idx], TenSP[i]);
                swapNe(Gia[min_idx], Gia[i]);
                swapNe(Ngay[min_idx], Ngay[i]);
                swapNe(Thang[min_idx], Thang[i]);
                swapNe(Nam[min_idx], Nam[i]);
                swapNe(DayUse[min_idx], DayUse[i]);
                swapNe(NoiSX[min_idx], NoiSX[i]);
        } 
        cout << "Sau khi sort: " << endl;
        xuatThongTin();
    }

};

void Menu() {
    cout << "================= Menu =====================" << endl;
    cout << "1. Nhap danh sach san pham." << endl;
    cout << "2. Xuat danh sach san pham." << endl;
    cout << "3. Tim kiem khi biet MaSP." << endl;
    cout << "4. Tim kiem khi biet TenSP." << endl;
    cout << "5. In ra cac ca hoc khi biet NoiSX." << endl;
    cout << "6. Sap xep TenSP theo thu tu tang dan." << endl;
    cout << "7. Thoát khỏi menu!" << endl;
    cout << "============================================" << endl;
}

int main() {
    SanPham SP;
    int choices;
    do {
        Menu();
        cout << "Hay nhap lua chon cua ban: "; cin >> choices;
        switch (choices)
        {
        case 1:
            SP.nhapThongTin();
            break;
        case 2:
            SP.xuatThongTin();
            break;
        case 3:
            SP.timKiemMaSP();
            break;
        case 4:
            SP.timKiemTenSP();
            break;
        case 5:
            SP.inRaKhiBietNoiSX();
            break;
        case 6:
            SP.sapXepTenSPTangDan();
            break;
        case 7:
            cout << "Thoat khoi menu!." << endl;
            break;
        default:
            cout << "Nhap sai roi! Ban vui long nhap lai." << endl;
            break;
        }
    } while (choices != 7);
    return 0;
}