#include <vector>
#include <string>
#include <iostream>
using namespace std;

class SanPham{
private:
	vector<string> MaSP;
	vector<string> TenSP;
	vector<float> DonGia;
	vector<string> NSX;
	vector<int> Ngay;
	vector<int> Thang;
	vector<int> Nam;
	vector<int> SoNgaySuDung;
	vector<string> NoiSanXuat;
public:
	void NhapSP(){
		string ma, ten, nsx, noisx;
		int ngay, thang, nam, ngaysudung, n;
		float price;
		cout << "Hay nhap so san pham can nhap: "; cin >> n;
		for (int i = 0; i < n; i++){
			if (MaSP.size() > 40) {
				cout << "Da vuot qua gioi han cho phep!" << endl;
			} else {
				cout << "Hay nhap ma san pham " << i + 1 << ": ";
				cin.ignore();
				getline(cin, ma);
				MaSP.push_back(ma);
				cout << "Hay nhap ten SP " << i + 1 << ": "; 
				getline(cin, ten);
				TenSP.push_back(ten);
				cout << "Hay nhap don gia " << i + 1 << ": "; 
				cin >> price;
				DonGia.push_back(price);
				cout << "Hay nhap ngay sx " << i + 1 << ": "; 
				cin >> ngay;
				Ngay.push_back(ngay);
				cout << "Hay nhap thang sx " << i + 1 << ": "; 
				cin >> thang;
				Thang.push_back(thang);
				cout << "Hay nhap nam sx " << i + 1 << ": "; 
				cin >> nam;
				Nam.push_back(nam);
				cout << "Hay nhap so ngay su dung " << i + 1 << ": "; 
				cin >> ngaysudung;
				SoNgaySuDung.push_back(ngaysudung);
				cout << "Hay nhap noi san xuat san pham " << i + 1 << ": "; 
				cin >> noisx;
				NoiSanXuat.push_back(noisx);	
			}
		}
	}
	
	void XuatDanhSach(){
		for (int i = 0; i < MaSP.size(); i++){
			cout << "Ma SP: " << MaSP[i] << "| Ten SP: " << TenSP[i] 
			<< "| Gia tien: " << DonGia[i] << "| Ngay/Thang/Nam: " << Ngay[i] 
			<< "/" << Thang[i] << "/" << Nam[i] << "| So Ngay Su Dung: " << SoNgaySuDung[i] 
			<< "| Noi San Xuat: " << NoiSanXuat[i] << endl;
		}
	}
	
	void SanPhamDuoi30(){
		bool DaTimThay = false;
		for (int i = 0; MaSP.size(); i++){
			if (SoNgaySuDung[i] < 30){
				DaTimThay= true;
				cout << "Ma SP: " << MaSP[i] << "| Ten SP: " << TenSP[i] 
				<< "| Gia tien: " << DonGia[i] << "| Ngay/Thang/Nam: " << Ngay[i] 
				<< "/" << Thang[i] << "/" << Nam[i] << "| So Ngay Su Dung: " << SoNgaySuDung[i] 
				<< "| Noi San Xuat: " << NoiSanXuat[i] << endl;
			}
		}
		if (!DaTimThay)
			cout << "Khong co san pham nao duoi 30 ngay trong danh sach." << endl;
	}
	
	void timKiemThongTinKhiBietNoiSX(){
		bool daTimThay = false;
		string x;
		cout << "Hay nhap noi san xuat can tim: ";
		cin.ignore();
		getline(cin, x);
		for (int i =0; i <= MaSP.size(); i++){
			if (NoiSanXuat[i] == x){
				cout << "Ma SP: " << MaSP[i] << "| Ten SP: " << TenSP[i] 
				<< "| Gia tien: " << DonGia[i] << "| Ngay/Thang/Nam: " << Ngay[i] 
				<< "/" << Thang[i] << "/" << Nam[i] << "| So Ngay Su Dung: " << SoNgaySuDung[i] 
				<< "| Noi San Xuat: " << NoiSanXuat[i] << endl;
				daTimThay = true;
			}
		}
		if (!daTimThay) {
			cout << "Khong tim thay thong tin san pham nay." << endl;
		}
	}
	
	void TimKiemSPKhiBietNamSX(){
		bool daTimThay = false;
		int x;
		cout << "Hay nhap nam san xuat can tim: ";
		cin.ignore();
		cin >> x;
		for (int i =0; i <= MaSP.size(); i++){
			if (Nam[i] == x){
				cout << "Ma SP: " << MaSP[i] << "| Ten SP: " << TenSP[i] 
				<< "| Gia tien: " << DonGia[i] << "| Ngay/Thang/Nam: " << Ngay[i] 
				<< "/" << Thang[i] << "/" << Nam[i] << "| So Ngay Su Dung: " << SoNgaySuDung[i] 
				<< "| Noi San Xuat: " << NoiSanXuat[i] << endl;
				daTimThay = true;
			}
		}
		if (!daTimThay) {
			cout << "Khong tim thay thong tin san pham nay." << endl;
		}
	}
	
	void CacSPGiaTren50000 (){
		bool daTimThay = false;
		for (int i =0; i <= MaSP.size(); i++){
			if (DonGia[i] > 50000){
				cout << "Ma SP: " << MaSP[i] << "| Ten SP: " << TenSP[i] 
				<< "| Gia tien: " << DonGia[i] << "| Ngay/Thang/Nam: " << Ngay[i] 
				<< "/" << Thang[i] << "/" << Nam[i] << "| So Ngay Su Dung: " << SoNgaySuDung[i] 
				<< "| Noi San Xuat: " << NoiSanXuat[i] << endl;
				daTimThay = true;
			}
		}
		if (!daTimThay) {
			cout << "Khong co san pham nao tren 50000." << endl;
		}
	}
};

void menu(){
	cout << "=============================" << endl;
	cout << "1. Nhap danh sach cac san pham." << endl;
	cout << "2. Xuat danh sach cac san pham." << endl;
	cout << "3. Danh sach cac san pham co gian su dung duoi 30 days." << endl;
	cout << "4. Tim kiem sp khi biet noi san xuat." << endl;
	cout << "5. Tim kiem sp khi biet nam san xuat. " << endl;
	cout << "6. In ra cac san pham co gia tren 50000." << endl;
	cout << "7. Thoat khoi menu!." << endl;
	cout << "=============================" << endl;
}


int main(){
	SanPham SP;
	int choices;
	do {
		menu();
		cout << "Hay nhap lua chon cua ban: "; cin >> choices;
		switch (choices){
			case 1:
				SP.NhapSP();
				break;
			case 2: 
				SP.XuatDanhSach();
				break;
			case 3: 
				SP.SanPhamDuoi30();
				break;
			case 4:
				SP.timKiemThongTinKhiBietNoiSX();
				break;
			case 5: 
				SP.TimKiemSPKhiBietNamSX();
				break;
			case 6:
				SP.CacSPGiaTren50000();
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