#include <iostream>
#include <string>
using namespace std;

struct tagNode {
	string MaSP, TenSP, NhaSanXuat, NoiSanXuat;
	int Ngay, Thang, Nam, SoNgaySuDung, SL;
	float DonGia;
	tagNode* pNext;
};

struct Stack {
	tagNode* pTop;
};

void CreateStack(Stack& s) {
	s.pTop = NULL;
}

tagNode* CreateNode(const string ma, const string ten, const int sl, const int ngay, const int thang, const int nam, const int ngaysudung, const string nsx, const string nhasx, const float gia) {
	tagNode* p = new tagNode;
	p -> MaSP = ma;
	p -> TenSP = ten;
	p -> DonGia = gia;
	p -> SL = sl;
	p -> Ngay = ngay;
	p -> Thang = thang;
	p -> Nam = nam;
	p -> NhaSanXuat = nhasx;
	p -> NoiSanXuat = nsx;
	p -> pNext = NULL;
	return p;
}

void Push(Stack& s, tagNode *node) {
	if (s.pTop == NULL) {
		s.pTop = node;
	}
	else {
		node->pNext = s.pTop;
		s.pTop = node;
	}
}

void nhapThongTinSP(Stack &s) {
	int n, sl, ngay, thang, nam, ngaysudung;
	string ma, ten, nhasx, nsx;
	float giatien;
	cout << "Hãy nhập số lượng SP bạn muốn nhập: "; cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Hãy nhập sản phẩm thứ " << i + 1 << ": " << endl;
		cout << "Hãy nhập Mã SP:";
		cin.ignore();
		getline(cin, ma);
		cout << "Hãy nhập Tên SP:"; 
		getline(cin, ten);
		cout << "Hãy nhập Giá SP:"; 
		cin >> giatien; 
		cout << "Hãy nhập số lượng sp:";
		cin >> sl;
		cout << "Hãy nhập ngày sx: "; cin >> ngay;
		cout << "Hãy nhập tháng sx: "; cin >> thang;
		cout << "Hãy nhập năm sx: "; cin >> nam;
		cout << "Hãy nhập số ngày đã sử dụng: "; cin >> ngaysudung;
		cout << "Hãy nhập nhà sx: "; cin.ignore();
		getline(cin, nhasx);
		cout << "Hãy nhập nơi sx: ";
		getline(cin, nsx);

		tagNode* node = CreateNode(ma, ten, sl, ngay, thang, nam, ngaysudung, nsx, nhasx, giatien);
		Push(s, node);
	}
}

void xuatThongTinSP(Stack s) {
	if (s.pTop != NULL) {
		cout << "Danh sách các sản phẩm đang có: " << endl;
		int i = 1;
		tagNode* node = s.pTop;
		while (node != NULL) {
			cout << i << ". Mã SP: " << node -> MaSP << " | Tên SP: " << node -> TenSP << " | Giá Tiền: " << node -> DonGia
				<< " | Số Lượng: " << node -> SL << " | Ngày SX: " << node -> Ngay << "/" << node -> Thang << "/" << node->Nam
				<< " | Số ngày đã sử dụng: " << node -> SoNgaySuDung << " | Nhà SX: " << node -> NhaSanXuat << " | Nơi SX: " << node -> NoiSanXuat << endl;
			node = node -> pNext;
			i++;
		}
	}
	else {
		cout << "Bạn chưa nhập thông tin vào! Xin hãy thử lại." << endl;
	}
}

void FreeStack(Stack& s) {
	tagNode* node = s.pTop;
	bool daGiaiPhong = false;
	while (s.pTop != NULL) {
		tagNode* nextNode = node->pNext;
		delete node;
		node = nextNode;
		daGiaiPhong = true;
	} 
	if (daGiaiPhong = true) {
		cout << "Giải phóng bộ nhớ thành công!" << endl;
	}
	else {
		cout << "Giải phóng bộ nhớ không thành công." << endl;
	}
}

void Menu() {
	cout << "========================================" << endl;
	cout << "1. Nhập thông tin cho SP." << endl;
	cout << "2. Xuất thông tin các SP." << endl;
	cout << "3. Giải phóng bộ nhớ." << endl;
	cout << "4. Thoát khỏi Menu." << endl;
	cout << "========================================" << endl;
}

int main() {
	Stack stack;
	CreateStack(stack);
	int choices;
	do {
		Menu();
		cout << "Hãy nhập lựa chọn của bạn: "; cin >> choices;
		switch (choices) {
			case 1: 
				nhapThongTinSP(stack);
				break;
			case 2:
				xuatThongTinSP(stack);
				break;
			case 3:
				FreeStack(stack);
				break;
			case 4:
				cout << "Thoát khỏi menu thành công!." << endl;
				break;
			default:
				cout << "Bạn nhập sai rồi! Vui lòng nhâp lại." << endl;
				break;
		}
	} while (choices != 4);
	return 0;
}
