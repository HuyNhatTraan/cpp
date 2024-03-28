#include <vector>
#include <string>
#include <iostream>
using namespace std;

class MonHoc{
private:
	vector<string> MaMH;
	vector<string> TenMH;
	vector<int> STC;
public:
	void NhapMonHoc (){
		string ma, name;
		int tc, n;
		cout << "Hay nhap so mon hoc: "; cin >> n;
		for (int i = 0; i < n; i++){
			if (MaMH.size() > 20){
				cout << "Da vuot qua so mon hoc cho phep!" << endl;
			} else{
				cout << "Hay nhap ma mon hoc thu " << i + 1 << ": ";
				cin.ignore();
				getline(cin, ma);
				MaMH.push_back(ma);
				cout << "Hay nhap ten mon hoc thu " << i + 1 << ": "; 
				getline(cin, name);
				TenMH.push_back(name);
				cout << "Hay nhap so tin chi hoc thu " << i + 1 << ": "; 
				cin >> tc;
				STC.push_back(tc);
			}
		}
	}
	
	void XuatDanhSach (){
		cout << "=============================" << endl;
		for (int i = 0; i < MaMH.size(); i++){
			cout << "Ma MH: " << MaMH[i] << "| Ten MH: " << TenMH[i] << "| So Tin Chi: " << STC[i] << endl;
		}
		cout << "=============================" << endl;
	}
	
	void XuatDanhSachTren2TC (){
		bool tren2tc = false;
		cout << "=============================" << endl;
		for (int i = 0; i < MaMH.size(); i++){
			if (STC[i] > 2){
			tren2tc = true;
			cout << "Ma MH: " << MaMH[i] << "| Ten MH: " << TenMH[i] << "| So Tin Chi: " << STC[i] << endl;
			}
		}
		if (!tren2tc)
		cout << "=============================" << endl;
			cout << "Khong co mon tren 2 tc" << endl;
	}
	
	void TongSoTinChi (){
		int Sum = 0;
		for (int i = 0; i < MaMH.size(); i++){
			Sum += STC[i];
		}
		cout << "Tong so tin chi la: " << Sum << endl;
	}
	
	void timKiemThongTin (){
		bool daTimThay = false;
		string x;
		cout << "Hay nhap ma so mon hoc can tim: ";
		cin.ignore();
		getline(cin, x);
		for (int i =0; i <= MaMH.size(); i++){
			if (MaMH[i] == x){
				cout << "Da tim thay thong tin mon hoc: " << x << endl;
				daTimThay = true;
				break;
			}
		}
		if (!daTimThay) {
			cout << "Khong tim thay thong tin mon hoc nay" << endl;
		}
	}
};

void menu(){
	cout << "=============================" << endl;
	cout << "1. Nhap danh sach mon hoc." << endl;
	cout << "2. Xuat danh sach mon hoc." << endl;
	cout << "3. Xuat danh sach mon hoc tren 2 tin chi." << endl;
	cout << "4. Tinh tong so tin chi co trong danh sach." << endl;
	cout << "5. Tim kiem thong tin mon hoc." << endl;
	cout << "6. Thoat khoi menu!." << endl;
	cout << "=============================" << endl;
}

int main(){
	MonHoc MH;
	int choices;
	do {
		menu();
		cout << "Hay nhap lua chon cua ban: "; cin >> choices;
		switch (choices){
			case 1:
				MH.NhapMonHoc();
				break;
			case 2: 
				MH.XuatDanhSach();
				break;
			case 3:
				MH.XuatDanhSachTren2TC();
				break;
			case 4: 
				MH.TongSoTinChi();
				break;
			case 5:
				MH.timKiemThongTin();
				break;
			case 6: 
				cout << "Thoat khoi menu!." << endl;
				break;
			default: 
				cout << "Nhap sai roi ban ei" << endl;
				break; 
		}
	} while(choices != 6);
	return 0;
}