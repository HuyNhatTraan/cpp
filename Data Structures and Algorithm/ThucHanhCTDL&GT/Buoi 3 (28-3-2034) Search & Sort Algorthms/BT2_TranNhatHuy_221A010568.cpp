#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class CATHUCHANH{
private:
    vector<string> MaHP;
    vector<string> TenHP;
    vector<int> SL;
    vector<string> PhongHoc;
public:
    void nhapThongTin(){
        string ma, ten, phong;
        int n, sl;
        cout << "Hay nhap so lop thuc hanh ban muon them vao: "; cin >> n;
        cin.ignore();
        cout << "Nhap thong tin lop hoc phan: " << endl;
        cout << "Hay nhap ma lop hoc phan: "; 
        getline(cin, ma);
        MaHP.push_back(ma);
        cout << "Hay nhap ten lop hoc phan: ";
        getline(cin, ten);
        TenHP.push_back(ten);
        cout << "Hay nhap so sinh vien: "; cin >> sl;
        SL.push_back(sl);
        cin.ignore();
        cout << "Hay nhap phong hoc: ";
        getline(cin, phong);
        PhongHoc.push_back(phong);
    }

    void xuatThongTin() {
        cout << "Thong tin cac ca hoc: " << endl;
        for (int i = 0; i < MaHP.size(); i++) {
            cout << i + 1 << "MaHP: " << MaHP[i] << " | TenHP: " << TenHP[i] << " | Sinh vien: " << SL[i]
            << " | Phong: " << PhongHoc[i] << endl;
        }
    }

    void timKiemMaHP() {
        string key;
        bool daTimThay = false;
        cout << "Hay nhap MaHP ma ban muon tim kiem: ";
        getline(cin, key);
        for (int i = 0; i < MaHP.size(); i++) {
            if (MaHP[i] == key) {
                daTimThay = true;
                cout << "Da tim thay thong tin hoc phan nay: " << endl;
                cout << i + 1 << "MaHP: " << MaHP[i] << " | TenHP: " << TenHP[i] << " | Sinh vien: " << SL[i]
            << " | Phong: " << PhongHoc[i] << endl;
            }
            if (!daTimThay) {
                cout << "Khong tim thay hoc phan nay! Vui long thu lai." << endl;
            }
        }
    }

    void timKiemTenHP() {
        string key;
        bool daTimThay = false;
        cout << "Hay nhap TenHP ma ban muon tim kiem: ";
        getline(cin, key);
        for (int i = 0; i < MaHP.size(); i++) {
            if (TenHP[i] == key) {
                daTimThay = true;
                cout << "Da tim thay thong tin hoc phan nay: " << endl;
                cout << i + 1 << "MaHP: " << MaHP[i] << " | TenHP: " << TenHP[i] << " | Sinh vien: " << SL[i]
            << " | Phong: " << PhongHoc[i] << endl;
            }
            if (!daTimThay) {
                cout << "Khong tim thay hoc phan nay! Vui long thu lai." << endl;
            }
        }
    }

    void inRaKhiBietPH() {
        string key;
        bool daTimThay = false;
        cout << "Hay nhap phong hoc ma ban muon tim kiem: ";
        getline(cin, key);
        for (int i = 0; i < MaHP.size(); i++) {
            if (PhongHoc[i] == key) {
                daTimThay = true;
                cout << "Da tim thay thong tin hoc phan nay: " << endl;
                cout << i + 1 << "MaHP: " << MaHP[i] << " | TenHP: " << TenHP[i] << " | Sinh vien: " << SL[i]
            << " | Phong: " << PhongHoc[i] << endl;
            }
            if (!daTimThay) {
                cout << "Khong tim thay hoc phan nay! Vui long thu lai." << endl;
            }
        }
    }

};

void Menu() {
    cout << "================= Menu =====================" << endl;
    cout << "1. Nhap danh sach ca thuc hanh." << endl;
    cout << "2. Xuat danh sach ca thuc hanh." << endl;
    cout << "3. Tim kiem khi biet ma hoc phan." << endl;
    cout << "4. Tim kiem khi biet ten hoc phan." << endl;
    cout << "5. In ra cac ca hoc khi biet phog hoc." << endl;
    cout << "6. Thoát khỏi menu!" << endl;
    cout << "============================================" << endl;
}

int main() {
    CATHUCHANH CTH;
    int choices;
    do {
        Menu();
        cout << "Hay nhap lua chon cua ban: "; cin >> choices;
        switch (choices)
        {
        case 1:
            CTH.nhapThongTin();
            break;
        case 2:
            CTH.xuatThongTin();
            break;
        case 3:
            CTH.timKiemMaHP();
            break;
        case 4:
            CTH.timKiemTenHP();
            break;
        case 5:
            CTH.inRaKhiBietPH();
            break;
        case 6:
            cout << "Thoat khoi menu!." << endl;
            break;
        default:
            cout << "Nhap sai roi! Ban vui long nhap lai." << endl;
            break;
        }
    } while (choices != 8);
    
    return 0;
}