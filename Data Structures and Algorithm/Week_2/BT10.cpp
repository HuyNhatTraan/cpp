// Ho va Ten: Tran Nhat Huy
// MSSV: 221A010568
#include <bits/stdc++.h>
using namespace std;

class SanPham{
private:
    vector<string> MaSP;
    vector<string> TenSP;
    vector<long> GiaSP;
public:
    void nhapThongTin(){
        string id, name;
        long price;
        cout << "Hay nhap ma san pham: "; cin >> id;
        cin.ignore();
        MaSP.push_back(id);
        cout << "Hay nhap ten san pham: ";
        getline(cin, name);
        TenSP.push_back(name);
        cout << "Hay nhap gia cho san pham: "; 
        cin >> price;
        GiaSP.push_back(price);
    }
    void xuatThongTin(){
        for (int i = 0; i < GiaSP.size(); i++)
        {
            cout << "========================= \n";
            cout << "Ma san pham: " << MaSP[i] << endl;
            cout << "Ten san pham: " << TenSP[i] << endl;
            cout << "Gia: " << GiaSP[i] << " VND" << endl;
            cout << "========================= \n";
        }
    }
    void timKiemThongTin(){
        string x;
        cout << "Hay nhap ma san pha ban can tim: " ; cin >> x;
        bool timThay = false;
        for (int i = 0; i < GiaSP.size(); i++)
        {
            if ( x == MaSP[i])
            {
                timThay = true;
                cout << "Da tim thay san pham: \n";
                cout << "========================= \n";
                cout << "Ma san pham: " << MaSP[i] << endl;
                cout << "Ten san pham: " << TenSP[i] << endl;
                cout << "Gia: " << GiaSP[i] << " VND" << endl;
                cout << "========================= \n";
            }
            
        }
        if (!timThay){
            cout << "Khong tim thay san pham nay! \n";
        }
    }
};

void menu(){
    cout << "=========================== Menu =========================== \n";
    cout << "1. Nhap thong tin cho san pham." << endl;
    cout << "2. Hien thi thong tin san pham." << endl;
    cout << "3. Tim thong tin san pham." << endl;
    cout << "4. Thoat khoi menu!" << endl;
    cout << "=========================== [01] ============================ \n";
    cout << "Hãy nhập lựa chọn của bạn: ";
}

int main(){
    SanPham SP;
    int choices;
    do
    {
        menu();
        cin >> choices;
        switch (choices)
        {
        case 1:
            SP.nhapThongTin();
            break;
        case 2:
            SP.xuatThongTin();
            break;
        case 3:
            SP.timKiemThongTin();
            break;
        case 4:
            cout << "Thoat khoi menu thanh cong!. \n";
            break;
        default:
            cout << "Ban nhap sai roi lol. Vui long nhap lai! \n";
            break;
        }
    } while (choices != 4);
    return 0;
}
