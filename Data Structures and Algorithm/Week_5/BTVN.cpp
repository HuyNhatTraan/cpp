/*
Giả sử cho danh sách liên kết đơn có khai báo cấu trúc như sau 
typedef struct tagSinhVien
{
    int MSSV;
    char TenSV[100];
    float DTB;
} SINHVIEN;
typedef struct tagNODE 
{
    SINHVIEN SV;
    struct tagNODE* pNext;
}NODE, *PNODE;

    Câu hỏi
        1.  Dùng C/C++ viết hàm nhập từ bàn phím thông tin của 10 sinh viên 
            thông tin này đc đưa vào danh sách liên kết đơn theo pp thêm vào cuối
    2. Viết hàm in ra danh sách in ra danh sách những sinh viên có ĐTB >= 5
    3. Viết hàm giải phóng liên kết đơn
    4. Viết hàm main để thực thi các hàm ở trên
*/

#include <bits/stdc++.h>
using namespace std;

typedef struct tagSinhVien {
    int MSSV;
    char TenSV[100];
    float DTB;
} SINHVIEN;

typedef struct tagNODE {
    SINHVIEN SV;
    struct tagNODE* pNext;
} NODE, *PNODE;

void nhapThongTinSinhVien(SINHVIEN& SinhVien) {
    cout << "Hay nhap thong tin sinh vien: " << endl; 
    cout << "Hay nhap ten sinh vien: ";
    cin.ignore();
    cin.getline(SinhVien.TenSV, 100);
    cout << "Hay nhap MSSV: ";
    cin >> SinhVien.MSSV;
    cout << "Hay nhap diem trung binh cua sinh vien: ";
    cin >> SinhVien.DTB;
}

void ThemSinhVienCuoiDanhSach(PNODE& pHead, SINHVIEN sv) {
    PNODE pNewNode = new NODE; // Tạo một nút mới
    pNewNode -> SV = sv; // Gán thông tin sinh viên vào nút mới
    pNewNode -> pNext = NULL; // Đặt con trỏ pNext của nút mới là NULL
    if (pHead == NULL) {
        pHead = pNewNode; // Nếu danh sách rỗng, nút mới trở thành nút đầu tiên
    }
    else {
        PNODE pTemp = pHead;
        while (pTemp->pNext != NULL) {
            pTemp = pTemp->pNext; // Tìm nút cuối cùng của danh sách
        }
        pTemp->pNext = pNewNode; // Gắn nút mới vào cuối danh sách
    }
}

void InDanhSachSinhVien(PNODE pHead) {
    PNODE pTemp = pHead;
    while (pTemp != NULL) {
        if (pTemp -> SV.DTB >= 5) {
            cout << "MSSV: " << pTemp -> SV.MSSV << endl;
            cout << "TenSV: " << pTemp -> SV.TenSV << endl;
            cout << "DTB: " << pTemp -> SV.DTB << endl;
            cout << endl;
        }
        pTemp = pTemp->pNext;
    }
}

void GiaiPhongDanhSach(PNODE& pHead) {
    while (pHead != NULL) {
        PNODE pTemp = pHead;
        pHead = pHead->pNext;
        delete pTemp;
    }
}

int main() {
    PNODE pHead = NULL; // Khởi tạo danh sách liên kết đơn rỗng
    // Nhập thông tin của 10 sinh viên và thêm vào danh sách
    for (int i = 0; i < 10; i++) {
        SINHVIEN sv;
        cout << "Nhap thong tin sinh vien thu " << i + 1 << ":" << endl;
        nhapThongTinSinhVien(sv);
        ThemSinhVienCuoiDanhSach(pHead, sv);
        cout << endl;
    }
    // In ra danh sách sinh viên có DTB >= 5
    cout << "Danh sach sinh vien co DTB >= 5:" << endl;
    InDanhSachSinhVien(pHead);
    // Giải phóng danh sách
    GiaiPhongDanhSach(pHead);
    return 0;
}