#include <iostream>
#include <string>
using namespace std;

struct tagNode {
    string MaSach;
    string TenSach;
    float DonGia;
    int SL;
    string NXB;
    string TenTG;
    tagNode* pNext;
};

struct tagList {
    tagNode* pHead;
    tagNode* pTail;
};

void CreateList(tagList& l) {
    l.pHead = nullptr;
    l.pTail = nullptr;
}

tagNode* CreateNode(const string& ma, const string& ten, float gia, int sl, const string& nxb, const string& tacgia) {
    tagNode* p = new tagNode;
    p -> MaSach = ma;
    p -> TenSach = ten;
    p -> DonGia = gia;
    p -> SL = sl;
    p -> NXB = nxb;
    p -> TenTG = tacgia;
    p -> pNext = nullptr;
    return p;
}

void AddHead(tagList& l, tagNode* node) {
    if (l.pHead == nullptr) {
        l.pHead = node;
        l.pTail = node;
    } else {
        node -> pNext = l.pHead;
        l.pHead = node;
    }
}

void AddTail(tagList& l, tagNode* node) {
    if (l.pHead == nullptr) {
        l.pHead = node;
        l.pTail = node;
    } else {
        l.pTail -> pNext = node;
        l.pTail = node;
    }
}

void DisplayBooks(tagList& l) {
    cout << "Danh sách các đầu sách đang có: " << endl;
    tagNode* temp = l.pHead;
    int i = 1;
    while (temp != nullptr) {
        cout << i << ". Mã sách: " << temp -> MaSach << " | Tên sách: " << temp -> TenSach
             << " | Giá: " << temp -> DonGia << " | Số lượng: " << temp -> SL << " | Tác giả: " << temp -> TenTG << " | NXB: " << temp -> NXB << endl;
        temp = temp -> pNext;
        i++;
    }
}

void DisplayBooksByAuthor(tagList& l, const string& authorName) {
    cout << "Đầu sách của tác giả " << authorName << ":" << endl;
    tagNode* temp = l.pHead;
    bool found = false;
    int i = 1;
    while (temp != nullptr) {
        if (temp -> TenTG == authorName) {
            found = true;
            cout << i << ". Mã sách: " << temp -> MaSach << " | Tên sách: " << temp -> TenSach
                 << " | Giá: " << temp -> DonGia << " | Số lượng: " << temp -> SL << " | NXB: " << temp -> NXB << endl;
            i++;
        }
        temp = temp->pNext;
    }
    if (!found) {
        cout << "Không tìm thấy đầu sách của tác giả " << authorName << endl;
    }
}

void SortBooksByQuantity(tagList& l) {
    if (l.pHead == nullptr || l.pHead -> pNext == nullptr) {
        return;
    }
    bool swapped;
    tagNode *ptr1, *lptr = nullptr;
    do {
        swapped = false;
        ptr1 = l.pHead;
        while (ptr1 -> pNext != lptr) {
            if (ptr1 -> SL > ptr1 -> pNext -> SL) {
                swap(ptr1, ptr1 -> pNext);
                swapped = true;
            }
            ptr1 = ptr1 -> pNext;
        }
        lptr = ptr1;
    } while (swapped);
}

void SortBooksByPriceDescending(tagList& l) {
    if (l.pHead == nullptr || l.pHead -> pNext == nullptr) {
        return;
    }
    bool swapped;
    tagNode *ptr1, *lptr = nullptr;
    do {
        swapped = false;
        ptr1 = l.pHead;
        while (ptr1 -> pNext != lptr) {
            if (ptr1 -> DonGia < ptr1 -> pNext -> DonGia) {
                swap(ptr1, ptr1 -> pNext);
                swapped = true;
            }
            ptr1 = ptr1 -> pNext;
        }
        lptr = ptr1;
    } while (swapped);
}

void CalculateTotalPriceByPublisher(tagList& l, const string& publisherName) {
    int total = 0;
    tagNode* temp = l.pHead;
    while (temp != nullptr) {
        if (temp -> NXB == publisherName) {
            total += temp -> DonGia * temp -> SL;
        }
        temp = temp -> pNext;
    }
    cout << "Tổng số tiền nhà xuất bản " << publisherName << " xuất bản là: " << total << endl;
}

void Menu() {
    cout << "================= Menu =====================" << endl;
    cout << "1. Nhập danh sách các đầu sách (Tối đa 30)." << endl;
    cout << "2. Xuất danh sách các đầu sách." << endl;
    cout << "3. Xuất danh sách các đầu sách khi biết tên tác giả." << endl;
    cout << "4. Sắp xếp các đầu sách tăng dần theo số lượng." << endl;
    cout << "5. Sắp xếp danh sách đầu sách giảm dần theo đơn giá." << endl;
    cout << "6. Tính tổng giá trị của các đầu sách khi biết tên nhà xuất bản." << endl;
    cout << "7. Thoát khỏi menu!" << endl;
    cout << "============================================" << endl;
}

int main() {
    tagList library;
    CreateList(library);
    int choice;
    do {
        Menu();
        cout << "Hãy nhập lựa chọn của bạn: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1: {
                string ma, ten, tacgia, nxb;
                float gia;
                int sl;
                cout << "Hãy nhập mã sách: ";
                getline(cin, ma);
                cout << "Hãy nhập tên sách: ";
                getline(cin, ten);
                cout << "Hãy nhập đơn giá: ";
                cin >> gia;
                cout << "Hãy nhập số lượng: ";
                cin >> sl;
                cin.ignore(); // consume newline
                cout << "Hãy nhập tên tác giả: ";
                getline(cin, tacgia);
                cout << "Hãy nhập tên nhà xuất bản: ";
                getline(cin, nxb);
                tagNode* newNode = CreateNode(ma, ten, gia, sl, nxb, tacgia);
                AddTail(library, newNode);
                break;
			}
            case 2:
                DisplayBooks(library);
                break;
            case 3: {
                string authorName;
                cout << "Hãy nhập tên tác giả bạn muốn tìm: ";
                getline(cin, authorName);
                DisplayBooksByAuthor(library, authorName);
                break;
            }
            case 4:
                SortBooksByQuantity(library);
                cout << "Đã sắp xếp sách theo số lượng tăng dần." << endl;
                break;
            case 5:
                SortBooksByPriceDescending(library);
                cout << "Đã sắp xếp sách theo giá giảm dần." << endl;
                break;
            case 6: {
                string publisherName;
                cout << "Hãy nhập tên nhà xuất bản: ";
                getline(cin, publisherName);
                CalculateTotalPriceByPublisher(library, publisherName);
                break;
            }
            case 7:
                cout << "Thoát khỏi Menu thành công." << endl;
                break;
            default:
                cout << "Nhập sai rồi, vui lòng nhập lại." << endl;
                break;
        }
    } while (choice != 7);

    return 0;
}
