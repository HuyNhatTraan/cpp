#include <iostream>
#include <vector>
#include <string>
using namespace std;

class ThuVien {
private:
    vector <string> MaSach;
    vector <string> TenSach;
    vector <float> DonGia;
    vector <int> SL;
    vector <string> NXB;
    vector <string> TenTG;
public:
    template<typename T> // Đặt template để swap nhanh
    void swapNe(T& a, T& b) {
        T temp = a;
        a = b;
        b = temp;
    }

    void nhapDanhSach() {
        int n, sl;
        string ma, ten, nxb, tacgia;
        float gia;
        cout << "Hãy nhập số lượng đầu sách bạn muốn thêm vào (x < 30): "; cin >> n;
        while (n <= 0) {
            cout << "Bạn nhập không đúng rồi, vui lòng nhập lại." << endl;
            cout << "Hãy nhập số lượng đầu sách bạn muốn thêm vào (x < 30): "; cin >> n;
        }
        if (MaSach.size() + n > 30) {
            cout << "Không đủ bộ nhớ để lưu các đầu sách. Tối đa 30, vui lòng xoá bớt nếu bạn muốn thêm vào." << endl;
        }
        else {
            for (int i = 0; i < n; i++) {
                cout << "Hãy nhập đầu sách thứ " << i + 1 << ": " << endl;
                cout << "Hãy nhập mã sách (Tối đa 10 ký tự): ";
                cin.ignore();
                getline(cin, ma);
                MaSach.push_back(ma);
                if (ma.length() > 10) {
                    cout << "Vượt quá số ký tự quy định cho mã sách. Vui lòng nhập lại!" << endl;
                    cout << "Hãy nhập mã sách (Tối đa 10 ký tự): ";
                    cin.ignore();
                    getline(cin, ma);
                    MaSach.push_back(ma);
                }
                cout << "Hãy nhập tên sách (Tối đa 50 ký tự): ";
                getline(cin, ten);
                TenSach.push_back(ten);
                if (ten.length() > 50) {
                    cout << "Vượt quá số ký tự quy định cho tên sách. Vui lòng nhập lại!" << endl;
                    getline(cin, ten);
                    TenSach.push_back(ten);
                }
                cout << "Hãy nhập đơn giá cho mã sách này: "; cin >> gia;
                DonGia.push_back(gia);
                cout << "Hãy nhập số lượng cho mã sách này: "; cin >> sl;
                SL.push_back(sl);
                cout << "Hãy nhập tên tác giả (Tối đa 50 ký tự): ";
                cin.ignore();
                getline(cin, tacgia);
                TenTG.push_back(tacgia);
                if (tacgia.length() > 50) {
                    cout << "Vượt quá số ký tự quy định cho tên tác giả. Vui lòng nhập lại!" << endl;
                    cin.ignore();
                    getline(cin, tacgia);
                    TenTG.push_back(tacgia);
                }
                cout << "Hãy nhập tên nhà xuất bản (Tối đa 50 ký tự): ";
                getline(cin, nxb);
                NXB.push_back(nxb);
                if (nxb.length() > 50) {
                    cout << "Vượt quá số ký tự quy định cho tên nxb. Vui lòng nhập lại!" << endl;
                    getline(cin, nxb);
                    NXB.push_back(nxb);
                }
            }
        }
    }

    void xuatDanhSach() {
        cout << "Danh sách các đầu sách đang có: " << endl;
        for (int i = 0; i < MaSach.size(); i++) {
            cout << i + 1 << ". Mã sách: " << MaSach[i] << " | Tên sách: " << TenSach[i]
                << " | Giá: " << DonGia[i] << " | Số lượng: " << SL[i] << " | Tác giả: " << TenTG[i] << " | NXB: " << NXB[i] << endl;
        }
    }

    void xuatDanhSachCuaTacGia() {
        string key;
        bool daTimThay = false;
        cout << "Hãy nhập tên tác giả bạn muốn xem: ";
        getline(cin, key);
        for (int i = 0; i < MaSach.size(); i++) {
            if (TenTG[i] == key) {
                daTimThay = true;
                cout << "Đã tìm thấy thông tin các đầu sách của tác giả: " << endl;
                cout << i + 1 << ". Mã sách: " << MaSach[i] << " | Tên sách: " << TenSach[i]
                    << " | Giá: " << DonGia[i] << " | Số lượng: " << SL[i] << " | Tác giả: " << TenTG[i] << " | NXB: " << NXB[i] << endl;
            }
        }
        if (!daTimThay) {
            cout << "Không tìm thấy tác giả này!" << endl;
        }

    }

    void sapXepDauSachTheoSoLuong() {
        bool daThayDoi = false;
        for (int i = 0; i < MaSach.size() - 1; i++) {
            for (int j = 0; j < MaSach.size() - i - 1; j++) {
                if (SL[j] > SL[j + 1]) {
                    swapNe(MaSach[j], MaSach[j + 1]);
                    swapNe(TenSach[j], TenSach[j + 1]);
                    swapNe(NXB[j], NXB[j + 1]);
                    swapNe(TenTG[j], TenTG[j + 1]);
                    swapNe(SL[j], SL[j + 1]);
                    swapNe(DonGia[j], DonGia[j + 1]);
                    daThayDoi = true;
                }
            }
            if (!daThayDoi) {
                break;
            }
        }
    }

    void sapXepDauSachGiamDanTheoGia() {
        bool daThayDoi = false;
        for (int i = 0; i < MaSach.size() - 1; i++) {
            for (int j = 0; j < MaSach.size() - i - 1; j++) {
                if (DonGia[j] < DonGia[j + 1]) {
                    swapNe(MaSach[j], MaSach[j + 1]);
                    swapNe(TenSach[j], TenSach[j + 1]);
                    swapNe(NXB[j], NXB[j + 1]);
                    swapNe(TenTG[j], TenTG[j + 1]);
                    swapNe(SL[j], SL[j + 1]);
                    swapNe(DonGia[j], DonGia[j + 1]);
                    daThayDoi = true;
                }
            }
            if (!daThayDoi) {
                break;
            }
        }
    }

    void sumNXB() {
        int sum = 0;
        string key;
        cout << "Hãy nhập tên nhà xuất bản bạn muốn tính: ";
        cin.ignore();
        getline(cin, key);
        for (int i = 0; i < MaSach.size(); i++) {
            if (NXB[i] == key) {
                sum += DonGia[i];
            }
        }
        cout << "Tổng số tiền nhà xuất bản này xuất bản là: " << sum << endl;
    }

    void sapXepDauSachTheoTenTG() {
        bool daThayDoi = false;
        for (int i = 0; i < MaSach.size() - 1; i++) {
            for (int j = 0; j < MaSach.size() - i - 1; j++) {
                if (TenTG[j] > TenTG[j + 1]) {
                    swapNe(MaSach[j], MaSach[j + 1]);
                    swapNe(TenSach[j], TenSach[j + 1]);
                    swapNe(NXB[j], NXB[j + 1]);
                    swapNe(TenTG[j], TenTG[j + 1]);
                    swapNe(SL[j], SL[j + 1]);
                    swapNe(DonGia[j], DonGia[j + 1]);
                    daThayDoi = true;
                }
            }
            if (!daThayDoi) {
                break;
            }
        }
    }
};



void Menu() {
    cout << "================= Menu =====================" << endl;
    cout << "1. Nhập danh sách các đầu sách (Tối đa 30)." << endl;
    cout << "2. Xuất danh sách các đầu sách." << endl;
    cout << "3. Xuất danh sách các đầu sách khi biết tên tác giả." << endl;
    cout << "4. Sắp xếp các đầu sách tăng dần theo số lượng." << endl;
    cout << "5. Sắp xếp danh sách đầu sách giảm dần theo đơn giá." << endl;
    cout << "6. Sắp xếp danh sách đầu sách tăng dần theo tên tác giả." << endl;
    cout << "7. Tính tổng giá trị của các đầu sách khi biết tên nhà xuất bản." << endl;
    cout << "8. Thoát khỏi menu!" << endl;
    cout << "============================================" << endl;
}

int main() {
    ThuVien TV;
    int choices;
    do {
        Menu();
        cout << "Hãy nhập lựa chọn của bạn: "; cin >> choices;
        switch (choices) {
        case 1:
            TV.nhapDanhSach();
            break;
        case 2:
            TV.xuatDanhSach();
            break;
        case 3:
            TV.xuatDanhSachCuaTacGia();
            break;
        case 4:
            TV.sapXepDauSachTheoSoLuong();
            break;
        case 5:
            TV.sapXepDauSachGiamDanTheoGia();
            break;
        case 6:
            TV.sapXepDauSachTheoTenTG();
            break;
        case 7:
            TV.sumNXB();
            break;
        case 8:
            cout << "Thoát khỏi Menu thành công!." << endl;
            break;
        default:
            cout << "Nhập sai rồi, vui lòng nhập lại!." << endl;
            break;
        }
    } while (choices != 8);
    return 0;
}