#include <vector>
#include <string>
#include <iostream>
using namespace std;

class ThuVien{
private:
	vector<string> MaSach;
	vector<string> TenSach;
	vector<string> TenTG;
	vector<string> NXB;
	vector<int> NamXuatBan;
	vector<int> SL;
	vector<float> DonGia;
public:
	void NhapSach(){
		string masach, tensach, tg, nxb;
		int namxb, sl, n;
		float price;
		cout << "Hay nhap so sach can nhap: "; cin >> n;
		for (int i = 0; i < n; i++){
			if (MaSach.size() > 30) {
				cout << "Vuot qua gioi han cho phep!" << endl;
			} else {
				cout << "Hay nhap ma sach thu " << i + 1 << ": ";
				cin.ignore();
				getline(cin, masach);
				MaSach.push_back(masach);
				cout << "Hay nhap ten sach thu " << i + 1 << ": "; 
				getline(cin, tensach);
				TenSach.push_back(tensach);
				cout << "Hay nhap ten tac gia " << i + 1 << ": "; 
				getline(cin, tg);
				TenTG.push_back(tg);
				cout << "Hay nhap ten nha xuat ban " << i + 1 << ": "; 
				getline(cin, nxb);
				NXB.push_back(nxb);
				cout << "Hay nhap nam xuat ban sach thu " << i + 1 << ": "; 
				cin >> namxb;
				NamXuatBan.push_back(namxb);
				cout << "Hay nhap so luong sach thu " << i + 1 << ": "; 
				cin >> sl;
				SL.push_back(sl);
				cout << "Hay nhap gia tien sach thu " << i + 1 << ": "; 
				cin >> price;
				DonGia.push_back(price);
			}
		}
	}
	
	void XuatDanhSach(){
		for (int i = 0; i < MaSach.size(); i++){
			cout << "Ma Sach: " << MaSach[i] << "| Ten Sach: " << TenSach[i] 
			<< "| Tac Gia: " << TenTG[i] << "| Nha Xuat Ban: " << NXB[i] 
			<< "| Nam Xuat Ban: " << NamXuatBan[i] 
			<< "| So Luong: " << SL[i] 
			<< "| Don Gia: " << DonGia[i] << " VND "<< endl;
		}
	}
	
	void TongTien(){
		int Sum = 0;
		for (int i = 0; i < MaSach.size(); i++){
			Sum += DonGia[i];
		}
		cout << "Tong tien phai bo ra la: " << Sum << " VND" << endl;
	}
	
	void SachDHQG(){
		bool daTimThay = false;
		for (int i =0; i <= MaSach.size(); i++){
			string target = "Dai Hoc Quoc Gia";
			if (NXB[i] == target){
				cout << "Da tim thay thong tin sach: " << endl;
				cout << "Ma Sach: " << MaSach[i] << "| Ten Sach: " << TenSach[i] 
				<< "| Tac Gia: " << TenTG[i] << "| Nha Xuat Ban: " << NXB[i] 
				<< "| Nam Xuat Ban: " << NamXuatBan[i] 
				<< "| So Luong: " << SL[i] 
				<< "| Don Gia: " << DonGia[i] << " VND "<< endl;
				daTimThay = true;
				break;
			}
		}
		if (!daTimThay) {
			cout << "Khong tim thay thong tin sach nay" << endl;
		}
	}
	
	void SachNam2016(){
		bool daTimThay = false;
		for (int i =0; i <= MaSach.size(); i++){
			if (NamXuatBan[i] == 2016){
				cout << "Da tim thay thong tin sach: " << endl;
				cout << "Ma Sach: " << MaSach[i] << "| Ten Sach: " << TenSach[i] 
				<< "| Tac Gia: " << TenTG[i] << "| Nha Xuat Ban: " << NXB[i] 
				<< "| Nam Xuat Ban: " << NamXuatBan[i] 
				<< "| So Luong: " << SL[i] 
				<< "| Don Gia: " << DonGia[i] << " VND "<< endl;
				daTimThay = true;
				break;
			}
		}
		if (!daTimThay) {
			cout << "Khong tim thay thong tin sach nay" << endl;
		}
	}
	void timKiemThongTin(){
		bool daTimThay = false;
		string x;
		cout << "Hay nhap ten tac gia can tim: ";
		cin.ignore();
		getline(cin, x);
		for (int i =0; i <= MaSach.size(); i++){
			if (TenTG[i] == x){
				cout << "Da tim thay thong tin sach: " << endl;
				cout << "Ma Sach: " << MaSach[i] << "| Ten Sach: " << TenSach[i] 
				<< "| Tac Gia: " << TenTG[i] << "| Nha Xuat Ban: " << NXB[i] 
				<< "| Nam Xuat Ban: " << NamXuatBan[i] 
				<< "| So Luong: " << SL[i] 
				<< "| Don Gia: " << DonGia[i] << " VND "<< endl;
				daTimThay = true;
				break;
			}
		}
		if (!daTimThay) {
			cout << "Khong tim thay thong tin sach nay" << endl;
		}
	}
};

void menu(){
	cout << "=============================" << endl;
	cout << "1. Nhap danh sach cac loai sach." << endl;
	cout << "2. Xuat danh sach cac loai sach." << endl;
	cout << "3. Tong tien de mua cac loai sach." << endl;
	cout << "4. Cac sach thuoc NXB Dai Hoc Quoc Gia." << endl;
	cout << "5. Cac sach in trong nam 2016. " << endl;
	cout << "6. Tim kiem thong tin mon hoc." << endl;
	cout << "7. Thoat khoi menu!." << endl;
	cout << "=============================" << endl;
}


int main(){
	ThuVien TV;
	int choices;
	do {
		menu();
		cout << "Hay nhap lua chon cua ban: "; cin >> choices;
		switch (choices){
			case 1:
				TV.NhapSach();
				break;
			case 2: 
				TV.XuatDanhSach();
				break;
			case 3: 
				TV.TongTien();
				break;
			case 4:
				TV.SachDHQG();
				break;
			case 5: 
				TV.SachNam2016();
				break;
			case 6:
				TV.timKiemThongTin();
				break;
			case 7: 
				cout << "Thoat khoi menu!." << endl;
				break;
			default: 
				cout << "Nhap sai roi ban ei" << endl;
				break; 
		}
	} while(choices != 7);
	return 0;
}